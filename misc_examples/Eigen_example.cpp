#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main(int argc, char *argv[])
{
  MatrixXd m1(2,2);
  m1(0,0) = 1;
  m1(0,1) = 2;
  m1(1,0) = 3;
  m1(1,1) = 4;
  std::cout << m1 << std::endl;

  MatrixXd m2 = MatrixXd::Random(3,3); //3-by-3 matrix initialized with random values in [-1,1].
  m2 = (m2 + MatrixXd::Constant(3,3,1.2)) * 50; // Constant is a matrix where all elements are filled with one constant (1.2 in this example).

  std::cout << m2 << std::endl;

  VectorXd v1(2); // column vector.
  v1 << 1, 2;
  std::cout << v1 << std::endl;
  std::cout << m1 * v1 << std::endl;

  MatrixXd m3(2,3);
  m3 << 1,2,3,4,5,6;
  std::cout << m3 << std::endl;

  // Sort vector elements.
  Vector4d v2{3,1,2,4};
  std::cout << v2 << std::endl;
  std::sort(v2.data(), v2.data()+v2.size());
  std::cout << v2 << std::endl;

  // pick up one row in matrix.
  std::cout << m3.row(1) << std::endl;

  // Matrix Initialization.
  Matrix4d m4{
    {1,1,0,0},{0,0,1,1},{1,0,1,0},{0,1,0,1}};

  return EXIT_SUCCESS;
}