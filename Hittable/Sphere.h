#pragma once

#include "Hittable.h"
#include "../Maths/Vec3.h"

class Sphere : public Hittable {
public:
    Sphere() = default;
    ~Sphere() = default;

    Sphere(Point3, double const r);

    virtual bool hit(Ray const&, double const t_min, double const t_max, HitRecord&) override;

private:
    Point3 center;
    double const radius;
};
