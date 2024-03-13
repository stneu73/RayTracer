cmake_minimum_required(VERSION 3.27)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RayTracer
        main.cpp
        vec3.h
        color.h
        ray.h)