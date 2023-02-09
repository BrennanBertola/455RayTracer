cmake_minimum_required(VERSION 3.21)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracer main.cpp vec3.h Object.h Sphere.h Light.h Camera.h Scene.h Scene.cpp RayTracer.cpp RayTracer.h Ray.h)
