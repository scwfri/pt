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

Vec3 Vec3::operator*=(double const t)
{
    m_x *= t;
    m_y *= t;
    m_z *= t;
    return *this;
}

Vec3& Vec3::operator/=(double const t)
{
    *this *= 1 / t;
    return *this;
}

double Vec3::length() const
{
    return sqrt(length_squared());
}

double Vec3::length_squared() const
{
    auto x = m_x * m_x;
    auto y = m_y * m_y;
    auto z = m_z * m_z;

    return x + y + z;
}

std::ostream& operator<<(std::ostream& out, Vec3 const& v)
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}