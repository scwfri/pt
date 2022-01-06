#include <iostream>

#include "maths/Color.h"
#include "maths/Vec3.h"

int main()
{
    int const image_width = 256;
    int const image_height = 256;

    std::cout << "P3\n"
              << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.25;

            Color pixel_color = { r, g, b };
            write_color(std::cout, pixel_color);
        }
    }
}
