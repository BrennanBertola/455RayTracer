#include "RayTracer.h"
#include <fstream>
#include <limits>
using namespace std;

void writeColor(std::ostream &out, vec3 pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

bool inShadow(vec3 ori, vec3 dir, vec3 norm, Scene* s) {
    ori += norm * 0.0001; //Offset point from surface
    Ray shadow(ori, dir);

    vector<Object*> objs = s->getObjs();
    bool noInter = true;

    for (Object* obj : objs) {
        pair<bool, vec3> result = obj->checkForIntersect(shadow);
        if (result.first) {
            noInter = false;
        }
    }

    return !noInter;
}

vec3 RayTracer::calcColor(Object* obj, vec3 point, Scene* s, Ray r) {
    vec3 norm = unit_vector(obj->getNorm(point));
    if (dot(norm, r.getDir()) > 0) {
        norm *= -1;
    }

    vec3 lNorm = unit_vector(s->getLight().getDirection());

    if (inShadow(point, lNorm, norm, s) && obj->getRefl() == 0) {
        return vec3(0,0,0);
    }

    vec3 vNorm = unit_vector(r.getDir() * -1);
    vec3 rNorm = 2 * dot(lNorm, norm) * norm - lNorm;

    vec3 diffuse = obj->getKd() * s->getLight().getColor() * obj->getOd() * max(0.0, dot(norm, lNorm));
    vec3 ambient = s->getAmbLight() * obj->getKa() * obj->getOd();
    vec3 specular = obj->getKs() * s->getLight().getColor() * obj->getOs() * pow(max(0.0, dot(vNorm, rNorm)), obj->getKgls());
    vec3 result = diffuse + ambient + specular;
    result[0] = max(0.0, min(result.x(), 1.0));
    result[1] = max(0.0, min(result.y(), 1.0));
    result[2] = max(0.0, min(result.z(), 1.0));

    if (obj->getRefl() > 0.0 && rayCount <= maxRays) {
        rayCount++;
        vec3 reflectDir = 2 * dot(vNorm, norm)*norm - vNorm;
        vec3 reflectOri = point + (norm * .001);
        Ray reflectRay(reflectOri, reflectDir);
        result = (1.0 - obj->getRefl()) * result + obj->getRefl() * rayColor(reflectRay, s);
    }

    return result;
}

vec3 RayTracer::rayColor(const Ray& r, Scene* s) {
    vector<Object*> objs = s->getObjs();
    Object* min;
    vec3 minPoint;
    float minD = numeric_limits<float>::infinity();
    bool noInter = true;

    for (Object* obj : objs) {
        pair<bool, vec3> result = obj->checkForIntersect(r);
        if (result.first) {
            float dist = result.second.distance(s->getCam().getLookFrom());
            if (dist < minD) {
                noInter = false;
                min = obj;
                minPoint = result.second;
                minD = dist;
            }
        }
    }

    if (noInter) {
        return s->getBackColor();
    }
    return calcColor(min, minPoint, s, r);
}

void RayTracer::traceScene(int imgW, int imgH, Scene* scene) {
    ofstream os;
    string fileName = "image" + scene->getName() + ".ppm";
    os.open(fileName);
    if (!os.is_open()) {
        cerr << "file failed to open" << endl;
        exit(1);
    }

    Camera cam = scene->getCam();
    os << "P3\n" << imgW << " " << imgH << "\n255\n";

    for (int j = imgH-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imgW; ++i) {
            float u = double(i) * ((cam.max.first - cam.min.first)/(imgW)) + cam.min.first;
            float v = double(j) * ((cam.max.second - cam.min.second)/(imgH)) + cam.min.second;
            Ray r(cam.getLookFrom(),  u*vec3(1,0,0) + v*vec3(0,1,0) + cam.getLookAt() - cam.getLookFrom());
            rayCount = 1;
            vec3 pixel_color = rayColor(r, scene);
            writeColor(os, pixel_color);
        }
    }
    
    os.close();
    std::cerr << "\nDone.\n";
}
