#include <iostream>
#include "RayTracer.h"

int main() {

    // Image
    const int image_width = 500;
    const int image_height = 500;

    Scene* scene = new Scene(vec3(.2,.2,.2), vec3(0,0,0), "1");

    //A fov 60 fit the examples better, that's why I'm using it over 90.
    Camera cam (vec3(0,0,0), vec3(0,0,1), vec3(0,1,0), 60);
    scene->setCam(cam);

    Light light(vec3(0,1,0), vec3(1,1,1));
    scene->setLight(light);

    Sphere* sphere = new Sphere(vec3(0.0, 0.3, -1.0), .25, 0, .1, .1, vec3(.75,.75,.75), vec3(1,1,1), 10, .9);
    scene->addObj(sphere);

    vector<vec3> tmp = {vec3(0, -.7, -.5), vec3(1, .4, -1), vec3(0,-.7,-1.5)};
    Triangle* triangle = new Triangle(tmp, .9, 1, .1, vec3(0,0,1), vec3(1,1,1), 4, 0);
    scene->addObj(triangle);

    tmp = {vec3(0,-.7,-.5), vec3(0,-.7,-1.5), vec3(-1.,.4, -1.0)};
    triangle = new Triangle(tmp, .9,1,.1, vec3(1,1,0), vec3(1,1,1), 4, 0);
    scene->addObj(triangle);

    RayTracer tracer;
    tracer.traceScene(image_width, image_height, scene);
    delete scene;

    scene = new Scene(vec3(.2,.2,.2), vec3(.1,.1,.1), "2");
    scene->setCam(cam);

    light = Light(vec3(1,0,0), vec3(1,1,1));
    scene->setLight(light);

    sphere = new Sphere(vec3(.5,0,-.15), .05, .8,.1,.3, vec3(1,1,1), vec3(1,1,1), 4, 0);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(.3,0,-.1), .08, .8, .8, .1, vec3(1,0,0), vec3(.5,1,.5), 32, 0);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(-.6,0,0), .3, .7, .5, .1, vec3(0,1,0), vec3(.5,1,.5), 64, 0);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(.1,-.55,.25),.3,0,.1,.1, vec3(.75,.75,.75), vec3(1,1,1), 10, 0.9);
    scene->addObj(sphere);

    tmp = {vec3(.3,-.3,-.4), vec3(.0,.3,-.1), vec3(-.3,-.3,.2)};
    triangle = new Triangle(tmp, .9,.9,.1, vec3(0,0,1), vec3(1,1,1), 32, 0);
    scene->addObj(triangle);
    tmp = {vec3(-.2,.1,.1), vec3(-.2,-.5,.2), vec3(-.2,.1,-.3)};
    triangle = new Triangle(tmp, .9,.5,.1, vec3(1,1,0), vec3(1,1,1), 4, 0);
    scene->addObj(triangle);

    tracer.traceScene(image_width, image_height, scene);
    delete scene;

    scene = new Scene(vec3(.2,.2,.2), vec3(.1,.1,.1), "3");
    scene->setCam(cam);

    light = Light(vec3(0,0 ,1), vec3(1,1,1));
    scene->setLight(light);


    tmp = {vec3(-.2, -.2, .2), vec3(.2,-.2, -.2), vec3(0, .2, 0)};
    triangle = new Triangle(tmp, .9,.9,.1, vec3(0.137,0.431,0.588), vec3(1,1,1), 32, 0);
    scene->addObj(triangle);
    tmp = {vec3(.2, .2, .2), vec3(-.2,.2, -.2), vec3(0, -.2, 0)};
    triangle = new Triangle(tmp, .9,.5,.1, vec3(0.952,0.529,0.184), vec3(1,1,1), 4, 0);
    scene->addObj(triangle);


    sphere = new Sphere(vec3(0.0, 0, 0), .075, 0, .1, .1, vec3(1,1,1), vec3(1,1,1), 10, .9);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(0.0, .25, 0), .075, 0, .1, .1, vec3(1,1,1), vec3(1,1,1), 10, .9);
    scene->addObj(sphere);
    sphere = new Sphere(vec3(0.0, -.25, 0), .075, 0, .1, .1, vec3(1,1,1), vec3(1,1,1), 10, .9);
    scene->addObj(sphere);

    tracer.traceScene(image_width, image_height, scene);
    delete scene;

}