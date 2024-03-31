//
// Created by Spencer on 3/18/2024.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "rtweekend.h"

#include "color.h"
#include "hittable.h"

#include <iostream>
#include <fstream>

class camera {
public:
    double aspect_ratio;
    int image_width;
    int max_depth = 10;

    std::string filename;
    double vfov;
    point3 lookfrom;
    point3 lookat;
    vec3   lookup;

    void render(const hittable& world, color ambient, color lightSource, color background, vec3 lightDir) {
        initialize();

        std::ofstream out(filename);

        out << "P3\n" << image_width << ' ' << image_height << "\n255\n";
//        int pixelnum = 0; //used for debugging by isolating a single pixel
        for (int j = 0; j < image_height; ++j) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i) {
//                pixelnum += 1;
                auto pixel_center = pixel00_loc + (i* pixel_delta_u) + (j * pixel_delta_v);
                auto ray_direction = pixel_center - center;
                ray r(center, ray_direction);

                color pixel_color = ray_color(r,world,ambient, lightSource, background, lightDir);
                write_color(out, pixel_color);
            }
        }
        std::clog << "\rDone.               \n";
    }

private:
    int image_height;       // rendered image height
    point3 center;          // camera center
    point3 pixel00_loc;    // location of pixel (0,0)
    vec3 pixel_delta_u;     // offset to pixel to the right
    vec3 pixel_delta_v;     // offset to pixel below
    vec3 u,v,w;

    void initialize() {
        image_height = static_cast<int>(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        center = lookfrom;

        //viewport dimensions
        auto focal_length = (lookfrom-lookat).length();
        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta/2);
        auto viewport_height = 2 * h * focal_length;
        auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);

        // Calculate the u,v,w unit basis vectors for the camera coordinate frame.
        w = unit_vector(lookfrom - lookat);
        u = unit_vector(cross(lookup, w));
        v = cross(w, u);

        // Calculate the vectors across the horizontal and down the vertical viewport edges.
        auto viewport_u = viewport_width * u;
        auto viewport_v = viewport_height * -v;

        // Calculate the horizontal and vertical delta vectors from pixel to pixel.
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // Calculate the location of the upper left pixel.
        auto viewport_upper_left = center
                                   - focal_length * w - viewport_u/2 - viewport_v/2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }

    static color ray_color(const ray& r, const hittable& world, color ambient, color lightSource, color background, vec3 lightDir) {

        hit_record rec;

        if (world.hit(r,interval(0,infinity), rec)) {

            return rec.obMat.illuminationEq(ambient, lightSource, r.direction(), rec.normal,lightDir);
            //return 0.5 * (rec.normal + color(1,1,1));
        }
        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.x() + 1.0);
//        return background;
        return color(0.0,0.0,0.0) + (1.0-a)*color(0.3,0.0,0.0);
    }
};


#endif //RAYTRACER_CAMERA_H
