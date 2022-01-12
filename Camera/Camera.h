#pragma once

#include "../Maths/Utils.h"
#include "../Maths/Vec3.h"
#include "../Ray/Ray.h"

class Camera {
public:
    Camera();
    ~Camera() = default;
    // FIXME copy and assignment constructors

    [[nodiscard]] Ray get_ray(double u, double v) const;

private:
    Point3 m_origin;
    Point3 m_lower_left_corner;
    Vec3 m_horizontal;
    Vec3 m_vertical;
};
