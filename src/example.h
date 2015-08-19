#include <iostream>

/* A global variable */
double Foo = 3.0;

/* Compute the greatest common divisor of positive integers */
int gcd(int x, int y);

class GCDPlusX {
public:
  GCDPlusX(int x=0):
    x(x) {
      std::cout << "constructing a new object with x = " << x << std::endl;
    }
  int x;

  int gcdPlusX(int y, int z) {
    return gcd(y, z) + x;
  }

  ~GCDPlusX() {
    std::cout << "destructing object at address: " << this << std::endl;
  }
};
