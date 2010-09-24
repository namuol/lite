#ifndef _VECTOR2_H_
#define _VECTOR2_H_

class Vector2 {
public:
    Vector2();
    Vector2(const Vector2& other);
    Vector2(double x, double y);

    ~Vector2();
    
    Vector2& operator=(const Vector2& other);

    friend const Vector2 operator*(const Vector2& left, double scalar);
    friend const Vector2 operator*(double scalar, const Vector2& right);

    friend const Vector2 operator/(const Vector2& left, double scalar);

    friend const Vector2 operator-(const Vector2& left);

    friend const Vector2 operator+(const Vector2& left, const Vector2& right);
    Vector2& operator+=(const Vector2& other);

    friend const Vector2 operator-(const Vector2& left, const Vector2& right);
    Vector2& operator-=(const Vector2& other);

    static double dot(const Vector2& left, const Vector2& right);
    static const Vector2 lerp(const Vector2& p0, const Vector2& p1, double u);
    
    double magnitude() const;
    Vector2& normalize();

    friend Vector2 normalized(const Vector2& vec);

    double x, y;
};

#endif
