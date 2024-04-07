//
// Created by Spencer on 3/20/2024.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "color.h"
#include <cmath>
#include <algorithm>

class material {
public:

    material() {
        this->kd = 0;
        this->ks = 0;
        this->ka = 0;
        od = {0,0,0};
        os = {0,0,0};
        this->kgls = 0;
        this->refl = 0;
    }

    material(double kd, double ks, double ka, color odiff, color ospec, double kgls, double refl) {
        this->kd = kd;
        this->ks = ks;
        this->ka = ka;
        od = odiff;
        os = ospec;
        this->kgls = kgls;
        this->refl = refl;
    }

    color illuminationEq(color Ia, color Ip, vec3 v, vec3 normal, vec3 L,color reflection, bool isSphere) {

        color amb = Ia * ka * od;

        double NdotL = dot(unit_vector(normal), unit_vector(L));
        color diffuse = kd * Ip * od * std::max(0.0,NdotL);

        vec3 r = 2*normal*dot(normal,L)-L;

        double VdotR = dot(unit_vector(v),unit_vector(-r)); //-r because the equation assumes that r is coming from the point
        color specular = ks * os * Ip * pow(std::max(0.0,VdotR),kgls); //phong
        color totalColor = amb + diffuse + specular + reflection * refl;
        totalColor = clamp(totalColor,0.0,1.0);
        return totalColor;
    }

    static color clamp(color vec,double min, double max) {
        for (int i = 0; i <= 2; i++) {
            if (vec[i] < 0) {
                vec[i] = 0;
            } else if (vec[i] > 1) {
                vec[i] = 1;
            } else {}
        }
        return vec;
    }

    double kd;
    double ks;
    double ka;
    color od;
    color os;
    double kgls;
    double refl;

};


#endif //RAYTRACER_MATERIAL_H
