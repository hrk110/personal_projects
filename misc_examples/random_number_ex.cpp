#include <iostream>
#include <random>

// using namespace std;
template <typename T>
void shuffle(std::vector<T> &list)
{
    std::random_device seed_gen;
    std::mt19937 e;
    e.seed(seed_gen());
		int vector_size = list.size();

    // Shuffle by Fisher-Yates method.
    for(int i=vector_size-1; i>0; i--) {
        std::uniform_int_distribution<int> d(0, i); // [0,1,...,i]
        int j = d(e);
        // Swap list[i] and list[j].
        T tmp = list.at(i);
        list.at(i) = list.at(j);
        list.at(j) = tmp;
    }
}

int main(int argc, char *argv[])
{
  // random_device seed_gen;
  // std::mt19937 e;
  // e.seed(seed_gen());
  // std::uniform_int_distribution<int> d(0, 9);
  // int array[12];
  // for(int i=0; i<300; ++i){
  //   int k = d(e);
  //   array[k]++;
  // }
  // for(int x:array) {
  //   for(int i=0; i<x; ++i) std::cout << '*';
  //   std::cout << std::endl;
  // }


  std::vector<std::vector<int>> v_list{{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
  std::vector<int> count{0,0,0,0,0,0};
  for(int i=0; i<1000; ++i){
    std::vector<int> v{0,1,2};
    shuffle(v);
    for(auto x:v) std::cout << x << ' ';
    for(int j=0; j<6; ++j){
      if(v == v_list.at(j)){
        std::cout << " => " << j << std::endl;
        ++count.at(j);
      }
    }
  }
  std::cout << "result: [";
  for(auto i:count) std::cout << i << ' ';
  std::cout << "]" << std::endl;
  return EXIT_SUCCESS;
}