#ifndef _VECTOR3_H_
#define _VECTOR3_H_

class Vector3 {
public:
    Vector3();
    Vector3(const Vector3& other);
    Vector3(double x, double y, double z);

    ~Vector3();
    
    Vector3& operator=(const Vector3& other);

    friend const Vector3 operator*(const Vector3& left, double scalar);
    friend const Vector3 operator*(double scalar, const Vector3& right);

    friend const Vector3 operator/(const Vector3& left, double scalar);

    friend const Vector3 operator-(const Vector3& left);

    friend const Vector3 operator+(const Vector3& left, const Vector3& right);
    Vector3& operator+=(const Vector3& other);

    friend const Vector3 operator-(const Vector3& left, const Vector3& right);
    Vector3& operator-=(const Vector3& other);

    static double dot(const Vector3& left, const Vector3& right);
    static const Vector3 lerp(const Vector3& p0, const Vector3& p1, double u);
    
    double magnitude() const;
    Vector3& normalize();

    friend Vector3 normalized(const Vector3& vec);

    double x, y, z;
};

#endif
