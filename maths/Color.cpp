#include "Color.h"

void write_color(std::ostream& out, Color pixel_color)
{
    // write (0, 255) value of each pixel_color component
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}
