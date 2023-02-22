#include <iostream>
#include "RayTracer.h"

int main() {

    // Image
    const int image_width = 1000;
    const int image_height = 1000;

    Scene* scene = new Scene (vec3(.2,.2,.2), vec3(0,0,0), "1");

    //A fov 60 fit the examples better, that's why I'm using it over 90.
    Camera cam (vec3(0,0,0), vec3(0,0,1), vec3(0,1,0), 60);
    scene->setCam(cam);

    Light light(vec3(0,2,0), vec3(1,1,1));
    scene->setLight(light);

    Sphere* sphere = new Sphere (vec3(0,0,0), .4, .7, .2, .1, vec3(1,0,1), vec3(1,1,1), 16);
    scene->addObj(sphere);

    RayTracer tracer;
    tracer.traceScene(image_width, image_height, scene);
    delete scene;

    scene = new Scene (vec3(.2,.2,.2), vec3(.1,0.1,0.1), "2");
    scene->setCam(cam);

    light = Light(vec3(1,1,1), vec3(1,1,1));
    scene->setLight(light);

    sphere = new Sphere(vec3(.45, 0, -0.15), .15, .8, .1, .1, vec3(1,1,1), vec3(1,1,1), 4);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(0,0,-0.1), .2, .6, .3, .1, vec3(1,0,0), vec3(1,1,1), 32);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(-0.6,0,0), .3, .6, .2, .1, vec3(0,1,0), vec3(.5,1,.5), 64);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(0, -10000.5, 0), 10000, .9, 0, .1, vec3(0,0,1), vec3(1,1,1), 16);
    scene->addObj(sphere);

    tracer.traceScene(image_width, image_height, scene);
    delete scene;

    scene = new Scene (vec3(.2,.2,.7), vec3(.5,.5,0.5), "3");
    scene->setCam(cam);

    light = Light(vec3(0,1,1), vec3(1,1,1));
    scene->setLight(light);

    sphere = new Sphere(vec3(0, 0, 0), .1, .7, .2, .1, vec3(.94,.71,.83), vec3(1,1,1), 32);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(0,0,-0.25), .2, .6, .3, .1, vec3(.5,.8,.88), vec3(1,1,1), 32);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(0,0,-0.35), .3, .5, .4, .1, vec3(.98,.78,.59), vec3(.5,1,.5), 64);
    scene->addObj(sphere);

    tracer.traceScene(image_width, image_height, scene);
    delete scene;

}