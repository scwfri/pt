#pragma once

#include "../Ray/Ray.h"

class Hittable {
public:
    struct HitRecord {
        Point3 point;
        Vec3 normal;
        double t;
    };

    virtual bool hit(Ray const&, double const t_min, double const t_max, HitRecord&) = 0;
};
