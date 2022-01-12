#include "Vec3.h"

Vec3::Vec3()
{
    m_x = random_double();
    m_y = random_double();
    m_z = random_double();
};

Vec3::Vec3(double const min, double const max)
{
    m_x = random_double(min, max);
    m_y = random_double(min, max);
    m_z = random_double(min, max);
}

Vec3::Vec3(double const x, double const y, double const z)
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

std::ostream& operator<<(std::ostream& out, Vec3 const& v)
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}
