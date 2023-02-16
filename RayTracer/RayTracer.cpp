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
    vec3 uS = vec3(1,0,0);
    vec3 vS = vec3(0,1,0);
    auto horizontal = vec3(cam.max.first*2, 0, 0);
    auto vertical = vec3(0, cam.max.second*2, 0);
    auto lower_left_corner = cam.getLookFrom() - horizontal/2 - vertical/2 - vec3(0, 0, 0);

    os << "P3\n" << imgW << " " << imgH << "\n255\n";

    for (int j = imgH-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imgW; ++i) {
            float u = double(i) * ((cam.max.first - cam.min.first)/(imgW)) + cam.min.first;
            float v = double(j) * ((cam.max.second - cam.min.second)/(imgH)) + cam.min.second;
            Ray r(cam.getLookFrom(),  u*uS + v*vS + cam.getLookAt() - cam.getLookFrom());

//            auto u = double(i) / (imgW-1);
//            auto v = double(j) / (imgH-1);
//            Ray r(cam.getLookFrom(), lower_left_corner + u*horizontal + v*vertical - cam.getLookFrom());

            vec3 pixel_color = ray_color(r, scene);
            write_color(os, pixel_color);
        }
    }
    
    os.close();
    std::cerr << "\nDone.\n";
}
