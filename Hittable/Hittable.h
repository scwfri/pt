#pragma once

#include "../Ray/Ray.h"

class Hittable {
public:
    struct HitRecord {
        Point3 point;
        Vec3 normal;
        double t;
        bool front_face;

        inline void set_face_normal(Ray const& ray, Vec3 const& outward_normal)
        {
            front_face = dot(ray.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
    };

    virtual bool hit(Ray const&, double const t_min, double const t_max, HitRecord&) = 0;
};
