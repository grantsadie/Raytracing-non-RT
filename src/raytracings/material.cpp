#include "raytracings/material.h"
#include "raytracings/hittable.h"

bool lambertian::scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const
{
            auto scatter_direction = rec.normal + random_unit_vector();
            scattered = ray(rec.p, scatter_direction);
            attenuation = albedo;
            return true;
        }