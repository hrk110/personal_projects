#include <iostream>
#include <vector>
using std::cin, std::cout, std::cerr, std::endl;
using std::swap;

namespace QuickSort{
  /**
   * naive: not limited to array. any type of array is allowed.
   * but this uses a lot of memory.
   */
  auto naive(std::vector<int>& array){
    if(array.size() <= 1){
      return array;
    }
    int pivot = std::max(array.at(0), array.at(1)); // not to choose the minimum of whole array
    std::vector<int> front_array, back_array;
    for(auto x: array){
      if(x < pivot) front_array.emplace_back(x);
      else back_array.emplace_back(x);
    }
    auto front_array_sorted = naive(front_array);
    auto back_array_sorted  = naive(back_array);
    front_array_sorted.insert(front_array_sorted.end(), back_array_sorted.begin(), back_array_sorted.end());
    return front_array_sorted;
  }

  int find_pivot(std::vector<int>& array, int begin, int end){
    int first = array.at(begin);
    for(int i=begin+1; i<=end; ++i){
      if(array.at(i) != first) return std::max(first, array.at(i));
    }
    return -1;
  }

  int partition(std::vector<int>& array, int begin, int end, int pivot){
    cout << "partition(pivot=" << pivot << "): " << begin << "-" << end << endl;
    while(true){
      int i, j;
      for(i=begin; array.at(i) < pivot; ++i){}
      for(j=end; array.at(j) >= pivot; --j){}

      if(i > j){
        return i;
      }
      else{
        swap(array.at(i), array.at(j));
        cout << "swaped: "; for(auto x:array) cout << x << ' '; cout << endl;
      }
    }
  }

  // sort in [begin, end]
  void in_place(std::vector<int>& array, int begin, int end){
    cout << "in_place: " << begin << "-" << end << endl;
    if(begin >= end) return;
    int pivot = find_pivot(array, begin, end);
    if(pivot == -1){
      cerr << "each element of array has same value." << endl;
      return;
    }
    int pivot_pos = partition(array, begin, end, pivot);
    cout << "partition end" << endl;
    in_place(array, begin, pivot_pos-1);
    in_place(array, pivot_pos, end);
  }
}

int main(int argc, char *argv[]){
  std::vector<int> array = {5,6,3,9,2,8,4,7};
  std::vector<int> sorted_array;
  cout << "----- quick sort -----" << endl;

  std::string command;
  cout << "command(naive/in_place//exit)?\n> ";
  cin >> command;
  if(command == "naive"){
    sorted_array = QuickSort::naive(array);
  }
  else if(command == "in_place"){
    QuickSort::in_place(array, 0, array.size()-1);
    sorted_array = array;
  }
  else{
    cerr << "invalid command." << endl;
  }
  for(auto x: sorted_array) cout << x << ' '; cout << endl;

  return EXIT_SUCCESS;
}