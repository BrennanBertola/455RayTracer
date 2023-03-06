#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "Ray.h"
#include "Object.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Light.h"
#include "Camera.h"
#include <vector>
#include <iostream>

class Scene {
private:
    vector<Object*> objs;
    Light light;
    Camera cam;
    vec3 backColor;
    vec3 ambLight;
    string name;
public:
    Scene(const vec3 &backColor, const vec3 &ambLight, const string &name) : backColor(backColor), ambLight(ambLight), name(name){}

    ~Scene() {
        while (!objs.empty()) {
            delete objs.back();
            objs.pop_back();
        }
    }

    const string &getName() const {
        return name;
    }

    void setCam(const Camera &cam) {
        Scene::cam = cam;
    }
    void addObj(Object* obj) {
        objs.push_back(obj);
    }
    void setLight(const Light &light) {
        this->light = light;
    }


     vector<Object*> getObjs()  {
        return objs;
    }

    const Light &getLight() const {
        return light;
    }

    const Camera &getCam() const {
        return cam;
    }

    const vec3 &getBackColor() const {
        return backColor;
    }

    const vec3 &getAmbLight() const {
        return ambLight;
    }
};

#endif //RAYTRACER_SCENE_H
