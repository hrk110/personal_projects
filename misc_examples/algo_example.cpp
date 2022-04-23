#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <bitset>

int main(int argc, char *argv[])
{
  // std::vector<double> v1 = {0.1, 0.2, 0.3};
  // std::cout << std::accumulate(v1.begin(), v1.end(), static_cast<double>(0)) << std::endl;

  // std::vector<double> v2 = {1, 3, 2, 5, 4.5, 5.0, 1.5};
  // std::cout << *std::max_element(v2.begin(), v2.end()) << std::endl;
  // std::cout << std::distance(v2.begin(), std::max_element(v2.begin(), v2.end())) << std::endl;

  // std::vector<double> v3 = {1,2,3,4};
  // for(auto x:v3) std::cout << x << ' '; std::cout << std::endl;
  // for(int i=1; i<4; ++i) v3.at(i) *= v3.at(i-1);
  // for(auto x:v3) std::cout << x << ' '; std::cout << std::endl;

  // std::cout << std::isinf(1*0.701947*1.23812e-73) << std::endl;

  std::cout << std::bitset<64>(10) << std::endl;

  return EXIT_SUCCESS;
}
