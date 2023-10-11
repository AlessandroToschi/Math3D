#include <iostream>

#if defined(__ARM_NEON) && defined(__aarch64__)
#include "vector_3d_neon.h"

int main(int argc, char** argv) {
  vector_3d_neon a(1.0f, 2.0f, 3.0f);
  vector_3d_neon b(4.0f, 5.0f, 6.0f);
  float c = a.dot(b);
  std::cout << c << "\n";

  return 0;
}

#endif