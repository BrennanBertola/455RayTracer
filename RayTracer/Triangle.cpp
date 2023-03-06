//
// Created by brenn on 3/5/2023.
//

#include "Triangle.h"

string magnitude(vec3 p) {
    float x = abs(p.x());
    float y = abs(p.y());
    float z = abs(p.z());

    if (x >= y and x >= z){
        return "X";
    }
    if (y >= z and y >= x) {
        return "Y";
    }
    return "Z";
}

pair<float, float> dropPointAxis(vec3 p, string dropAxis) {
    if (dropAxis == "X") {
        return {p.y(), p.z()};
    }
    else if (dropAxis == "Y") {
        return {p.x(), p.z()};
    }
    else {
        return {p.x(), p.y()};
    }

}

pair<bool, vec3> Triangle::checkForIntersect(Ray ray) {
    vec3 norm = getNorm(vec3());

    //flips the norm to the side that faces the camera
//    if (dot(norm, ray.getDir()) > 0) {
//        norm *= -1;
//    }
    if (dot(norm, ray.getDir()) == 0) {
        return {false, vec3()};
    }

    float d = -1.0 *(norm.x() * vertices[0].x() + norm.y() * vertices[0].y() + norm.z() * vertices[0].z());
    float t = (-1.0 * (dot(norm, ray.getOri()) + d)) / dot(norm, ray.getDir());

    if (t <= 0) {
        return {false, vec3()};
    }

    vec3 p = ray.at(t);
    string dropAxis = magnitude(p);
    pair <float, float> newP = dropPointAxis(p, dropAxis);

    vector<pair<float, float>> projected;
    for (auto curr : vertices) {
        auto val = dropPointAxis(curr, dropAxis);
        projected.push_back({val.first - newP.first, val.second - newP.second});
    }

    int numCrosses = 0;
    int sign = 1;
    if (projected[0].second < 0){sign = -1;}
    for (int i = 0; i < projected.size(); ++i) {
        int nextIdx = i+1;
        if (i+1 >= projected.size()) {nextIdx = 0;}
        auto curr = projected[i];
        auto next = projected[nextIdx];

        int nextSign = 1;
        if (next.second < 0) {nextSign = -1;}
        if (sign < nextSign or sign > nextSign) {
            if (curr.first >= 0 and next.first >= 0) {numCrosses++;}
            else if (curr.first >= 0 or next.first >= 0) {
                float cross = curr.first - curr.second * (next.first - curr.first)/(next.second - curr.second);
                if (cross >= 0) {numCrosses++;}
            }
        }

        sign = nextSign;
    }

    if (numCrosses % 2 == 0) {
        return {false, vec3()};
    }

    return {true, p};
}

vec3 Triangle::getNorm(vec3 p) {
    return unit_vector(cross((vertices[2]-vertices[1]), (vertices[0]-vertices[1])));
}

Triangle::Triangle(const vector<vec3> &vertices, float kd, float ks, float ka, const vec3 &od, const vec3 &os,
                   float kgls, float refl) : Object(ks, kd, ka, od, os, kgls, refl), vertices(vertices) {}
