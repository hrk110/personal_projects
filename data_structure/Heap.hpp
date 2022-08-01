/*
  Heap(Priority Queue)
  This data structure supports the following methods:
  - append(key)
  - deletemin()
  Note that finding an arbitrary value (which takes O(n)) is not supported.
  This heap has its minimum value on the root node.
 */

#pragma once
#include <iostream>
#include <vector>
using std::cin, std::cout, std::cerr, std::endl;
using std::swap;

template<typename T>
class Heap {
  private:
  std::vector<T> array_;

  int find_child_(int i) const{
    int length = array_.size();
    if(2*i+1 >= length){ // has no children
      return -1;
    }
    else if(2*i+2 >= length){ // has left child only
      return 2*i+1;
    }
    else{ // has both children
      return (array_.at(2*i+1) > array_.at(2*i+2))? 2*i+2: 2*i+1;
    }
  }

  public:
  Heap(): array_(){};

  Heap(std::vector<T> v): array_(){
    for(auto x: v){
      append(x);
    }
  };
  ~Heap(){};

  bool is_empty(void) const{
    return array_.empty();
  }

  void append(T new_key){
    // Add new key to the end of array.
    array_.emplace_back(new_key);

    // Heapify from leaf nodes to the root node.
    // the parent of i'th node is (i-1)/2'th node.
    int i = array_.size() - 1;
    while(i > 0){
      if(array_.at((i-1)/2) > array_.at(i)){
        swap(array_.at((i-1)/2), array_.at(i));
        i = (i-1)/2;
      }
      else break;
    }
  }

  T deletemin(void){
    if(array_.empty()){
      cerr << "deletemin: array is empty." << endl;
      exit(EXIT_FAILURE);
    }

    // Move the node which is added most recently to the root.
    T min = array_.front();
    array_.front() = array_.back();
    array_.pop_back();

    // Heapify from the root node to leaf nodes.
    // Children of i'th node are 2*i+1'th and 2*i+2'th node.
    int i = 0;
    while(true){
      int child_idx = find_child_(i);
      if(child_idx == -1) break;

      if(array_.at(i) > array_.at(child_idx)){
        swap(array_.at(i), array_.at(child_idx));
        i = child_idx;
      }
      else break;
    }

    return min;
  }

  std::vector<T> sorted(){
    std::vector<T> result;
    while(!array_.empty()){
      result.emplace_back(deletemin());
    }
    return result;
  }

  void display() const{
    cout << "Heap: [";
    for(int i=0; i<array_.size(); ++i){
      if(i != 0 && ((i+1)&i) == 0) cout << "| ";
      cout << array_.at(i) << ' ';
    }
    cout << "]\n" << endl;
  }
};