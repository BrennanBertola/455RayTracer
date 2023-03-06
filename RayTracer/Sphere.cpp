#include "Sphere.h"

pair<bool, vec3> Sphere::checkForIntersect(Ray r) {
    vec3 oc = r.getOri() - center;
    float a = dot(r.getDir(), r.getDir());
    float b = 2.0 * dot(oc, r.getDir());
    float c = dot(oc, oc) - radius*radius;
    float d = b*b - 4*a*c;

    if (d < 0) {
        return {false, vec3()};
    }

    float t = 0;
    float t0 = (-b - sqrt(d)) / (2.0 * a);
    if (t0 <= 0) {
        float t1 = (-b + sqrt(d)) / (2.0 * a);
        if (t1 <= 0) {
            return {false, vec3()};
        }
        t = t1;
    }
    else {
        t = t0;
    }
    return {true, r.getOri() + r.getDir()*t};
}

Sphere::Sphere(const vec3 &center, float radius, float kd, float ks, float ka, const vec3 &od, const vec3 &os,
               float kgls, float refl) : Object(ks, kd, ka, od, os, kgls, refl), radius(radius), center(center) {}


