#pragma once
#include <iostream>
#include <string>
using std::cout, std::cerr, std::endl;

class FourIntsLinkedList {
  private:
  class Node {
    public:
    int value;
    std::string result;
    Node* next;

    Node(int i): value(i), result(std::to_string(i)), next(nullptr){};
    ~Node(){};
  };
  Node* front_node_;

  public:
  FourIntsLinkedList(int a, int b, int c, int d): is_calculated(false){
    front_node_ = new Node(a);
    front_node_->next = new Node(b);
    front_node_->next->next = new Node(c);
    front_node_->next->next->next = new Node(d);
  };
  ~FourIntsLinkedList(){};

  Node* get_front_node() const{
    return front_node_;
  }

  bool calc_at(int i, char op){
    if(i<0) return false;

    Node* n = front_node_;
    for(int j=0; j<i; ++j){ n = n->next; } // error?
    int left = n->value;
    int right = n->next->value;

    switch (op){
      case '+':
        n->value = left + right;
        break;
      case '*':
        n->value = left * right;
        break;
      case '-':
        n->value = left - right;
        break;
      default:
        break;
    }
    n->result = ("(" + n->result + op + n->next->result + ")");
    Node* delete_node = n->next;
    n->next = n->next->next;
    delete delete_node;

    return true;
  }

  bool is_calculated;

  std::string get_result() const{
    if(!is_calculated){
      cerr << "Calculation not finished." << endl;
      return "";
    }
    else{
      return front_node_->result;
    }
  }

  int get_answer() const{
    if(!is_calculated){
      cerr << "Calculation not finished." << endl;
      return -1;
    }
    else{
      return front_node_->value;
    }
  }

  friend std::ostream& operator<<(std::ostream & os, FourIntsLinkedList& l){
    Node* p = l.get_front_node();
    os << '[';
    while(true){
      os << p->value << ", ";
      if(!p->next) break;
      p = p->next;
    }

    return os << ']';
  }
};
