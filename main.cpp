#include <iostream>

#include "Camera/Camera.h"
#include "Hittable/Hittable.h"
#include "Hittable/HittableWrapper.h"
#include "Hittable/Sphere.h"
#include "Maths/Color.h"
#include "Maths/Utils.h"
#include "Maths/Vec3.h"
#include "Ray/Ray.h"

#define DEBUG

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

Color ray_color(Ray const& ray, Hittable& world, int depth)
{
    Hittable::HitRecord hit_record;
    if (depth <= 0)
        return Color(0.0, 0.0, 0.0);
    if (world.hit(ray, 0.001, infinity, hit_record)) {
        Point3 target = hit_record.point + hit_record.normal + Vec3::random_in_unit_sphere();
        return 0.5 * ray_color(Ray(hit_record.point, target - hit_record.point), world, depth - 1);
    }

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
    int const samples_per_pixel = 100;
    int const max_depth = 50;
    int const log_interval = 5;

    HittableWrapper world;
    world.add(std::make_shared<Sphere>(Point3(0.0, 0.0, -1.0), 0.5));
    world.add(std::make_shared<Sphere>(Point3(0.0, -100.5, -1.0), 100));

#ifdef DEBUG
    std::cerr << "---WORLD:---";
    auto world_objects = world.hittable_objects();
    for (auto it = world_objects.begin(); it != world_objects.end(); ++it)
        std::cerr << std::static_pointer_cast<Sphere>(*it)->center() << "\n";
    std::cerr << "---END WORLD---";
#endif // DEBUG

    std::cout << "P3\n";
    std::cout << image_width << ' ' << image_height << "\n255\n";

    std::cerr << "Generating Image...";
    Camera camera;
    for (int j = image_height - 1; j >= 0; --j) {
        if (j % log_interval == 0)
            std::cerr << "\nGenerating " << j << " of " << image_height - 1;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_color = Color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width - 1);
                auto v = (j + random_double()) / (image_height - 1);
                Ray ray = camera.get_ray(u, v);
#ifdef DEBUG
                std::cerr << "u: " << u << ", v: " << v << "\n";
                std::cerr << "ray.origin()[" << ray.origin() << "] ray.direction()[" << ray.direction() << "].\n";
                std::cerr << "pixel_color: " << pixel_color;
#endif // DEBUG
                pixel_color += ray_color(ray, world, max_depth);
#ifdef DEBUG
                std::cerr << " after: " << pixel_color << "\n";
#endif // DEBUG
            }
#ifdef DEBUG
            std::cerr << "pixel_color: " << pixel_color << "\n";
            exit(1);
#endif // DEBUG
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << "\nFinished...\n";
}
