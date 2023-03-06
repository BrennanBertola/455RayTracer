//
// Created by brenn on 3/5/2023.
//

#include "Triangle.h"


pair<bool, vec3> Triangle::checkForIntersect(Ray ray) {
    return pair<bool, vec3>();
}

vec3 Triangle::getNorm(vec3 p) {
    return unit_vector(cross((vertices[2]-vertices[1]), (vertices[0]-vertices[1])));
}

Triangle::Triangle(const vector<vec3> &vertices, float ks, float kd, float ka, const vec3 &od, const vec3 &os,
                   float kgls, float refl) : Object(ks, kd, ka, od, os, kgls, refl), vertices(vertices) {}
