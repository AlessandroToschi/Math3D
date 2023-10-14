#ifndef VECTOR_3D_H_
#define VECTOR_3D_H_

#include <cmath>

struct vector_3d {
    float x, y, z;

    vector_3d(): x{0.0f}, y{0.0f}, z{0.0f} {}
    vector_3d(const vector_3d& other) = default;
    vector_3d(float x, float y, float z): x{x}, y{y}, z{z} {}

    ~vector_3d() = default;

    static vector_3d zero() { return vector_3d(0.0f, 0.0f, 0.0f); }
    static vector_3d one() { return vector_3d(1.0f, 1.0f, 1.0f); }

    float& operator[](int i) { return (&x)[i]; }
    float operator[](int i) const { return (&x)[i]; }

    inline vector_3d operator+(const vector_3d& rhs) const {
        return vector_3d{x + rhs.x, y + rhs.y, z + rhs.z};
    }

    inline vector_3d operator-(const vector_3d& rhs) const {
        return vector_3d{x - rhs.x, y - rhs.y, z - rhs.z};
    }

    inline vector_3d operator-() const {
        return vector_3d{-x, -y, -z};
    }

    inline vector_3d operator*(float scalar) const {
        return vector_3d{x * scalar, y * scalar, z * scalar};
    }

    inline vector_3d operator*(const vector_3d& rhs) const {
        return vector_3d{x * rhs.x, y * rhs.y, z * rhs.z};
    }

    inline vector_3d operator/(float scalar) const {
        return vector_3d{x / scalar, y / scalar, z / scalar};
    }

    inline vector_3d operator/(const vector_3d& rhs) const {
        return vector_3d{x / rhs.x, y / rhs.y, z / rhs.z};
    }

    vector_3d& operator+=(const vector_3d& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    vector_3d& operator-=(const vector_3d& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    vector_3d& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    vector_3d& operator*=(const vector_3d& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    vector_3d& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    vector_3d& operator/=(const vector_3d& other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    float dot(const vector_3d& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    float magnitude() const {
        return sqrtf(x * x + y * y + z * z);
    }

    vector_3d& normalize() {
        const float mag = magnitude();
        x /= mag;
        y /= mag;
        z /= mag;
        return *this;
    }

    vector_3d normalize() const {
        const float mag = magnitude();
        return vector_3d{x / mag, y / mag, z / mag};
    }

    vector_3d cross(const vector_3d& other) const {
        return vector_3d{
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        };
    }
    
    float angle(const vector_3d& other) const {
        return acosf(dot(other) / (magnitude() * other.magnitude()));
    }

    vector_3d projection(const vector_3d& other) const {
        return other * (dot(other) / other.dot(other));
    }

    vector_3d rejection(const vector_3d& other) const {
        return  *this - projection(other);
    }
};

#endif // VECTOR_3D_H_
