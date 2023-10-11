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
};

inline vector_3d operator+(const vector_3d& lhs, const vector_3d& rhs) {
    return vector_3d{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

inline vector_3d operator-(const vector_3d& lhs, const vector_3d& rhs) {
    return vector_3d{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

inline vector_3d operator*(const vector_3d& lhs, float scalar) {
    return vector_3d{lhs.x * scalar, lhs.y * scalar, lhs.z * scalar};
}

inline vector_3d operator*(float scalar, const vector_3d& rhs) {
    return vector_3d{rhs.x * scalar, rhs.y * scalar, rhs.z * scalar};
}

inline vector_3d operator*(const vector_3d& lhs, const vector_3d& rhs) {
    return vector_3d{lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

inline vector_3d operator/(const vector_3d& lhs, float scalar) {
    return vector_3d{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar};
}

inline vector_3d operator/(const vector_3d& lhs, const vector_3d& rhs) {
    return vector_3d{lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

#endif // VECTOR_3D_H_
