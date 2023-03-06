#ifndef RAYTRACER_RAYTRACER_H
#define RAYTRACER_RAYTRACER_H
#include "Scene.h"


//more for project 6
class RayTracer {
private:
    int rayCount = 0;
    int maxRays = 3;

    vec3 calcColor(Object* obj, vec3 point, Scene* s, Ray r);
    vec3 rayColor(const Ray& r, Scene* s);
public:
    RayTracer() {};
    void traceScene(int imgW, int imgH, Scene* scene);
};


#endif //RAYTRACER_RAYTRACER_H
