#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Object.h"

class Sphere: protected Object {
private:
    float radius;
    vec3 center;
public:
    Sphere(const vec3 &ks, const vec3 &kd, const vec3 &ka, const vec3 &od, const vec3 &os, float kgls, float radius,
           const vec3 &center) : Object(ks, kd, ka, od, os, kgls), radius(radius), center(center) {}


    float getRadius() const {
        return radius;
    }

    const vec3 &getCenter() const {
        return center;
    }

};
#endif //RAYTRACER_SPHERE_H
