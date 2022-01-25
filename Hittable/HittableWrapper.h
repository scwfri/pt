#pragma once

#include "Hittable.h"

#include <memory>
#include <vector>

class HittableWrapper : public Hittable {
public:
    HittableWrapper() = default;
    ~HittableWrapper() = default;
    // FIXME copy and assignment constructors

    inline void clear() { m_hittable_objects.clear(); }
    inline void add(std::shared_ptr<Hittable> const& hittable_object) { m_hittable_objects.push_back(hittable_object); }
    virtual bool hit(Ray const&, double const t_min, double const t_max, HitRecord&) override;

    std::vector<std::shared_ptr<Hittable>> hittable_objects() { return m_hittable_objects; }

private:
    std::vector<std::shared_ptr<Hittable>> m_hittable_objects;
};
