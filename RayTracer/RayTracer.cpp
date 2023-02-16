#include "RayTracer.h"
#include <fstream>
using namespace std;

void write_color(std::ostream &out, vec3 pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

bool hit_sphere(const vec3& center, double radius, const Ray& r) {
    vec3 oc = r.getOri() - center;
    auto a = dot(r.getDir(), r.getDir());
    auto b = 2.0 * dot(oc, r.getDir());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}

vec3 ray_color(const Ray& r, Scene* s) {
    if (s->getObjs()[0]->checkForIntersect(r).found)
        return s->getObjs()[0]->getOd();
    return s->getBackColor();
}

void RayTracer::traceScene(int imgW, int imgH, Scene* scene) {
    ofstream os;
    os.open("image.ppm");
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
            vec3 pixel_color = ray_color(r, scene);
            write_color(os, pixel_color);
        }
    }
    
    os.close();
    std::cerr << "\nDone.\n";
}
