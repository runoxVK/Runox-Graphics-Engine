#include <algorithm>
#include <iostream>
#include "vec3.h"
#include "color.h"


//https://raytracing.github.io/ <- Book being followed

int main (){


    //Image Parameters
    int image_width = 256;
    int image_height = 256;

    // Render Image
    // We want the image to be in PPM format

    // PPM Header:
    // P3 means colors are in ASCII (PPM Format Declaration), followed by image_width columns and image_height rows and then 255 for max color (See PPM format: https://en.wikipedia.org/wiki/Netpbm)
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";


    // The PPM format/declaration must be followed by RGB triplets which per pixel. Each pixel has three RGB values
    // Iterate through each pixel and define each pixels R, G and B
    // For this image we'll run a gradient based on the pixel position
    for (int j = 0; j < image_height; j++){
        for(int i = 0; i < image_width; i++){

            // Progress Indicator (clog = output stream for logging messages, flush = ensures output is displayed immediately) -> Clog and flush combo is useful for message logging
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

            // Defining the pixel color vector
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);

        }
    }

    std::sort(const RanIt First, const RanIt Last)

    std::clog << "\rDone.                       \n";

}

//g++ main.cpp -o inOneWeekend -> to Compile
//cmd /c "inOneWeekend.exe > image.ppm" -> To generate ppm
