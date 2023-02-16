#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "Ray.h"
#include "Object.h"
#include "Sphere.h"
#include "Light.h"
#include "Camera.h"
#include <vector>

class Scene {
private:
    vector<Object*> objs;
    vector<Light> lights;
    Camera cam;
    vec3 backColor;
    vec3 ambLight;
public:
    Scene(const vec3 &backColor, const vec3 &ambLight) : backColor(backColor), ambLight(ambLight) {}

    ~Scene() {
        while (!objs.empty()) {
            delete objs.front();
        }
    }

    void setCam(const Camera &cam) {
        Scene::cam = cam;
    }
    void addObj(Object* obj) {
        objs.push_back(obj);
    }
    void addLight(const Light &light) {
        lights.push_back(light);
    }

     vector<Object*> getObjs()  {
        return objs;
    }

    const vector<Light> &getLights() const {
        return lights;
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
