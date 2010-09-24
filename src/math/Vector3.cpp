#include <cmath>
#include <cstdio>
#include <limits>

using namespace std;

#include "Vector3.h"

Vector3::Vector3()
{
    x = y = z = 0.f;
}

Vector3::Vector3(const Vector3& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

Vector3::Vector3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::~Vector3() {
}

double Vector3::magnitude() const {
    return sqrt(x*x + y*y + z*z);
}

Vector3 normalized(const Vector3& vec) { 
    double mag = sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
    if( abs(mag) < numeric_limits<double>::epsilon() ) {
        return Vector3(0.0f,0.0f,0.0f);
    }
    return Vector3(vec.x/mag, vec.y/mag, vec.z/mag); 
}

Vector3& Vector3::normalize() { 
    double mag = sqrt(x*x + y*y + z*z);
    if( abs(mag) < 10*numeric_limits<double>::epsilon() ) {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    } else {
        x /= mag;
        y /= mag;
        z /= mag;
    }
    return *this;
}

Vector3& Vector3::operator=(const Vector3& other) {
    if(this == &other)
        return *this;

    x = other.x;
    y = other.y;
    z = other.z;

    return *this; 
}

const Vector3 operator*(const Vector3& left, double scalar) {
    return Vector3(left.x*scalar, left.y*scalar, left.z*scalar);
}

const Vector3 operator*(double scalar, const Vector3& right) {
    return right * scalar;
}

const Vector3 operator/(const Vector3& left, double scalar) {
    return Vector3(left.x/scalar, left.y/scalar, left.z/scalar);
}

const Vector3 operator+(const Vector3& left, const Vector3& right) {
    return Vector3(left.x+right.x, left.y+right.y, left.z+right.z);
}

Vector3& Vector3::operator+=(const Vector3& other) {
    *this = *this + other;
    return *this;
}

const Vector3 operator-(const Vector3& left) {
    return Vector3(-left.x, -left.y, -left.z);
}

const Vector3 operator-(const Vector3& left, const Vector3& right) {
    return Vector3(left.x-right.x, left.y-right.y, left.z-right.z);
}

Vector3& Vector3::operator-=(const Vector3& other) {
    *this = *this - other;
    return *this;
}

double Vector3::dot(const Vector3& left, const Vector3& right) {
    return left.x*right.x + left.y*right.y + left.z*right.z;
}

const Vector3 Vector3::lerp(const Vector3& p0, const Vector3& p1, double u) {
    return p0 + ((p1 - p0) * u); 

}
