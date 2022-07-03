/*
  Binary Search Tree
  This data structure supports the following methods:
  - append(key)
  - delete(key)
  - search(key)
 */

#pragma once
#include <iostream>
using std::cin, std::cout, std::cerr, std::endl;
using std::swap;

template<typename T>
class BinarySearchTree {
  private:
  class Node {
    public:
    T value;
    Node* parent;
    Node* left;
    Node* right;

    Node(T v): value(v), parent(nullptr), left(nullptr), right(nullptr){};
    ~Node(){};
  };

  Node* root_ptr_;

  T deletemin_(Node* right_ptr){
    Node* ptr = right_ptr;
    while(ptr->left){
      ptr = ptr->left;
    }
    T value = ptr->value;
    if(ptr->right){ // left child does not exist.
      ptr->right->parent = ptr->parent;
    }
    // ptr->parent always exists.
    if(ptr == right_ptr){
      ptr->parent->right = ptr->right;
    }
    else{
      ptr->parent->left = ptr->right;
    }
    delete ptr; ptr = nullptr;
    return value;
  }

  void display_sub_(Node* ptr) const{
    cout << '(';
    if(ptr->left) display_sub_(ptr->left);
    cout << ptr->value;
    if(ptr->right) display_sub_(ptr->right);
    cout << ')';
    return;
  }

  public:
  BinarySearchTree(): root_ptr_(nullptr){};
  ~BinarySearchTree(){};

  bool is_empty(void) const{
    return !root_ptr_;
  }

  bool insert(T new_key){
    if(is_empty()){
      root_ptr_ = new Node(new_key);
      return true;
    }
    Node* ptr = root_ptr_;
    while(true){
      if(new_key < ptr->value){
        if(!ptr->left){
          ptr->left = new Node(new_key);
          ptr->left->parent = ptr;
          return true;
        }
        else{
          ptr = ptr->left;
        }
      }
      else if(ptr->value < new_key){
        if(!ptr->right){
          ptr->right = new Node(new_key);
          ptr->right->parent = ptr;
          return true;
        }
        else{
          ptr = ptr->right;
        }
      }
      else{
        cerr << "Key " << new_key << " already exists." << endl;
        return false;
      }
    }
  }

  bool erase(T key){
    if(is_empty()){ return false; }

    Node* ptr = root_ptr_;
    while(true){
      if(key < ptr->value){
        if(!ptr->left){
          return false;
        }
        else{
          ptr = ptr->left;
        }
      }
      else if(ptr->value < key){
        if(!ptr->right){
          return false;
        }
        else{
          ptr = ptr->right;
        }
      }
      else{ // delete this node
        if(ptr->left && ptr->right){
          ptr->value = deletemin_(ptr->right);
        }
        else if(ptr->left){
          if(!ptr->parent){ // root node
            ptr->left->parent = nullptr;
            root_ptr_ = ptr->left;
          }
          else if(ptr == ptr->parent->left){
            ptr->left->parent = ptr->parent;
            ptr->parent->left = ptr->left;
          }
          else{
            ptr->left->parent = ptr->parent;
            ptr->parent->right = ptr->left;
          }
          delete ptr; ptr = nullptr;
        }
        else if(ptr->right){
          if(!ptr->parent){ // root node
            ptr->right->parent = nullptr;
            root_ptr_ = ptr->right;
          }
          else if(ptr == ptr->parent->left){
            ptr->right->parent = ptr->parent;
            ptr->parent->left = ptr->right;
          }
          else{
            ptr->right->parent = ptr->parent;
            ptr->parent->right = ptr->right;
          }
          delete ptr; ptr = nullptr;
        }
        else{
          if(!ptr->parent){
            root_ptr_ = nullptr;
          }
          else if(ptr == ptr->parent->left){
            ptr->parent->left = nullptr;
          }
          else{
            ptr->parent->right = nullptr;
          }
          delete ptr; ptr = nullptr;
        }
        return true;
      }
    }
  }

  bool search(T key) const{
    if(is_empty()){
      return false;
    }
    Node* ptr = root_ptr_;
    while(true){
      if(key < ptr->value){
        if(!ptr->left){
          return false;
        }
        else{
          ptr = ptr->left;
        }
      }
      else if(ptr->value < key){
        if(!ptr->right){
          return false;
        }
        else{
          ptr = ptr->right;
        }
      }
      else{
        return true;
      }
    }
  }

  void display() const{
    cout << "BinarySearchTree: [";
    if(root_ptr_) display_sub_(root_ptr_);
    cout << "]\n" << endl;
  }
};