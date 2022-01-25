#pragma once

#include <cmath>
#include <iostream>
#include "Utils.h"

class Vec3 {
public:
    Vec3();
    Vec3(double x, double y, double z);
    ~Vec3() = default;

    // FIXME copy constructor, etc

    [[nodiscard]] constexpr double x() const { return m_x; }
    [[nodiscard]] constexpr double y() const { return m_y; }
    [[nodiscard]] constexpr double z() const { return m_z; }

    Vec3 operator-() const { return Vec3(-m_x, -m_y, -m_z); }

    Vec3 operator+=(Vec3 const&);
    Vec3 operator*=(double);
    Vec3& operator/=(double);

    [[nodiscard]] double length() const { return sqrt(length_squared()); }
    [[nodiscard]] constexpr double length_squared() const
    {
        auto x = m_x * m_x;
        auto y = m_y * m_y;
        auto z = m_z * m_z;

        return x + y + z;
    }

    friend std::ostream& operator<<(std::ostream&, Vec3 const&);

    friend Vec3 operator+(Vec3 const& u, Vec3 const& v) { return { u.x() + v.x(), u.y() + v.y(), u.z() + v.z() }; }
    friend Vec3 operator-(Vec3 const& u, Vec3 const& v) { return { u.x() - v.x(), u.y() - v.y(), u.z() - v.z() }; }
    friend Vec3 operator*(Vec3 const& u, Vec3 const& v) { return { u.x() * v.x(), u.y() * v.y(), u.z() * v.z() }; }
    friend Vec3 operator*(double const t, Vec3 const& v) { return { t * v.x(), t * v.y(), t * v.z() }; }
    friend Vec3 operator*(Vec3 const& v, double const t) { return t * v; }
    friend Vec3 operator/(Vec3 v, double const t) { return (1 / t) * v; }
    friend Vec3 unit_vector(Vec3 v) { return v / v.length(); }

    friend constexpr double dot(Vec3 const& u, Vec3 const& v)
    {
        return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
    }

    friend Vec3 cross(Vec3 const& u, Vec3 const& v)
    {
        return { u.y() * v.z() - u.z() * v.y(),
            u.z() * v.x() - u.x() * u.z(),
            u.x() * v.y() - u.y() * v.x() };
    }

    inline static Vec3 random() { return Vec3(random_double(), random_double(), random_double()); }
    inline static Vec3 random(double min, double max) { return Vec3(random_double(min, max), random_double(min, max), random_double(min, max)); }

    static Vec3 random_in_unit_sphere();
    static Vec3 random_unit_vector();


private:
    double m_x;
    double m_y;
    double m_z;
};

using Point3 = Vec3;
using Color = Vec3;
