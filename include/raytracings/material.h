#ifndef MATERIAL_H
#define MATERIAL_H

#include "raytracings/rtutils.h"
#include "raytracings/ray.h"
// #include "raytracings/hittable.h"

struct hit_record;

class material {
    public:
        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const = 0;
};

class lambertian : public material {
    public:
        lambertian(const color& a) : albedo(a) {}

        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const override;

    public:
        color albedo;
};

#endif