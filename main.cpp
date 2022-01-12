#include <iostream>

#include "Maths/Utils.h"
#include "Maths/Color.h"
#include "Maths/Vec3.h"
#include "Ray/Ray.h"
#include "Hittable/Hittable.h"
#include "Hittable/HittableWrapper.h"
#include "Hittable/Sphere.h"

double hit_sphere(Point3 const& center, double const radius, Ray const& r)
{
    Vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
        return -1.0;
    else
        return (-half_b - sqrt(discriminant)) / a;
}

Color ray_color(Ray const& ray, Hittable& world)
{
    Hittable::HitRecord hit_record;
    if (world.hit(ray, 0, infinity, hit_record))
        return 0.5 * (hit_record.normal + Color(1.0, 1.0, 1.0));

    Vec3 unit_direction = unit_vector(ray.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main()
{
    // image
    const auto aspect_ratio = 16.0 / 9.0;
    int const image_width = 400;
    int const image_height = static_cast<int>(image_width / aspect_ratio);

    HittableWrapper world;
    world.add(std::make_shared<Sphere>(Point3(0.0, 0.0, -1.0), 0.5));
    world.add(std::make_shared<Sphere>(Point3(0.0, -100.5, -1.0), 100));

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
            Color pixel_color = ray_color(r, world);
            write_color(std::cout, pixel_color);
        }
    }
}
