//
// Created by Spencer on 2/21/2024.
//

#include "rtweekend.h"

#include "hittable_list.h"
#include "camera.h"
#include "sphere.h"
#include "triangle.h"
#include "material.h"

int main() {
    hittable_list world;

    //scene 1
//    world.add(make_shared<sphere>(point3(0,0,0),0.4,make_shared<material>(
//            0.7, 0.2, 0.1, color{1.0, 0, 1.0}, color{1.0, 1.0, 1.0}, 16.0)));

//    vec3 lightDir = {0.0,1.0,0.0};
//    color ambient{0.0,0.0,0.0};
//    color lightSource{1.0,1.0,1.0};
//    color background{0.2,0.2,0.2};


    //scene 2
    //white sphere
//    world.add(make_shared<sphere>(point3(0.45,0.0,-0.15),0.15,make_shared<material>(
//            0.8, 0.1, 0.3, color{1.0, 1.0, 1.0}, color{1.0, 1.0, 1.0}, 4.0)));
//    //red sphere
//    world.add(make_shared<sphere>(point3(0.0,0.0,-0.1),0.2,make_shared<material>(
//            0.6, 0.3, 0.1, color{1.0, 0.0, 0.0}, color{1.0, 1.0, 1.0}, 32.0)));
//    //green sphere
//    world.add(make_shared<sphere>(point3(-0.6,0.0,0.0),0.3,make_shared<material>(
//            0.7, 0.2, 0.1, color{0.0, 1.0, 0.0}, color{0.5, 1.0, 0.5}, 64.0)));
//    //large blue sphere
//    world.add(make_shared<sphere>(point3(0.0,-10000.5,0.0),10000.0,make_shared<material>(
//            0.9, 0.0, 0.1, color{0.0, 0.0, 1.0}, color{1.0, 1.0, 1.0}, 16.0)));
//
//    vec3 lightDir = {1.0,1.0,1.0};
//    color ambient{0.1,0.1,0.1};
//    color lightSource{1.0,1.0,1.0};
//    color background{0.2,0.2,0.2};

//    //scene 3 the snowman
//    //base
//    world.add(make_shared<sphere>(point3(0,-0.75,0.0),.32,make_shared<material>(
//            0.7, 0.2, 0.1, color{1.0, 1.0, 1.0}, color{1.0, 1.0, 1.0}, 1.0)));
//    //body
//    world.add(make_shared<sphere>(point3(0,-0.33,0.0),.23,make_shared<material>(
//            0.7, 0.2, 0.1, color{1.0, 1.0, 1.0}, color{1.0, 1.0, 1.0}, 1.0)));
//    //head
//    world.add(make_shared<sphere>(point3(0,0.01,0),.16,make_shared<material>(
//            0.7, 0.2, 0.1, color{1.0, 1.0, 1.0}, color{1.0, 1.0, 1.0}, 1.0)));
//    //eyes
//    world.add(make_shared<sphere>(point3(-.05,0.03,0.16),.01,make_shared<material>(
//            0.7, 0.2, 0.1, color{0, 0, 0}, color{0.3, 0, 0}, 64.0)));
//    world.add(make_shared<sphere>(point3(.05,0.03,0.16),.01,make_shared<material>(
//            0.7, 0.2, 0.1, color{0, 0, 0}, color{0.3, 0, 0}, 64.0)));
//    //nose
////    world.add(make_shared<sphere>(point3(0,0.01,0.16),.01,make_shared<material>(
////            0.7, 0.2, 0.1, color{0, 0, 0}, color{0.3, 0, 0}, 100.0)));
//    //mouth
//    world.add(make_shared<sphere>(point3(0,-0.04,0.16),.014,make_shared<material>(
//            0.7, 0.2, 0.1, color{0, 0, 0}, color{0.3, 0, 0}, 100.0)));
//    //buttons
//    world.add(make_shared<sphere>(point3(0,-0.23,0.21),.03,make_shared<material>(
//            0.7, 0.2, 0.1, color{0, 0, 0}, color{0.3, 0, 0}, 1.0)));
//    world.add(make_shared<sphere>(point3(0,-0.4,0.21),.03,make_shared<material>(
//            0.7, 0.2, 0.1, color{0, 0, 0}, color{0.3, 0, 0}, 1.0)));
//    //floor
//    world.add(make_shared<sphere>(point3(0,-10100,-1),10000,make_shared<material>(
//            0.5, 0, 0.1, color{.2, .2, .2}, color{0.3, .2, .2}, 1.0)));
    world.add(make_shared<triangle>(point3(-1,-1,0),
                                    point3(1,-1,0),
                                    point3(0,1,0),
                                    make_shared<material>(.9,1.0,0.1,
                                                          color(1.0,1.0,0.0),
                                                          color(1.0,1.0,1.0),4.0)));
    vec3 lightDir = {-1.0,0.0,1.0};
    color ambient{0.1,0.1,0.1};
    color lightSource{1.0,1.0,1.0};
    color background{0.1,0.0,0.0};


    //initialize camera
    camera cam;

    cam.filename = "first triangle.ppm";
    cam.aspect_ratio = 1;
    cam.image_width = 400;
    cam.vfov = 65;
    cam.lookfrom = {0,0,2};
    cam.lookat = {0,0,0};
    cam.lookup = {0,1,0};

    cam.render(world, ambient, lightSource, background, lightDir);



}