#include "Color.h"

void write_color(std::ostream& out, Color const& pixel_color, int samples_per_pixel)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    //std::cerr << "samples per pixel: " << samples_per_pixel << "\n";
    auto scale = 1.0 / samples_per_pixel;
    r *= sqrt(scale * r);
    g *= sqrt(scale * g);
    b *= sqrt(scale * b);

#ifdef COLOR_DEBUG
    std::cerr << "scale: " << scale << "\n";
    std::cerr << "r: " << pixel_color.x() << " => " << r << "\n";
    std::cerr << "g: " << pixel_color.y() << " => " << g << "\n";
    std::cerr << "b: " << pixel_color.z() << " => " << b << "\n";
#endif // COLOR_DEBUG

    //std::cerr << "r: " << r << " g: " << g << " b: " << b << "\n";
    // write (0, 255) value of each pixel_color component
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}
