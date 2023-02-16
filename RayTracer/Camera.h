#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "vec3.h"
using namespace std;

class Camera{
private:
    vec3 lookAt;
    vec3 lookFrom;
    vec3 lookUp;
    float fov;

public:
    pair<float, float> min;
    pair<float, float> max;

    Camera() {}

    Camera(const vec3 &lookAt, const vec3 &lookFrom, const vec3 &lookUp, float fov)
            : lookAt(lookAt), lookFrom(lookFrom), lookUp(lookUp), fov(fov) {

        float focalLength = sqrt(pow(lookAt.x() - lookFrom.x(), 2) + pow(lookAt.y()-lookFrom.y(),2) +
                            pow(lookAt.z() - lookFrom.z(), 2));
        float length = tan(fov/2) * focalLength;
        max = {length, length};
        length *= -1;
        min = {length, length};
    }


    const vec3 &getLookAt() const {
        return lookAt;
    }

    const vec3 &getLookFrom() const {
        return lookFrom;
    }

    const vec3 &getLookUp() const {
        return lookUp;
    }

    float getFov() const {
        return fov;
    }
};

#endif //RAYTRACER_CAMERA_H
