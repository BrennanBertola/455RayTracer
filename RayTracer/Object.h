#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "vec3.h"
#include "Ray.h"
using namespace std;

class IResult {
public:
    bool found;
    vec3 point;
    vec3 color;

    IResult(bool found) : found(found) {}
    IResult(bool found, const vec3 &point, const vec3 &color) : found(found), point(point), color(color) {}
};

class  Object {
protected:
    float Ks;
    float Kd;
    float Ka;
    vec3 Od;
    vec3 Os;
    float kgls;

public:
    Object(float kd, float ks, float ka, const vec3 &od, const vec3 &os, float kgls) : Ks(ks), Kd(kd), Ka(ka),
                                                                                       kgls(kgls), Od(od), Os(os) {}

    virtual ~Object() {}

    virtual IResult checkForIntersect(Ray ray) = 0;


    float getKs() const {
        return Ks;
    }

    float getKd() const {
        return Kd;
    }

    float getKa() const {
        return Ka;
    }

    float getKgls() const {
        return kgls;
    }

    const vec3 &getOd() const {
        return Od;
    }

    const vec3 &getOs() const {
        return Os;
    }
};
#endif //RAYTRACER_OBJECT_H
