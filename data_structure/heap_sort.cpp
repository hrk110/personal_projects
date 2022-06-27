#include <iostream>
#include <vector>
#include "Heap.hpp"
using std::cin, std::cout, std::cerr, std::endl;

int main(int argc, char *argv[])
{
  cout << "----- Heap Sort -----" << endl;
  int N; cout << "Number of elements?\n> "; cin >> N;
  std::vector<int> input(N, 0);
  cout << "input elements\n";
  for(int i=0; i<N; ++i){
    cout << "> ";
    cin >> input.at(i);
  }
  cout << "To be sorted: [";
  for(int i=0; i<N; ++i){
    cout << input.at(i) << ' ';
  }
  cout << ']' << endl;

  {
    Heap h(input);
    h.display();
    auto result = h.sorted();

    bool first = true;
    cout << "Sorted: [";
    for(auto x: result){
      if(first) first = false;
      else cout << ' ';
      cout << x;
    } cout << ']' << endl;
  }


  return EXIT_SUCCESS;
}