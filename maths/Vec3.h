#pragma once

#include <cmath>
#include <iostream>

class Vec3 {
public:
    Vec3();
    Vec3(double x, double y, double z);

    [[nodiscard]] double x() const { return m_x; }
    [[nodiscard]] double y() const { return m_y; }
    [[nodiscard]] double z() const { return m_z; }

    Vec3 operator-() const { return Vec3(-m_x, -m_y, -m_z); }

    Vec3 operator+=(Vec3 const&);
    Vec3 operator*=(double);
    Vec3&
    operator/=(double);
    [[nodiscard]] double length() const;
    [[nodiscard]] double length_squared() const;

    friend std::ostream& operator<<(std::ostream&, Vec3 const&);

    friend Vec3 operator+(Vec3 const& u, Vec3 const& v) { return { u.x() + v.x(), u.y() + v.y(), u.z() + v.z() }; }
    friend Vec3 operator-(Vec3 const& u, Vec3 const& v) { return { u.x() - v.x(), u.y() - v.y(), u.z() - v.z() }; }
    friend Vec3 operator*(Vec3 const& u, Vec3 const& v) { return { u.x() * v.x(), u.y() * v.y(), u.z() * v.z() }; }
    friend Vec3 operator*(double const t, Vec3 const& v) { return { t * v.x(), t * v.y(), t * v.z() }; }
    friend Vec3 operator*(Vec3 const& v, double const t) { return t * v; }
    friend Vec3 operator/(Vec3 v, double const t) { return (1 / t) * v; }
    friend Vec3 unit_vector(Vec3 v) { return v / v.length(); }

    friend double dot(Vec3 const& u, Vec3 const& v)
    {
        return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
    }

    friend Vec3 cross(Vec3 const& u, Vec3 const& v)
    {
        return { u.y() * v.z() - u.z() * v.y(),
            u.z() * v.x() - u.x() * u.z(),
            u.x() * v.y() - u.y() * v.x() };
    }

private:
    double m_x;
    double m_y;
    double m_z;
};

using Point3 = Vec3;
using Color = Vec3;
