#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H
#include "vec3.h"
class Ray {
private:
    vec3 ori;
    vec3 dir;
public:
    Ray(const vec3 &ori, const vec3 &dir) : ori(ori), dir(dir) {}

    const vec3 &getOri() const {
        return ori;
    }

    const vec3 &getDir() const {
        return dir;
    }

    vec3 at(float t) const {
        return ori + t * dir;
    }

};

#endif //RAYTRACER_RAY_H
