#pragma once

#include "Hittable.h"
#include "../Maths/Vec3.h"

class Sphere : public Hittable {
public:
    Sphere() = delete;
    ~Sphere() = default;

    Sphere(Point3, double r);

    virtual bool hit(Ray const&, double t_min, double t_max, HitRecord&) override;

    Point3 center() { return m_center; }
    double radius() { return m_radius; }

private:
    Point3 m_center;
    double m_radius;
};
