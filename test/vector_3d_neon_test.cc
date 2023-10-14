#include "vector_3d_neon.h"
#include "gtest/gtest.h"

TEST(Vector3DNeon, DefaultConstructor) {
    vector_3d_neon a;
    EXPECT_FLOAT_EQ(a.x(), 0.0f);
    EXPECT_FLOAT_EQ(a.y(), 0.0f);
    EXPECT_FLOAT_EQ(a.z(), 0.0f);
}

TEST(Vector3DNeon, CopyConstructor) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{a};
    EXPECT_FLOAT_EQ(b.x(), 1.0f);
    EXPECT_FLOAT_EQ(b.y(), 2.0f);
    EXPECT_FLOAT_EQ(b.z(), 3.0f);
}

TEST(Vector3DNeon, XYZContructor) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    EXPECT_FLOAT_EQ(a.x(), 1.0f);
    EXPECT_FLOAT_EQ(a.y(), 2.0f);
    EXPECT_FLOAT_EQ(a.z(), 3.0f);
}

TEST(Vector3DNeon, ZeroOneConstructors) {
    vector_3d_neon a = vector_3d_neon::zero();
    EXPECT_FLOAT_EQ(a.x(), 0.0f);
    EXPECT_FLOAT_EQ(a.y(), 0.0f);
    EXPECT_FLOAT_EQ(a.z(), 0.0f);

    vector_3d_neon b = vector_3d_neon::one();
    EXPECT_FLOAT_EQ(b.x(), 1.0f);
    EXPECT_FLOAT_EQ(b.y(), 1.0f);
    EXPECT_FLOAT_EQ(b.z(), 1.0f);
}

TEST(Vector3DNeon, Subscript) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    EXPECT_FLOAT_EQ(a.x(), 1.0f);
    EXPECT_FLOAT_EQ(a.y(), 2.0f);
    EXPECT_FLOAT_EQ(a.z(), 3.0f);

    a.set_x(4.0);
    EXPECT_FLOAT_EQ(a.x(), 4.0f);
    
    a.set_y(5.0);
    EXPECT_FLOAT_EQ(a.y(), 5.0f);

    a.set_z(6.0);
    EXPECT_FLOAT_EQ(a.z(), 6.0f);
}

TEST(Vector3DNeon, AdditionAssignment) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    a += b;
    EXPECT_FLOAT_EQ(a.x(), 5.0f);
    EXPECT_FLOAT_EQ(a.y(), 7.0f);
    EXPECT_FLOAT_EQ(a.z(), 9.0f);
}

TEST(Vector3DNeon, SubtractionAssignment) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    a -= b;
    EXPECT_FLOAT_EQ(a.x(), -3.0f);
    EXPECT_FLOAT_EQ(a.y(), -3.0f);
    EXPECT_FLOAT_EQ(a.z(), -3.0f);
}

TEST(Vector3DNeon, MultiplicationAssignmentScalar) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    a *= 2.0f;
    EXPECT_FLOAT_EQ(a.x(), 2.0f);
    EXPECT_FLOAT_EQ(a.y(), 4.0f);
    EXPECT_FLOAT_EQ(a.z(), 6.0f);
}

TEST(Vector3DNeon, MultiplicationAssignmentVector) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    a *= b;
    EXPECT_FLOAT_EQ(a.x(), 4.0f);
    EXPECT_FLOAT_EQ(a.y(), 10.0f);
    EXPECT_FLOAT_EQ(a.z(), 18.0f);
}

TEST(Vector3DNeon, DivisionAssignmentScalar) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    a /= 2.0f;
    EXPECT_FLOAT_EQ(a.x(), 0.5f);
    EXPECT_FLOAT_EQ(a.y(), 1.0f);
    EXPECT_FLOAT_EQ(a.z(), 1.5f);
}

TEST(Vector3DNeon, DivisionAssignmentVector) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    a /= b;
    EXPECT_FLOAT_EQ(a.x(), 0.25f);
    EXPECT_FLOAT_EQ(a.y(), 0.4f);
    EXPECT_FLOAT_EQ(a.z(), 0.5f);
}

TEST(Vector3DNeon, DotProduct) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    EXPECT_FLOAT_EQ(a.dot(b), 32.0f);
}

TEST(Vector3DNeon, Addition) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    vector_3d_neon c = a + b;
    EXPECT_FLOAT_EQ(c.x(), 5.0f);
    EXPECT_FLOAT_EQ(c.y(), 7.0f);
    EXPECT_FLOAT_EQ(c.z(), 9.0f);
}

TEST(Vector3DNeon, Subtraction) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    vector_3d_neon c = a - b;
    EXPECT_FLOAT_EQ(c.x(), -3.0f);
    EXPECT_FLOAT_EQ(c.y(), -3.0f);
    EXPECT_FLOAT_EQ(c.z(), -3.0f);
}

TEST(Vector3DNeon, MultiplicationScalar) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b = a * 2.0f;
    EXPECT_FLOAT_EQ(b.x(), 2.0f);
    EXPECT_FLOAT_EQ(b.y(), 4.0f);
    EXPECT_FLOAT_EQ(b.z(), 6.0f);
}

TEST(Vector3DNeon, MultiplicationVector) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    vector_3d_neon c = a * b;
    EXPECT_FLOAT_EQ(c.x(), 4.0f);
    EXPECT_FLOAT_EQ(c.y(), 10.0f);
    EXPECT_FLOAT_EQ(c.z(), 18.0f);
}

TEST(Vector3DNeon, DivisionScalar) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b = a / 2.0f;
    EXPECT_FLOAT_EQ(b.x(), 0.5f);
    EXPECT_FLOAT_EQ(b.y(), 1.0f);
    EXPECT_FLOAT_EQ(b.z(), 1.5f);
}

TEST(Vector3DNeon, DivisionVector) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    vector_3d_neon c = a / b;
    EXPECT_FLOAT_EQ(c.x(), 0.25f);
    EXPECT_FLOAT_EQ(c.y(), 0.4f);
    EXPECT_FLOAT_EQ(c.z(), 0.5f);
}

TEST(Vector3DNeon, Magnitude) {
    vector_3d_neon a{0.0f, 3.0f, 4.0f};
    EXPECT_FLOAT_EQ(a.magnitude(), 5.0);
}

TEST(Vector3DNeon, Normalize) {
    vector_3d_neon a{0.0f, 3.0f, 4.0f};
    a.normalize();
    EXPECT_FLOAT_EQ(a.x(), 0.0f);
    EXPECT_FLOAT_EQ(a.y(), 0.6f);
    EXPECT_FLOAT_EQ(a.z(), 0.8f);
}

TEST(Vector3DNeon, Cross) {
    vector_3d_neon a{1.0f, 2.0f, 3.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    vector_3d_neon c = a.cross(b);
    EXPECT_FLOAT_EQ(c.x(), -3.0f);
    EXPECT_FLOAT_EQ(c.y(), 6.0f);
    EXPECT_FLOAT_EQ(c.z(), -3.0f);
}

TEST(Vector3DNeon, Angle) {
    vector_3d_neon a{1.0f, 0.0f, 0.0f};
    vector_3d_neon b{0.0f, 1.0f, 0.0f};
    EXPECT_FLOAT_EQ(a.angle(b), M_PI / 2.0f);
    EXPECT_FLOAT_EQ(a.angle(-a), M_PI);
    EXPECT_FLOAT_EQ(a.angle(a), 0.0f);
}

TEST(Vector3DNeon, Projection) {
    vector_3d_neon a{1.0f, 0.0f, 0.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    vector_3d_neon c = b.projection(a);
    EXPECT_FLOAT_EQ(c.x(), 4.0f);
    EXPECT_FLOAT_EQ(c.y(), 0.0f);
    EXPECT_FLOAT_EQ(c.z(), 0.0f);
}

TEST(Vector3DNeon, Rejection) {
    vector_3d_neon a{1.0f, 0.0f, 0.0f};
    vector_3d_neon b{4.0f, 5.0f, 6.0f};
    vector_3d_neon c = b.rejection(a);
    EXPECT_FLOAT_EQ(c.x(), 0.0);
    EXPECT_FLOAT_EQ(c.y(), 5.0f);
    EXPECT_FLOAT_EQ(c.z(), 6.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}