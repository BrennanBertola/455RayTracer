#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "vec3.h"
using namespace std;

class  Object {
protected:
    vec3 Ks;
    vec3 Kd;
    vec3 Ka;
    vec3 Od;
    vec3 Os;
    float kgls;
public:
    Object() {}

    Object(const vec3 &ks, const vec3 &kd, const vec3 &ka, const vec3 &od, const vec3 &os, float kgls) : Ks(ks), Kd(kd),
                                                                                                         Ka(ka), Od(od),
                                                                                                         Os(os),
                                                                                                         kgls(kgls) {}


    const vec3 &getKs() const {
        return Ks;
    }

    const vec3 &getKd() const {
        return Kd;
    }

    const vec3 &getKa() const {
        return Ka;
    }

    const vec3 &getOd() const {
        return Od;
    }

    const vec3 &getOs() const {
        return Os;
    }

    float getkgls() const {
        return kgls;
    }
};
#endif //RAYTRACER_OBJECT_H
