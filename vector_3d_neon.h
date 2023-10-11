#ifndef VECTOR_3D_NEON_H_
#define VECTOR_3D_NEON_H_

#ifdef __ARM_NEON
#ifdef __aarch64__
#include "arm_neon.h"
#include <cmath>

struct vector_3d_neon {
    float32x4_t xyz;

    vector_3d_neon() { xyz = vdupq_n_f32(0.0); }
    vector_3d_neon(const vector_3d_neon& other) = default;
    vector_3d_neon(float x, float y, float z) {
        const float32_t data[4] = {x, y, z, 0.0};
        xyz = vld1q_f32(data);
    }

    ~vector_3d_neon() = default;

    static vector_3d_neon zero() { return vector_3d_neon{}; }
    static vector_3d_neon one() { return vector_3d_neon{1.0f, 1.0f, 1.0f}; }

    float x() const { return vgetq_lane_f32(xyz, 0); }
    void set_x(float x) { xyz = vsetq_lane_f32(x, xyz, 0); }

    float y() const { return vgetq_lane_f32(xyz, 1); }
    void set_y(float y) { xyz = vsetq_lane_f32(y, xyz, 1); }

    float z() const { return vgetq_lane_f32(xyz, 2); }
    void set_z(float z) { xyz = vsetq_lane_f32(z, xyz, 2); }

    vector_3d_neon& operator+=(const vector_3d_neon& other) {
        xyz = vaddq_f32(xyz, other.xyz);
        return *this;
    }

    vector_3d_neon operator+(const vector_3d_neon& other) const {
        return vector_3d_neon(vaddq_f32(xyz, other.xyz));
    }

    vector_3d_neon& operator-=(const vector_3d_neon& other) {
        xyz = vsubq_f32(xyz, other.xyz);
        return *this;
    }

    vector_3d_neon operator-(const vector_3d_neon& other) const {
        return vector_3d_neon(vsubq_f32(xyz, other.xyz));
    }

    vector_3d_neon& operator*=(float scalar) {
        xyz = vmulq_n_f32(xyz, scalar);
        return *this;
    }

    vector_3d_neon operator*(float scalar) const {
        return vector_3d_neon(vmulq_n_f32(xyz, scalar));
    }

    vector_3d_neon& operator*=(const vector_3d_neon& other) {
        xyz = vmulq_f32(xyz, other.xyz);
        return *this;
    }

    vector_3d_neon operator*(const vector_3d_neon& other) const {
        return vector_3d_neon(vmulq_f32(xyz, other.xyz));
    }

    vector_3d_neon& operator/=(float scalar) {
        xyz = vmulq_n_f32(xyz, 1.0f / scalar);
        return *this;
    }

    vector_3d_neon operator/(float scalar) const {
        return vector_3d_neon(vmulq_n_f32(xyz, 1.0f / scalar));
    }

    vector_3d_neon& operator/=(const vector_3d_neon& other) {
        xyz = vdivq_f32(xyz, other.xyz);
        return *this;
    }

    vector_3d_neon operator/(const vector_3d_neon& other) const {
        return vector_3d_neon(vdivq_f32(xyz, other.xyz));
    }

    float dot(const vector_3d_neon& other) const {
        return vaddvq_f32(vmulq_f32(xyz, other.xyz));
    }

    float magnitude() const {
        return sqrtf(vaddvq_f32(vmulq_f32(xyz, xyz)));
    }

    vector_3d_neon normalize() const {
        return *this / magnitude();
    }

    vector_3d_neon& normalize() {
        *this /= magnitude();
        return *this;
    }

private:
    vector_3d_neon(float32x4_t xyz) : xyz(xyz) {}
};

#endif // __aarch64__
#endif // __ARM_NEON
#endif // VECTOR_3D_NEON_H_