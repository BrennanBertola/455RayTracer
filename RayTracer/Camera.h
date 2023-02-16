#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "vec3.h"

class Camera{
private:
    vec3 lookAt;
    vec3 lookFrom;
    vec3 lookUp;
    float focalLength;
    float viewHeight;
    float viewWidth;
public:
    Camera() {}

    Camera(const vec3 &lookAt, const vec3 &lookFrom, const vec3 &lookUp, float focalLength, float viewHeight, float viewWidth)
            : lookAt(lookAt), lookFrom(lookFrom), lookUp(lookUp), focalLength(focalLength), viewHeight(viewHeight),
              viewWidth(viewWidth) {}

    float getViewHeight() const {
        return viewHeight;
    }

    void setViewHeight(float viewHeight) {
        Camera::viewHeight = viewHeight;
    }

    float getViewWidth() const {
        return viewWidth;
    }

    void setViewWidth(float viewWidth) {
        Camera::viewWidth = viewWidth;
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

    float getFocalLength() const {
        return focalLength;
    }
};

#endif //RAYTRACER_CAMERA_H
