//
// Created by Spencer on 2/21/2024.
//

#include "rtweekend.h"

#include "hittable_list.h"
#include "camera.h"
#include "sphere.h"
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

    //initialize camera
    camera cam;

    cam.filename = "scene 2 render.ppm";
    cam.aspect_ratio = 1;
    cam.image_width = 400;
    cam.vfov = 65;
    cam.lookfrom = {0,0,1};
    cam.lookat = {0,0,0};
    cam.lookup = {0,1,0};

    cam.render(world, ambient, lightSource, background, lightDir);



}