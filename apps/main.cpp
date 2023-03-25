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

color ray_color(const ray& r, const hittable& world, int depth) {
    hit_record rec;
    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0,0,0);

    if (world.hit(r, 0.001, infinity, rec)) {
        point3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * ray_color(ray(rec.p, target - rec.p), world, depth-1);
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
    const int max_depth = 50;

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
                // auto u = double(i) / (image_width-1); // From 0 to 1, left to right
                // auto v = double(j) / (image_height-1); // From 0 to 1, left to right
                ray r = cam.get_ray(u, v); // Gets origin and direction of ray
                pixel_colour += ray_color(r, world, max_depth); 
            }
            write_color(std::cout, pixel_colour, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}