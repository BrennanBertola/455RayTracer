#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "vec3.h"

class Camera{
private:
    vec3 lookAt;
    vec3 lookFrom;
    vec3 lookUp;
    float fov;
public:
    Camera() {}
    Camera(const vec3 &lookAt, const vec3 &lookFrom, const vec3 &lookUp, float fov) : lookAt(lookAt),
                                                                                      lookFrom(lookFrom),
                                                                                      lookUp(lookUp), fov(fov) {}

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
