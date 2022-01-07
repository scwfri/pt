#include "Sphere.h"

Sphere::Sphere(Point3 center, double const radius)
: center(center)
, radius(radius)
{
}
bool Sphere::hit(Ray const& ray, double const t_min, double const t_max, Hittable::HitRecord& hit_record)
{
    Vec3 oc = ray.origin() - center;
    auto a = ray.direction().length_squared();
    auto half_b = dot(oc, ray.direction());
    auto c = oc.length_squared() - radius * radius;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
        return false;
    auto discriminant_sqrt = sqrt(discriminant);

    // find nearest root that lies in range
    auto root = (-half_b - discriminant_sqrt) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + discriminant_sqrt) / a;
        if (root < t_min ||| t_max < root)
            return false;
    }

    hit_record.t = root;
    hit_record.point = ray.at(hit_record.t);
    hit_record.normal = (hit_record.point - center / radius);

    return true;
}
