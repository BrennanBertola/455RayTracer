#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "vec3.h"
#include "Ray.h"
using namespace std;

class  Object {
protected:
    float Ks;
    float Kd;
    float Ka;
    vec3 Od;
    vec3 Os;
    float kgls;
    float refl;

public:
    Object(float ks, float kd, float ka, const vec3 &od, const vec3 &os, float kgls, float refl) : Ks(ks), Kd(kd),
                                                                                                   Ka(ka), Od(od),
                                                                                                   Os(os), kgls(kgls),
                                                                                                   refl(refl) {}


    virtual ~Object() {}

    virtual pair<bool, vec3> checkForIntersect(Ray ray) = 0;
    virtual vec3 getNorm(vec3 p) = 0;

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

    float getRefl() const {
        return refl;
    }
};
#endif //RAYTRACER_OBJECT_H
