#include "Sphere.h"

IResult Sphere::checkForIntersect(Ray r) {
    vec3 oc = r.getOri() - center;
    float a = dot(r.getDir(), r.getDir());
    float b = 2.0 * dot(oc, r.getDir());
    float c = dot(oc, oc) - radius*radius;
    float d = b*b - 4*a*c;

    if (d < 0) {
        return IResult(false);
    }

    float t = 0;
    float t0 = (-b - sqrt(d)) / 2;
    if (t0 <= 0) {
        float t1 = (-b + sqrt(d)) / 2;
        if (t1 <= 0) {
            return IResult(false);
        }
        t = t1;
    }
    else {
        t = t0;
    }
    return IResult(true, r.getOri() + r.getDir()*t, Od);





}

