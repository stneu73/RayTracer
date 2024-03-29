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

    world.add(make_shared<sphere>(point3(0,0,0),0.4,make_shared<material>(
            0.7, 0.2, 0.1, color{1.0, 0, 1.0}, color{1.0, 1.0, 1.0}, 16.0)));

    camera cam;
    cam.filename = "viewport test 1.ppm";
    cam.aspect_ratio = 1;
    cam.image_width = 400;
    cam.vfov = 90;
    cam.lookfrom = {0,0,1};
    cam.lookat = {0,0,0};
    cam.lookup = {0,1,0};

    color ambient{0.0,0.0,0.0};
    color lightSource{1.0,1.0,1.0};
    color background{0.2,0.2,0.2};

    cam.render(world, ambient, lightSource, background);
}