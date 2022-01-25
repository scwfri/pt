#include "HittableWrapper.h"

bool HittableWrapper::hit(Ray const& ray, double t_min, double t_max, HitRecord& hit_record)
{
    HitRecord _hit_record;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& hittable_object : m_hittable_objects)
    {
        if (hittable_object->hit(ray, t_min, closest_so_far, _hit_record)) {
            hit_anything = true;
            closest_so_far = _hit_record.t;
            hit_record = _hit_record;
        }
    }

    return hit_anything;
}
