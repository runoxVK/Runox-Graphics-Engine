#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>
#include <ostream>

// Color and a vector 3 are one in the same
using color = vec3;

// Constructor for a color
void write_color(std::ostream& out, const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate color values to the byte range [0,255]
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write the pixel components
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif
