#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include <vector>
#include "Object.h"

using namespace std;

class Triangle : public Object {
private:
    vector<vec3> vertices;
public:
    Triangle(const vector<vec3> &vertices, float kd, float ks, float ka, const vec3 &od, const vec3 &os,
             float kgls, float refl);

    pair<bool, vec3> checkForIntersect(Ray ray) override;

    vec3 getNorm(vec3 p) override;
};


#endif //RAYTRACER_TRIANGLE_H
