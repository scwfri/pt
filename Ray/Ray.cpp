#include "Ray.h"

Ray::Ray(Point3 const& origin, Vec3 const& direction)
    : m_origin(origin)
    , m_direction(direction)
{
}
