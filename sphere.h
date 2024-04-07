//
// Created by Spencer on 3/13/2024.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:
    sphere(point3 _center, double _radius, const shared_ptr<material>& _mat) : center(_center), radius(_radius),
    mat(_mat->kd,_mat->ks,_mat->ka,_mat->od,_mat->os,_mat->kgls,_mat->refl){}

    bool hit(const ray& r, interval(ray_t), hit_record& rec) const override {
        vec3 oc = r.origin() - center;
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = half_b*half_b - a*c;
        if (discriminant < 0) return false;
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-half_b - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (-half_b + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r,outward_normal);

        rec.isSphere = true;
        return true;
    }

    material getMat() override {
        return mat;
    }

private:
    point3 center;
    double radius;
    material mat;
};


#endif //RAYTRACER_SPHERE_H
