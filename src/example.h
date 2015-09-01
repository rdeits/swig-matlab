#include <iostream>
#include <Eigen/Core>

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

  Eigen::MatrixXd gcdPlusXMatrix(Eigen::MatrixXd y, Eigen::MatrixXd z) {
    Eigen::MatrixXd result(y.rows(), y.cols());
    for (Eigen::DenseIndex i=0; i < y.rows(); i++) {
      for (Eigen::DenseIndex j=0; j < y.cols(); j++) {
        result(i,j) = this->gcdPlusX(y(i,j), z(i,j));
      }
    }
    return result;
  }

  ~GCDPlusX() {
    std::cout << "destructing object at address: " << this << std::endl;
  }
};
