#include <iostream>

struct pippo {
  float x;

  pippo(): x{0.0f} {}
  pippo(float x): x{x} {}

  pippo permute(const pippo& other) {
    return *this * other;
  }

  pippo operator*(const pippo& rhs) {
    return pippo{x * rhs.x};
  }
};



int main(int argc, char **argv) {
  pippo a{3.0f};
  pippo b{2.0f};

  a.permute(b);

  a * b * a;

  return 0;
}