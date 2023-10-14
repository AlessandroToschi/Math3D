#include "vector_3d.h"
#include "gtest/gtest.h"

TEST(Vector3D, DefaultConstructor) {
    vector_3d a;
    EXPECT_FLOAT_EQ(a.x, 0.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
}

TEST(Vector3D, CopyConstructor) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{a};
    EXPECT_FLOAT_EQ(b.x, 1.0f);
    EXPECT_FLOAT_EQ(b.y, 2.0f);
    EXPECT_FLOAT_EQ(b.z, 3.0f);
}

TEST(Vector3D, XYZContructor) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 2.0f);
    EXPECT_FLOAT_EQ(a.z, 3.0f);
}

TEST(Vector3D, ZeroOneConstructors) {
    vector_3d a = vector_3d::zero();
    EXPECT_FLOAT_EQ(a.x, 0.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);

    vector_3d b = vector_3d::one();
    EXPECT_FLOAT_EQ(b.x, 1.0f);
    EXPECT_FLOAT_EQ(b.y, 1.0f);
    EXPECT_FLOAT_EQ(b.z, 1.0f);
}

TEST(Vector3D, Subscript) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    EXPECT_FLOAT_EQ(a[0], 1.0f);
    EXPECT_FLOAT_EQ(a[1], 2.0f);
    EXPECT_FLOAT_EQ(a[2], 3.0f);

    a[0] = 4.0f;
    EXPECT_FLOAT_EQ(a[0], 4.0f);
    
    a[1] = 5.0f;
    EXPECT_FLOAT_EQ(a[1], 5.0f);

    a[2] = 6.0f;
    EXPECT_FLOAT_EQ(a[2], 6.0f);
}

TEST(Vector3D, AdditionAssignment) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    a += b;
    EXPECT_FLOAT_EQ(a.x, 5.0f);
    EXPECT_FLOAT_EQ(a.y, 7.0f);
    EXPECT_FLOAT_EQ(a.z, 9.0f);
}

TEST(Vector3D, SubtractionAssignment) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    a -= b;
    EXPECT_FLOAT_EQ(a.x, -3.0f);
    EXPECT_FLOAT_EQ(a.y, -3.0f);
    EXPECT_FLOAT_EQ(a.z, -3.0f);
}

TEST(Vector3D, MultiplicationAssignmentScalar) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    a *= 2.0f;
    EXPECT_FLOAT_EQ(a.x, 2.0f);
    EXPECT_FLOAT_EQ(a.y, 4.0f);
    EXPECT_FLOAT_EQ(a.z, 6.0f);
}

TEST(Vector3D, MultiplicationAssignmentVector) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    a *= b;
    EXPECT_FLOAT_EQ(a.x, 4.0f);
    EXPECT_FLOAT_EQ(a.y, 10.0f);
    EXPECT_FLOAT_EQ(a.z, 18.0f);
}

TEST(Vector3D, DivisionAssignmentScalar) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    a /= 2.0f;
    EXPECT_FLOAT_EQ(a.x, 0.5f);
    EXPECT_FLOAT_EQ(a.y, 1.0f);
    EXPECT_FLOAT_EQ(a.z, 1.5f);
}

TEST(Vector3D, DivisionAssignmentVector) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    a /= b;
    EXPECT_FLOAT_EQ(a.x, 0.25f);
    EXPECT_FLOAT_EQ(a.y, 0.4f);
    EXPECT_FLOAT_EQ(a.z, 0.5f);
}

TEST(Vector3D, DotProduct) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    EXPECT_FLOAT_EQ(a.dot(b), 32.0f);
}

TEST(Vector3D, Addition) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    vector_3d c = a + b;
    EXPECT_FLOAT_EQ(c.x, 5.0f);
    EXPECT_FLOAT_EQ(c.y, 7.0f);
    EXPECT_FLOAT_EQ(c.z, 9.0f);
}

TEST(Vector3D, Subtraction) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    vector_3d c = a - b;
    EXPECT_FLOAT_EQ(c.x, -3.0f);
    EXPECT_FLOAT_EQ(c.y, -3.0f);
    EXPECT_FLOAT_EQ(c.z, -3.0f);
}

TEST(Vector3D, MultiplicationScalar) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b = a * 2.0f;
    EXPECT_FLOAT_EQ(b.x, 2.0f);
    EXPECT_FLOAT_EQ(b.y, 4.0f);
    EXPECT_FLOAT_EQ(b.z, 6.0f);
}

TEST(Vector3D, MultiplicationVector) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    vector_3d c = a * b;
    EXPECT_FLOAT_EQ(c.x, 4.0f);
    EXPECT_FLOAT_EQ(c.y, 10.0f);
    EXPECT_FLOAT_EQ(c.z, 18.0f);
}

TEST(Vector3D, DivisionScalar) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b = a / 2.0f;
    EXPECT_FLOAT_EQ(b.x, 0.5f);
    EXPECT_FLOAT_EQ(b.y, 1.0f);
    EXPECT_FLOAT_EQ(b.z, 1.5f);
}

TEST(Vector3D, DivisionVector) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    vector_3d c = a / b;
    EXPECT_FLOAT_EQ(c.x, 0.25f);
    EXPECT_FLOAT_EQ(c.y, 0.4f);
    EXPECT_FLOAT_EQ(c.z, 0.5f);
}

TEST(Vector3D, Magnitude) {
    vector_3d a{0.0f, 3.0f, 4.0f};
    EXPECT_FLOAT_EQ(a.magnitude(), 5.0);
}

TEST(Vector3D, Normalize) {
    vector_3d a{0.0f, 3.0f, 4.0f};
    a.normalize();
    EXPECT_FLOAT_EQ(a.x, 0.0f);
    EXPECT_FLOAT_EQ(a.y, 0.6f);
    EXPECT_FLOAT_EQ(a.z, 0.8f);
}

TEST(Vector3D, Cross) {
    vector_3d a{1.0f, 2.0f, 3.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    vector_3d c = a.cross(b);
    EXPECT_FLOAT_EQ(c.x, -3.0f);
    EXPECT_FLOAT_EQ(c.y, 6.0f);
    EXPECT_FLOAT_EQ(c.z, -3.0f);
}

TEST(Vector3D, Angle) {
    vector_3d a{1.0f, 0.0f, 0.0f};
    vector_3d b{0.0f, 1.0f, 0.0f};
    EXPECT_FLOAT_EQ(a.angle(b), M_PI / 2.0f);
    EXPECT_FLOAT_EQ(a.angle(-a), M_PI);
    EXPECT_FLOAT_EQ(a.angle(a), 0.0f);
}

TEST(Vector3D, Projection) {
    vector_3d a{1.0f, 0.0f, 0.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    vector_3d c = b.projection(a);
    EXPECT_FLOAT_EQ(c.x, 4.0f);
    EXPECT_FLOAT_EQ(c.y, 0.0f);
    EXPECT_FLOAT_EQ(c.z, 0.0f);
}

TEST(Vector3D, Rejection) {
    vector_3d a{1.0f, 0.0f, 0.0f};
    vector_3d b{4.0f, 5.0f, 6.0f};
    vector_3d c = a.rejection(b);
    EXPECT_FLOAT_EQ(c.x, -3.0);
    EXPECT_FLOAT_EQ(c.y, -5.0f);
    EXPECT_FLOAT_EQ(c.z, -6.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}