#include <iostream>

#include "maths/Color.h"
#include "maths/Vec3.h"
#include "ray/Ray.h"

bool hit_sphere(Point3 const& center, double const radius, Ray const& r)
{
    Vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

Color ray_color(Ray const& r)
{
    if (hit_sphere(Point3(0, 0, -1), 0.5, r))
        return Color(1, 0, 0);

    Vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main()
{
    // image
    const auto aspect_ratio = 16.0 / 9.0;
    int const image_width = 400;
    int const image_height = static_cast<int>(image_width / aspect_ratio);

    // camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = Point3(0, 0, 0);
    auto horizontal = Vec3(viewport_width, 0, 0);
    auto vertical = Vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focal_length);

    std::cout << "P3\n";
    std::cout << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            // auto r = double(i) / (image_width - 1);
            // auto g = double(j) / (image_height - 1);
            // auto b = 0.25;

            // Color pixel_color = { r, g, b };
            // write_color(std::cout, pixel_color);

            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            Color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
}
