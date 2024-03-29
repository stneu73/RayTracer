//
// Created by Spencer on 3/20/2024.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "color.h"
#include <cmath>

class material {
public:

    material() {
        this->kd = 0;
        this->ks = 0;
        this->ka = 0;
        od = {0,0,0};
        os = {0,0,0};
        this->kgls = 0;
    }
    material(double kd, double ks, double ka, color odiff, color ospec, double kgls) {
        this->kd = kd;
        this->ks = ks;
        this->ka = ka;
        od = odiff;
        os = ospec;
        this->kgls = kgls;

    }

    color illuminationEq(color Ia, color Ip, vec3 v, vec3 normal) {

        vec3 L = {0.0,1.0,0.0};
        color amb = Ia * ka * od;

        double NdotL = dot(normal, L);
        color diffuse = kd * Ip * od * std::max(0.0,NdotL);

        vec3 r = 2*normal*dot(normal,L)-L;

        double VdotR = dot(v,-r);
        color specular = ks * os * Ip * pow(std::max(0.0,VdotR),kgls); //phong

        return amb + diffuse + specular;
    }

    double kd;
    double ks;
    double ka;
    color od;
    color os;
    double kgls;

};


#endif //RAYTRACER_MATERIAL_H
