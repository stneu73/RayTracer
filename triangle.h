//
// Created by Spencer on 4/3/2024.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H


#include <cmath>

#include "hittable.h"
#include "vec3.h"

class triangle : public hittable {
public:
    triangle(point3 a, point3 b, point3 c, const shared_ptr<material>& _mat) : v0(a), v1(b), v2(c),
    mat(_mat->kd,_mat->ks,_mat->ka,_mat->od,_mat->os,_mat->kgls,_mat->refl){}

    bool hit(const ray& r, interval(ray_t), hit_record& rec) const override {
        // Compute the plane's normal
        vec3 v0v1 = v1 - v0;
        vec3 v0v2 = v2 - v0;
        // No need to normalize
        vec3 N = cross(v0v1,v0v2); // N

//        double area2 = N.length();

        // Step 1: Finding P

        // Check if the ray and plane are parallel
        double NdotRayDirection = dot(N,r.direction());
        if (std::fabs(NdotRayDirection) < 0) // Almost 0
            return false; // They are parallel, so they don't intersect!

        // Compute d parameter using equation 2
        double d = dot(-N,v0);

        // Compute t (equation 3)
        double t = -(dot(N,r.origin()) + d) / NdotRayDirection;

        // Check if the triangle is behind the ray
        if (!ray_t.surrounds(t)) return false; // The triangle is behind


        // Compute the intersection point using equation 1
        vec3 P = r.origin() + t * r.direction();

        // Step 2: Inside-Outside Test
        vec3 C; // Vector perpendicular to triangle's plane

        // Edge 0
        vec3 edge0 = v1 - v0;
        vec3 vp0 = P - v0;
        C = cross(edge0,vp0);
        if (dot(N,C) < 0) return false; // P is on the right side

        // Edge 1
        vec3 edge1 = v2 - v1;
        vec3 vp1 = P - v1;
        C = cross(edge1,vp1);
        if (dot(N,C) < 0) return false; // P is on the right side

        // Edge 2
        vec3 edge2 = v0 - v2;
        vec3 vp2 = P - v2;
        C = cross(edge2,vp2);
        if (dot(N,C) < 0) return false; // P is on the right side

        rec.isSphere = false;
        rec.t = t;
        rec.p = r.at(rec.t);
        rec.set_face_normal(r,N);

        return true; // This ray hits the triangle
    }

    material getMat() override {
        return mat;
    }

private:
    point3 v0;
    point3 v1;
    point3 v2;
    material mat;
};


#endif //RAYTRACER_TRIANGLE_H
