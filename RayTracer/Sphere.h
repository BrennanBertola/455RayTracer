#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Object.h"

class Sphere: public Object {
private:
    float radius;
    vec3 center;
public:
    Sphere( const vec3 &center, float radius, float kd, float ks, float ka, const vec3 &od, const vec3 &os, float kgls)
            : Object(kd, ks, ka, od, os, kgls), radius(radius), center(center) {}

    IResult checkForIntersect(Ray r);

    float getRadius() const {
        return radius;
    }

    const vec3 &getCenter() const {
        return center;
    }

};
#endif //RAYTRACER_SPHERE_H
