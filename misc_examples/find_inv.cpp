#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main(int argc, char *argv[])
{
  Matrix4d m1{
    {1,1,0,0},{0,0,1,1},{1,0,1,0},{0,1,0,1}};

  std::cout << m1 << std::endl;
  std::cout << m1.inverse() << std::endl;


  return EXIT_SUCCESS;
}