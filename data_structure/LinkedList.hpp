#pragma once
#include <iostream>

template<typename T>
class LinkedList {
  private:

  class Node {
    public:
    T key;
    Node *next;

    Node(): key(T()), next(nullptr){};
    Node(T key): key(key), next(nullptr){};
    ~Node(){};
  };

  Node *begin_;

  public:

  LinkedList(){
    begin_ = new Node;
  };
  ~LinkedList(){};

  bool is_empty() const{
    return !begin_->next;
  }

  void append(T new_key){
    Node *new_node = new Node(new_key);
    Node *ptr = begin_;
    for(; ptr->next; ptr = ptr->next){}
    ptr->next = new_node;
  }

  void erace(T key){
    for(Node *ptr = begin_; ptr; ptr = ptr->next){
      if(ptr->next->key == key){
        Node *del_ptr = ptr->next;
        ptr->next = ptr->next->next;
        delete del_ptr;
        return;
      }
    }
    std::cerr << "key " << key << " is not in the list" << std::endl;
  }

  bool is_contained(T key) const{
    for(Node *ptr = begin_->next; ptr; ptr = ptr->next){
      if(ptr->key == key){
        return true;
      }
    }
    return false;
  }

  void display() const{
    std::cout << "[";
    for(Node *ptr = begin_->next; ptr; ptr = ptr->next){
      std::cout << ptr->key << ' ';
    }
    std::cout << "]" << std::endl;
  }
};