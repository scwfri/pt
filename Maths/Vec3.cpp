#include "Vec3.h"

Vec3::Vec3()
    : m_x(0)
    , m_y(0)
    , m_z(0) {};

Vec3::Vec3(double x, double y, double z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
{
}

Vec3 Vec3::operator+=(Vec3 const& other)
{
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;
    return *this;
}

Vec3 Vec3::operator*=(double t)
{
    m_x *= t;
    m_y *= t;
    m_z *= t;
    return *this;
}

Vec3& Vec3::operator/=(double t)
{
    *this *= 1 / t;
    return *this;
}

Vec3 Vec3::random_in_unit_sphere()
{
    while (true) {
        auto vec = Vec3::random(-1, 1);
        if (vec.length_squared() >= 1)
            continue;
        return vec;
    }
}

Vec3 Vec3::random_unit_vector()
{
    return unit_vector(Vec3::random_in_unit_sphere());
}

std::ostream& operator<<(std::ostream& out, Vec3 const& v)
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}
