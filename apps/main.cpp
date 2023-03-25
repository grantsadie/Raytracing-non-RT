#include "raytracings/rtutils.h"
#include "colour/colour.h"
#include "raytracings/ray.h"
#include "raytracings/hittable_list.h"
#include "raytracings/sphere.h"
#include "raytracings/camera.h"
#include "math/vec3.h"

#include <iostream>

// double hit_sphere(const point3& center, double radius, const ray& r) {
//     // center is the center of the circle. 0,0,-1
//     // r.origin is 0,0,0 cause its the origin of the ray
//     // oc is the difference in the rays origin and the spheres center
//     // oc is pointing from the center of the sphere to the origin of the ray
//     vec3 oc = r.origin() - center;
//     auto a = dot(r.direction(), r.direction());
//     auto b = 2.0 * dot(oc, r.direction());
//     auto c = dot(oc, oc) - radius * radius;
//     auto discriminant = b*b - 4*a*c;
//     if (discriminant < 0) {
//         return -1.0;
//     } else {
//         return (-b - sqrt(discriminant) ) / (2.0*a);
//     }
// }

color ray_color(const ray& r, const hittable& world) {
    // auto t = hit_sphere(point3(0,0,-1), 0.5, r);
    // if (t > 0.0) {
    //     vec3 N = unit_vector(r.at(t) - vec3(0,0,-1));
    //     return 0.5*color(N.x()+1, N.y()+1, N.z()+1);
    // }
    // vec3 unit_direction = unit_vector(r.direction());
    // t = 0.5*(unit_direction.y() + 1.0);
    // return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.5, 0.5);
    // World items
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }

    // Background
    vec3 unit_direction = unit_vector(r.direction());
    double t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100;

    // World 
    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));


    // Camera
    camera cam;
    
    // Render

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_colour(0,0,0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = double(i + random_double()) / (image_width-1); // From 0 to 1, left to right
                auto v = double(j + random_double()) / (image_height-1);
                ray r = cam.get_ray(u, v);
                pixel_colour += ray_color(r, world);
            }
            write_color(std::cout, pixel_colour, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}