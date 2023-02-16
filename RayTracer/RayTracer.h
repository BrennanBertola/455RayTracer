#ifndef RAYTRACER_RAYTRACER_H
#define RAYTRACER_RAYTRACER_H
#include "Scene.h"


//more for project 6
class RayTracer {
private:
    //tree
public:
    RayTracer() {};
    void traceScene(int imgW, int imgH, Scene* scene);

};


#endif //RAYTRACER_RAYTRACER_H
