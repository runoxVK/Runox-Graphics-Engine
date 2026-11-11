// Header Guards (If VEC3_H is not defined then go ahead and define it) -> Prevents repeat declarations
#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3{
    public:
        // Vector Array
        // If I want to set 3 values for the array I can say V = e[3]{1,2,3} and that will make the array [1,2,3]
        double e[3];

        // Constructors:
        // We are using initializer lists instead of the typical constructor function
        // The array is initialized directly rather than assigned inside the body. The {} at the end is an empty constructor body
        // What it would do without this is initialize an array and allocate memory for that array without having any value in it and THEN assign the values in the constructor body.
        // This way is just more efficient because it instantly sets the values rather than bringing forth garbage and then replacing it
        vec3(): e{0,0,0} {}
        vec3(double e1, double e2, double e3): e{e1,e2,e3} {}

        // Accesors (To get individual components)
        double x() const{
            return e[0];
        }

        double y() const{
            return e[1];
        }

        double z() const{
            return e[2];
        }

        // Flipping Operator
        // operator- is essentially a function where if I have w = vec3() and I say -w then it will run this function and basically flip the direction of the vector
        // It returns a NEW vector
        vec3 operator-() const{
            return vec3(-e[0], -e[1], -e[2]);
        }

        // Indexing
        // Defines what [] would be -> Instead of having to write v.e[1] to access index one we could just write v[1]
        double operator[](int i) const{ // This is for read only vectors (const) and returns what the value is at that index
            return e[i]
        }


        double& operator[] (int i){ // This is for vectors that you can actually write into and literally sets that index value to what you want by direcctly changing the data at its address
            return e[i];            // We are using & to directly access the vector component in memory.
        }

}





#endif
