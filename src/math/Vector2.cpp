#include <cmath>
#include <cstdio>
#include <limits>

using namespace std;

#include "Vector2.h"

Vector2::Vector2()
{
    x = y = 0.f;
}

Vector2::Vector2(const Vector2& other)
{
    this->x = other.x;
    this->y = other.y;
}

Vector2::Vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector2::~Vector2() {
}

double Vector2::magnitude() const {
    return sqrt(x*x + y*y);
}

const Vector2& normalized(const Vector2& vec) { 
    double mag = sqrt(vec.x*vec.x + vec.y*vec.y);
    if( abs(mag) < numeric_limits<double>::epsilon() ) {
        return Vector2(0.0f,0.0f);
    }
    return Vector2(vec.x/mag, vec.y/mag); 
}

Vector2& Vector2::normalize() { 
    double mag = sqrt(x*x + y*y);
    if( abs(mag) < 10*numeric_limits<double>::epsilon() ) {
        x = 0.0f;
        y = 0.0f;
    } else {
        x /= mag;
        y /= mag;
    }
    return *this;
}

Vector2& Vector2::operator=(const Vector2& other) {
    if(this == &other)
        return *this;

    x = other.x;
    y = other.y;

    return *this; 
}

const Vector2 operator*(const Vector2& left, double scalar) {
    return Vector2(left.x*scalar, left.y*scalar);
}

const Vector2 operator*(double scalar, const Vector2& right) {
    return right * scalar;
}

const Vector2 operator/(const Vector2& left, double scalar) {
    return Vector2(left.x/scalar, left.y/scalar);
}

const Vector2 operator+(const Vector2& left, const Vector2& right) {
    return Vector2(left.x+right.x, left.y+right.y);
}

Vector2& Vector2::operator+=(const Vector2& other) {
    *this = *this + other;
    return *this;
}

const Vector2 operator-(const Vector2& left) {
    return Vector2(-left.x, -left.y);
}

const Vector2 operator-(const Vector2& left, const Vector2& right) {
    return Vector2(left.x-right.x, left.y-right.y);
}

Vector2& Vector2::operator-=(const Vector2& other) {
    *this = *this - other;
    return *this;
}

double Vector2::dot(const Vector2& left, const Vector2& right) {
    return left.x*right.x + left.y*right.y;
}

const Vector2 Vector2::lerp(const Vector2& p0, const Vector2& p1, double u) {
    return p0 + ((p1 - p0) * u); 

}
