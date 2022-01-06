#pragma once

#include "../maths/Vec3.h"

class Ray {
public:
    Ray() = default;
    ~Ray() = default;
    // FIXME add copy constructor etc

    Ray(Point3 const&, Vec3 const&);

    [[nodiscard]] Point3 origin() const { return m_origin; }
    [[nodiscard]] Vec3 direction() const { return m_direction; }

    [[nodiscard]] Point3 at(double const t) const {
        return m_origin + t * m_direction;
    }

private:
    Point3 m_origin;
    Vec3 m_direction;
};
