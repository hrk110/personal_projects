#include <iostream>
#include <vector>
using std::cin, std::cout, std::cerr, std::endl;
using std::swap;

void display(const std::vector<int>& array){
  cout << "array: ";
  for(auto x: array){
    cout << x << ' ';
  } cout << endl;
}

namespace Sort {
/**
 * bubble sort: O(N^2)
 */
void bubble_sort(std::vector<int>& array){
  int N = array.size();
  for(int i=0; i<N-1; ++i){
    for(int j=N-1; j>i; --j){
      if(array.at(j-1) > array.at(j)) swap(array.at(j-1), array.at(j));
      display(array);
    }
  }
  return;
}

std::vector<int> merge_(std::vector<int> front, std::vector<int> back){

}

/**
 * merge sort: O(NlogN)
 */
std::vector<int> merge_sort(std::vector<int> array){
  if(array.size() == 1){
    return array;
  }
  else{
    std::vector<int> front(array.begin(), array.begin()+array.size()/2);
    std::vector<int> back(array.begin()+array.size()/2, array.end());
    return merge_(merge_sort(front), merge_sort(back));
  }
}

/**
 * quick sort: O(NlogN)
 */

} // namespace Sort

int main(int argc, char *argv[])
{
  std::vector<int> array = {4, 5, 2, 6, 3};
  cout << "----- sort -----" << endl;

  std::string command;

  cout << "command(bubble/quick/merge/exit)?\n> ";
  cin >> command;
  if(command == "bubble"){
    Sort::bubble_sort(array);
  }
  else if(command == "quick"){
  }
  else if(command == "merge"){
    array = Sort::merge_sort(array);
  }
  else{
    cerr << "invalid command." << endl;
  }

  return EXIT_SUCCESS;
}