//
// Created by Spencer on 3/20/2024.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


class material {
public:

    material(double kd, double ks, double ka, double od[], double os[], double kgls) {
        this->kd = kd;
        this->ks = ks;
        this->ka = ka;
        this->od[0] = od[0];
        this->od[1] = od[1];
        this->od[2] = od[2];
        this->os[0] = os[0];
        this->os[1] = os[1];
        this->os[2] = os[2];
        this->kgls = kgls;

    }

    double kd;
    double ks;
    double ka;
    double od[3];
    double os[3];
    double kgls;
};


#endif //RAYTRACER_MATERIAL_H
