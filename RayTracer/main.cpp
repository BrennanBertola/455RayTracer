#include <iostream>
#include "RayTracer.h"

//void write_color(std::ostream &out, vec3 pixel_color) {
//    // Write the translated [0,255] value of each color component.
//    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
//        << static_cast<int>(255.999 * pixel_color.y()) << ' '
//        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
//}
//
//bool hit_sphere(const vec3& center, double radius, const Ray& r) {
//    vec3 oc = r.getOri() - center;
//    auto a = dot(r.getDir(), r.getDir());
//    auto b = 2.0 * dot(oc, r.getDir());
//    auto c = dot(oc, oc) - radius*radius;
//    auto discriminant = b*b - 4*a*c;
//    return (discriminant > 0);
//}
//
//vec3 ray_color(const Ray& r) {
//    if (hit_sphere(vec3(0,0,0), .5, r))
//        return vec3(1, 0, 0);
//    vec3 unit_direction = unit_vector(r.getDir());
//    auto t = 0.5*(unit_direction.y() + 1.0);
//    return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
//}

int main() {

    // Image
    const int image_width = 500;
    const int image_height = 500;

    Scene* scene = new Scene (vec3(.2,.2,.2), vec3(0,0,0));

    Camera cam (vec3(0,0,0), vec3(0,0,1), vec3(0,1,0), 90);
    scene->setCam(cam);

    Light light(vec3(0,1,0), vec3(1,1,1));
    scene->addLight(light);

    Sphere* sphere = new Sphere (vec3(0,0,0), .4, .7, .2, .1, vec3(1,0,1), vec3(1,1,1), 16.0);
    scene->addObj(sphere);

    RayTracer tracer;
    tracer.traceScene(image_width, image_height, scene);


    // Render

//    auto horizontal = vec3(cam.max.first, 0, 0);
//    auto vertical = vec3(0, cam.max.second, 0);
//
//    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
//
//    for (int j = image_height-1; j >= 0; --j) {
//        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
//        for (int i = 0; i < image_width; ++i) {
//            float u = double(i) * ((cam.max.first - cam.min.first)/(image_width)) + cam.min.first;
//            float v = double(j) * ((cam.max.second - cam.min.second)/(image_width)) + cam.min.second;
//            Ray r(cam.getLookFrom(),  u*horizontal + v*vertical - cam.getLookFrom());
//            vec3 pixel_color = ray_color(r);
//            write_color(std::cout, pixel_color);
//        }
//    }
//
//    std::cerr << "\nDone.\n";
}