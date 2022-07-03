#include <iostream>
#include <string>
#include "BinarySearchTree.hpp"
using std::cin, std::cout, std::cerr, std::endl;

int main(int argc, char *argv[])
{
  BinarySearchTree<int> bst;
  cout << "----- binary search tree -----" << endl;

  std::string command;
  int key;
  while(true){
    cout << "command(insert/erase/search/exit)?\n> ";
    cin >> command;
    if(command == "insert" | command == "erase" | command == "search"){
      cout << "key?\n> ";
      cin >> key;
    }
    if(command == "insert"){
      bst.insert(key);
    }
    else if(command == "erase"){
      if(!bst.erase(key)){
        cerr << "erase: no such key in the tree." << endl;
      }
    }
    else if(command == "search"){
      if(bst.search(key)){
        cout << "Key " << key << " is in the tree." << endl;
      }
      else{
        cout << "Key " << key << " is not in the tree." << endl;
      }
    }
    else if (command == "exit"){
      break;
    }
    else{
      cerr << "invalid command. Try again." << endl;
    }
    bst.display();
  }

  return EXIT_SUCCESS;
}