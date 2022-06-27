/*
  Heap(Priority Queue)
  This data structure support the following methods:
  - append(key)
  - deletemin()
  Note that finding an arbitrary value (which takes O(n)) is not supported.
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
    array_.emplace_back(new_key);
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

      exit(EXIT_FAILURE);
    }

    T min = array_.front();
    array_.front() = array_.back();
    array_.pop_back();

    int i = 0;
    int length = array_.size();
    while (2*i+1 < length){
      int child_idx = 2*i+1;
      if(child_idx+1 < length && array_.at(child_idx) > array_.at(child_idx+1)){
        ++child_idx;
      }

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