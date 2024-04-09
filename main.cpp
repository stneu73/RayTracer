//
// Created by Spencer on 2/21/2024.
//

#include "rtweekend.h"

#include "hittable_list.h"
#include "camera.h"
#include "sphere.h"
#include "triangle.h"
#include "material.h"

int camera::max_depth = 50;

int main() {
    hittable_list world;

//    scene 1
//    world.add(make_shared<sphere>(point3(0,0,0),0.4,make_shared<material>(
//            0.7, 0.2, 0.1, color{1.0, 0, 1.0}, color{1.0, 1.0, 1.0}, 16.0,0.0)));
//
//    vec3 lightDir = {0.0,1.0,0.0};
//    color ambient{0.2,0.2,0.2};
//    color lightSource{1.0,1.0,1.0};
//    color background{0.2,0.2,0.2};


    //scene 2
//    white sphere
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

//Triangle test
//    world.add(make_shared<triangle>(point3(-0.5,-0.5,0.0),
//                                    point3(0.5,0,0.0),
//                                    point3(0,-1.0,0.0),
//                                    make_shared<material>(.9,1.0,0.1,
//                                                          color(1.0,1.0,1.0),
//                                                          color(1.0,1.0,1.0),4.0,0.0)));
//    world.add(make_shared<triangle>(point3(-0.5,0.5,-1.0),
//                                    point3(0.5,1.0,-1.0),
//                                    point3(0.0,0.0,-1.0),
//                                    make_shared<material>(.9,1.0,0.1,
//                                                          color(1.0,0.0,0.0),
//                                                          color(1.0,1.0,1.0),4.0,0.0)));
//    vec3 lightDir = {0.0,0.0,1.0};
//    color ambient{0.1,0.1,0.1};
//    color lightSource{1.0,0.0,1.0};
//    color background{0.2,0.2,0.2};

//pt scene 1
    //reflective sphere
//    world.add(make_shared<sphere>(point3(0.0,0.3,-1.0),0.25, make_shared<material>(
//            0.0,0.1,0.1,color(0.75,0.75,0.75),color(1.0,1.0,1.0),10.0,0.9)));
//    world.add(make_shared<triangle>(point3(0.0,-0.7,-0.5),
//                                    point3(1.0,0.4,-1.0),
//                                    point3(0.0,-0.7,-1.5),
//                                    make_shared<material>(0.9,1.0,0.1,
//                                                          color(0.0,0.0,1.0),
//                                                          color(1.0,1.0,1.0),4.0,0.0)));
//    //yellow sphere
//    world.add(make_shared<triangle>(point3(0.0,-0.7,-0.5),
//                                    point3(0.0,-0.7,-1.5),
//                                    point3(-1.0,0.4,-1.0),
//                                    make_shared<material>(0.9,1.0,0.0,
//                                                          color(1.0,1.0,0.0),
//                                                          color(1.0,1.0,1.0),4.0,0.0)));
//
//    vec3 lightDir = {0.0,1.0,0.0};
//    color ambient{0.0,0.0,0.0};
//    color lightSource{1.0,1.0,1.0};
//    color background{0.2,0.2,0.2};


//pt 2 Scene 2
//    //white sphere
//    world.add(make_shared<sphere>(point3(0.5,0.0,-.15),0.05, make_shared<material>(
//            0.8,0.1,0.3,color(1.0,1.0,1.0),color(1.0,1.0,1.0),4.0,0.0)));
//    //red sphere
//    world.add(make_shared<sphere>(point3(0.3,0.0,-.1),0.08, make_shared<material>(
//            0.8,0.8,0.1,color(1.0,0.0,0.0),color(0.5,1.0,0.5),32.0,0.0)));
//    //green sphere
//    world.add(make_shared<sphere>(point3(-0.6,0.0,0.0),0.3, make_shared<material>(
//            0.7,0.5,0.1,color(0.0,1.0,0.0),color(0.5,1.0,0.5),64.0,0.0)));
//    //reflective sphere
//    world.add(make_shared<sphere>(point3(0.1,-0.55,0.25),0.3, make_shared<material>(
//            0.0,0.1,0.1,color(0.75,0.75,0.75),color(1.0,1.0,1.0),10.0,0.9)));
//    //blue triangle
//    world.add(make_shared<triangle>(point3(0.3,-0.3,-0.4),
//                                    point3(0.0,0.3,-0.1),
//                                    point3(-0.3,-0.3,0.2),
//                                    make_shared<material>(0.9,0.9,0.1,
//                                                          color(0.0,0.0,1.0),
//                                                          color(1.0,1.0,1.0),32.0,0.0)));
//    //yellow triangle
//    world.add(make_shared<triangle>(point3(-0.2,0.1,0.1),
//                                    point3(-0.2,-0.5,0.2),
//                                    point3(-0.2,0.1,-0.3),
//                                    make_shared<material>(0.9,0.5,0.1,
//                                                          color(1.0,1.0,0.0),
//                                                          color(1.0,1.0,1.0),4.0,0.0)));
//
//    vec3 lightDir = {1.0,0.0,0.0};
//    color ambient{0.1,0.1,0.1};
//    color lightSource{1.0,1.0,1.0};
//    color background{0.2,0.2,0.2};


    //random shapes
//    srand(3);
//    int maxShapes = 7;//rand()%15;
//    for (int i = 0; i < maxShapes; ++i) {
//        srand(i+1);
//        double kgls = rand()%64;
//        double refl = (rand()%10);//10;
//        double c11 = (rand()%10);//10;
//        double c12 = (rand()%10);//10;
//        double c13 = (rand()%10);//10;
//        double c21 = (rand()%10);//10;
//        double c22 = (rand()%10);//10;
//        double c23 = (rand()%10);//10;
//        double kd  = (rand()%10);//10;
//        double ks = (rand()%10);//10;
//        double ka = (rand()%10);//10;
//
//        if (rand()%3 == 0) {
//            double verticies[9];
//            for (int j = 0; j < 9; j++) {
//                verticies[j] = rand()%5-2.5;
//            }
//            world.add(make_shared<triangle>(point3(verticies[0], verticies[1],verticies[2]),
//                                            point3(verticies[3],verticies[4],verticies[5]),
//                                            point3(verticies[6],verticies[7],verticies[8]),
//                                            make_shared<material>(kd, ks, ka,
//                                                                  color(c11, c12, c13),
//                                                                  color(c21, c22, c23), kgls, refl)));
//        } else {
//            world.add(make_shared<sphere>(point3(rand()%5-2.5,rand()%5-2.5,rand()%5-2.5),rand()%10/100, make_shared<material>(
//                    kd, ks, ka,color(c11, c12, c13),color(c21, c22, c23),kgls,refl)));
//        }
//    }
//
//    vec3 lightDir = {1.0,1.0,1.0};
//    color ambient{0.1,0.1,0.1};
//    color lightSource{1.0,1.0,1.0};
//    color background{0.2,0.2,0.2};

//hagia sophia
    //colors
//    color tan = color(210.0/256.0,180.0/256.0,140.0/256.0);
//    color green = color(0.0,1.0,0.0);
//    color skyBlue = color(135/256.0, 206/256.0, 235/256.0);
//    color oceanBlue = color(50/256.0, 50/256.0, 235/256.0);
//    //dome
//    world.add(make_shared<sphere>(point3(0.0,0.0,0.0),.2, make_shared<material>(
//            1.0,1.0,1.0,tan,color(0.0,0.0,0.0 ),0.0,0.0)));
//    //ground
//    world.add(make_shared<sphere>(point3(0.0,-10005.5,20.0),10000.0, make_shared<material>(
//            1.0,1.0,1.0,green,color(0.0,0.0,0.0 ),0.0,0.0)));
//    //sky
//    world.add(make_shared<sphere>(point3(0.0,0.0,-15000.5),10000.0, make_shared<material>(
//            0.9,0.5,0.1,skyBlue,color(0.0,0.0,0.0 ),0.0,0.0)));
//    //base structure
//    point3 ful = point3(-0.5,0.0,0.2);
//    point3 flr = point3(0.45,-0.5,0.3);
//    point3 fll = point3(-0.45,-0.5,0.3);
//    point3 fur = point3(0.5,0.0,0.2);
//    world.add(make_shared<triangle>(ful,
//                                    fll,
//                                    fur,
//                                    make_shared<material>(0.9,0.5,0.1,
//                                                          tan,
//                                                          color(1.0,1.0,1.0),4.0,0.0)));
//    world.add(make_shared<triangle>(fur,
//                                    fll,
//                                    flr,
//                                    make_shared<material>(0.9,0.5,0.1,
//                                                          tan,
//                                                          color(1.0,1.0,1.0),4.0,0.0)));
//    //river
//    world.add(make_shared<triangle>(point3(0.0,-.8,-15.0),
//                                    point3(-0.5,-0.1,20.0),
//                                    point3(.50,-0.1,20.0),
//                                    make_shared<material>(0.9,0.5,0.1,
//                                                          oceanBlue,
//                                                          color(1.0,1.0,1.0),4.0,0.9)));

    vec3 lightDir = {0.0,0.0,0.5};
    color ambient{0.1,0.1,0.1};
    color lightSource{0.8,1.0,0.8};
    color background{0.2,0.2,0.2};

    //sphere pyramid
    double square2over2 = .707;// sqrt(2)/2;
    double radius = 0.707;

    world.add(make_shared<sphere>(point3(0.0,0.0,0.0),radius, make_shared<material>(
            0.9,0.5,0.3,color(1.0,1.0,1.0),color(0.0,0.0,0.0 ),0.6,0.7)));
    world.add(make_shared<sphere>(point3(square2over2,0.0,square2over2),radius, make_shared<material>(
            0.9,0.5,0.3,color(1.0,1.0,1.0),color(0.0,0.0,0.0 ),0.3,0.0)));
    world.add(make_shared<sphere>(point3(-square2over2,0.0,square2over2),radius, make_shared<material>(
            0.9,0.5,0.3,color(1.0,1.0,1.0),color(0.0,0.0,0.0 ),0.3,0.0)));
    world.add(make_shared<sphere>(point3(0.0,square2over2,square2over2/2),radius, make_shared<material>(
            0.9,0.5,0.2,color(1.0,1.0,1.0),color(0.0,0.0,0.0 ),0.3,0.0)));
    world.add(make_shared<sphere>(point3(0.0,-square2over2,square2over2/2),radius, make_shared<material>(
            0.9,0.5,0.2,color(1.0,1.0,1.0),color(0.0,0.0,0.0 ),0.1,0.0)));
    world.add(make_shared<sphere>(point3(0.0,-square2over2,square2over2+square2over2/2),radius, make_shared<material>(
            0.9,0.5,0.2,color(1.0,1.0,1.0),color(0.0,0.0,0.0 ),0.1,0.0)));
    world.add(make_shared<sphere>(point3(-square2over2*2,-square2over2,square2over2+square2over2/2),radius, make_shared<material>(
            0.9,0.5,0.2,color(1.0,1.0,1.0),color(0.0,0.0,0.0 ),0.1,0.0)));
    world.add(make_shared<sphere>(point3(square2over2*2,-square2over2,square2over2+square2over2/2),radius, make_shared<material>(
            0.9,0.5,0.2,color(1.0,1.0,1.0),color(0.0,0.0,0.0 ),0.1,0.0)));
    //big sphere
    world.add(make_shared<sphere>(point3(0.0,-40.7,0.0),40, make_shared<material>(
            0.9,0.5,0.1,color(0.0,0.0,1.0),color(0.5,0.5,0.5),4.0,0.8)));

    world.add(make_shared<triangle>(point3(0.0,7,-5),
                                    point3(-5,-1,-5),
                                    point3(5,-1,-5),
                                    make_shared<material>(0.9,0.5,0.1,
                                                          color(0.0,0.0,250.0/256.0),
                                                          color(1.0,1.0,1.0),4.0,0.9)));
    world.add(make_shared<triangle>(point3(2.0,6,-5.5),
                                    point3(-3,-1,-5.5),
                                    point3(7,-5,-5.5),
                                    make_shared<material>(0.9,0.5,0.1,
                                                          color(1.0,0.0,.8),
                                                          color(1.0,1.0,1.0),4.0,0.9)));
    world.add(make_shared<triangle>(point3(-2,6,-5.5),
                                    point3(-7,-5,-5.5),
                                    point3(3,-1,-5.5),
                                    make_shared<material>(0.9,0.5,0.1,
                                                          color(148/256.0,87/256.0,235/256.0),
                                                          color(1.0,1.0,1.0),4.0,0.9)));
    world.add(make_shared<triangle>(point3(0.0,15,-7),
                                    point3(-10,-5,-7),
                                    point3(10,-5,-7),
                                    make_shared<material>(0.9,0.5,0.1,
                                                          color(0.0,0.0,0),
                                                          color(0,0,0),64.0,0.0)));
    world.add(make_shared<triangle>(point3(5.0,1.0,0.0),
                                    point3(square2over2*2,-square2over2,square2over2+square2over2/2),
                                    point3(-square2over2*2,-square2over2,square2over2+square2over2/2),
                                    make_shared<material>(0.9,0.5,0.1,
                                                          color(1.0,215/256.0,0.0),
                                                          color(1.0,1.0,1.0),4.0,0.9)));
    world.add(make_shared<triangle>(point3(-5.0,2.0,0.0),
                                    point3(square2over2*2,-square2over2,square2over2+square2over2/2),
                                    point3(-square2over2*2,-square2over2,square2over2+square2over2/2),
                                    make_shared<material>(0.9,0.5,0.1,
                                                          color(0.0,100/256.0,1.0),
                                                          color(1.0,1.0,1.0),4.0,0.9)));

    //initialize camera
    camera cam;

    cam.filename = "sphere pyramid.ppm";
    cam.aspect_ratio = 1;
    cam.image_width = 800;
    cam.vfov = 70;
    cam.lookfrom = {0,.2,8};
    cam.lookat = {0,0,0};
    cam.lookup = {0,1,0};

    cam.render(world, ambient, lightSource, background, lightDir);
}