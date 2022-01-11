#pragma once

#include "Hittable.h"

#include <memory>
#include <vector>

class HittableWrapper : public Hittable {
public:
    HittableWrapper() = default;
    ~HittableWrapper() = default;
    // FIXME copy and assignment constructors

    inline void clear() { hittable_objects.clear(); }
    inline void add(std::shared_ptr<Hittable> const& hittable_object) { hittable_objects.push_back(hittable_object); }
    virtual bool hit(Ray const&, double const t_min, double const t_max, HitRecord&) override;

private:
    std::vector<std::shared_ptr<Hittable>> hittable_objects;
};
