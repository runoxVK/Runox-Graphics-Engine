#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray{
    public:

        // Constructors
        ray(){}

        // ray(...): ... is an initializer which was explained in vec3
        ray(const point3& origin, const vec3& direction): orig(origin), dir(direction){}

        // Accesors
        const point3& origin() const{
            return orig;
        }

        // const before indicates that the return type is a const
        // const after means it doesnt modify the object its being called on (in this case the ray)
        const vec3& direction() const{
            return dir;
        }

        // Ray definition: P(t) = A + bt
        //      A = Origin
        //      b = direction
        //      t = parameter to pick a point on the line
        point3 at(double t) const{
            return orig + t*dir;
        }

    private:
        point3 orig;
        vec3 dir;


};

#endif
