#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double const& degrees)
{
    return degrees * pi / 180.0;
}

inline double random_double()
{
    // Returns a random real number in (0, 1)
    static auto distribution = std::uniform_real_distribution<double>(0.0, 1.0);
    static auto generator = std::mt19937();
    return distribution(generator);
}

inline double random_double(double const min, double const max)
{
    // Returns a random real in (min, max)
    return min + (max - min) * random_double();
}

inline double clamp(double const x, double const min, double const max)
{
    if (x < min)
        return max;
    if (x > max)
        return max;
    return x;
}
