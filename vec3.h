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
            return e[i];
        }


        double& operator[] (int i){  // This is for vectors that you can actually write into and literally sets that index value to what you want by direcctly changing the data at its address
            return e[i];            // We are using & to directly access the vector component in memory.
        }

        // Add to Self Operator (a += v adds vector v onto a)
        vec3& operator+=(const vec3& v){  // The reason the input is a const vec3& is because its more efficient to directly access that vector in memory rather than make a copy of it (const ma                                                   kes it read only)
            e[0] = e[0] + v.e[0];
            e[1] = e[1] + v.e[1];
            e[2] = e[2] + v.e[2];
            return *this;
        }

        //Multiply to Self Operator
        vec3& operator*=(double t){
            e[0] = e[0] * t;
            e[1] = e[1] * t;
            e[2] = e[2] * t;
            return *this;
        }

        //Divide to Self Operator
        vec3& operator/=(double t){
            e[0] = e[0] * 1/t;
            e[1] = e[1] * 1/t;
            e[2] = e[2] * 1/t;
            return *this;
        }

        double length() const{
            return std::sqrt(length_squared());
        }

        double length_squared() const{
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        // point3 is just an alias for vec3, but useful for geometric clarity in the code.
        using point3 = vec3;


};

// Vector Utility Functions are gonna go outside the class because they involve using two vectors to make something new
// Anytime the vector being used "owns" the operation we can put it inside the class
// Inline basically means if this function exists in multiple files (via #include), tell the machine that the function is the same throughout the other files
// Inline is already added to every function inside the class but when we define functions outside we must manually add it

// This defines what the << means for a vector (Ex. std::cout << v would output the vectors components)
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v){
    return vec3(u[0]+v[0], u[1]+v[1], u[2]+v[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v){
    return vec3(u[0]-v[0], u[1]-v[1], u[2]-v[2]);
}

// Multiplication Operators
inline vec3 operator*(const vec3& u, const vec3& v){
    return vec3(u[0]*v[0], u[1]*v[1], u[2]*v[2]);
}

inline vec3 operator*(double t, const vec3& v){
    return vec3(t*v[0], t*v[1], t*v[2]);
}

// Putting this in case we flip the order it leads back to the original function
inline vec3 operator*(const vec3& v, double t){
    return t*v;
}

inline vec3 operator/(const vec3& v, double t){
    return ((1/t) * v);
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}


#endif
