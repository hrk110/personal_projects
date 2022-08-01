#include <iostream>
#include <vector>
#include "Heap.hpp"
using std::cin, std::cout, std::cerr, std::endl;
using std::swap;

void print_array(std::vector<int>& array){
  bool first = true;
  cout << '[';
  for(auto x: array){
    if(first) first = false;
    else cout << ' ';
    cout << x;
  }
  cout << ']' << endl;
}

namespace HeapSort {
  // Heapify in section [begin, end].
  void pushdown(std::vector<int>& array, int begin, int end){
    if(begin == end) return;
    int i = begin;
    while(i <= (end-1)/2){
      int j = 0;
      if(2*i+2 > end){ // has left child only
        j = 2*i+1;
      }
      else{ // has both children
        j = (array.at(2*i+1) > array.at(2*i+2))? 2*i+2: 2*i+1;
      }

      if(array.at(i) > array.at(j)){
        swap(array.at(i), array.at(j));
        i = j;
      }
      else break;
    }
  }

  void heapsort_inplace(std::vector<int>& array){
    int N = array.size();
    // Heapify the array from bottom.
    for(int i=(N-2)/2; i>=0; --i){ // start with the lowest node which has child.
      pushdown(array, i, N-1);
    }

    // Extract the minimum and move to the end of array.
    for(int i=N-1; i>0; --i){
      swap(array.front(), array.at(i));
      pushdown(array, 0, i-1);
    }

    // Make the sorted array in the ascending order.
    for(int i=0; i<N/2; ++i){
      swap(array.at(i), array.at(N-1-i));
    }
  }
}

int main(int argc, char *argv[])
{
  cout << "----- Heap Sort -----" << endl;
  int N; cout << "Number of elements?\n> "; cin >> N;
  std::vector<int> A(N, 0);
  cout << "input elements\n";
  for(int i=0; i<N; ++i){
    cout << "> ";
    cin >> A.at(i);
  }
  cout << "To be sorted: ";
  print_array(A);

  HeapSort::heapsort_inplace(A);
  print_array(A);

  return EXIT_SUCCESS;
}