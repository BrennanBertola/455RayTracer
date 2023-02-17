#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H
#include "vec3.h"

class Light {
private:
    vec3 dirToLight;
    vec3 lightColor;

public:
    Light() {}
    Light(const vec3 &dirToLight, const vec3 &lightColor) : dirToLight(dirToLight), lightColor(lightColor) {}

    const vec3 &getDirection() const {
        return dirToLight;
    }

    const vec3 &getColor() const {
        return lightColor;
    }
};

#endif //RAYTRACER_LIGHT_H
