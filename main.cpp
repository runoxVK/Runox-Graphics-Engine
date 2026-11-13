#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <algorithm>
#include <iostream>
//https://raytracing.github.io/ <- Book being followed

// Gradient of white-->blue depending on y (see document for derivation)
color ray_color(const ray& r){
    vec3 unit_direction = unit_vector(r.direction());

    //a as a function of y where 0<a<1 (white < a < blue)
    auto a = 0.5*(unit_direction.y()+1);

    // Lerp Formula
    return ((1-a)*color(1,1,1) + a*color(0.5,0.7,1.0));
}


int main (){

    //Image Parameters
    auto aspect_ratio = 16.0/9.0;
    int image_width = 256;

    // Calculate Height based on aspect ratio
    int image_height = int(image_width/aspect_ratio);

    if (image_height < 1)
        image_height = 1;

    // Viewport
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width/image_height)); // Same idea as height * aspect ratio to get width but we are using actual fraction cus the aspect ratio rounds

    // Camera
    auto focal_length = 1.0;
    auto camera_center = point3(0,0,0);

    // Calculate viewport horizontal and vertical vectors that help navigate pixel grid
    auto viewport_u = vec3(viewport_width,0,0);
    auto viewport_v = vec3(0,-viewport_height,0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u/image_width;
    auto pixel_delta_v = viewport_v/image_height;

    // Calculate Location of Upper left pixel (Q)

    auto viewport_upper_left = camera_center - vec3(0,0,focal_length) - viewport_u/2 - viewport_v/2;

    auto pixel100_loc = viewport_upper_left + (0.5*(pixel_delta_u + pixel_delta_v));

    // Render Image
    // We want the image to be in PPM format

    // PPM Header:
    // P3 means colors are in ASCII (PPM Format Declaration), followed by image_width columns and image_height rows and then 255 for max color (See PPM format: https://en.wikipedia.org/wiki/Netpbm)
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";


    // The PPM format/declaration must be followed by RGB triplets which per pixel. Each pixel has three RGB values
    // Iterate through each pixel and define each pixels R, G and B
    // For this image we'll run a gradient based on the pixel position
    for (int j = 0; j < image_height; j++){
        // Progress Indicator (clog = output stream for logging messages, flush = ensures output is displayed immediately) -> Clog and flush combo is useful for message logging
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for(int i = 0; i < image_width; i++){

            auto pixel_center = (pixel100_loc + (i*pixel_delta_u) + (j*pixel_delta_v));
            auto ray_direction = pixel_center-camera_center;

            ray r(camera_center, ray_direction);

            color pixel_color =  ray_color(r);
            write_color(std::cout, pixel_color);

        }
    }

    std::clog << "\rDone.                       \n";

}

//g++ main.cpp -o inOneWeekend -> to Compile
//cmd /c "inOneWeekend.exe > image.ppm" -> To generate ppm
