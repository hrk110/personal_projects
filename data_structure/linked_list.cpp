#include <iostream>
#include <string>
#include "LinkedList.hpp"
using std::cin, std::cout, std::cerr, std::endl;

int main(int argc, char *argv[])
{
  LinkedList<int> list;
  std::string command;
  int key;
  cout << "----- Linked List -----" << endl;

  while(true){
    cout << "command(append/erase/search/exit)?\n> ";
    cin >> command;
    if(command == "append" | command == "erase" | command == "search"){
      cout << "key?\n> ";
      cin >> key;
    }

    if(command == "append"){
      list.append(key);
    }
    else if(command == "erase"){
      if(list.erace(key)){
        cout << "Key " << key << " was successfully erased." << endl;
      }
      else{
        cout << "Unable to erase key " << key << '.' << endl;
      }
    }
    else if(command == "search"){
      if(list.is_contained(key)){
        cout << "key " << key << " is in the list." << endl;
      }
      else{
        cout << "key " << key << " is not in the list." << endl;
      }
    }
    else if (command == "exit"){
      break;
    }
    else{
      cerr << "invalid command" << endl;
      // return EXIT_FAILURE;
    }
    list.display();
  }

  return EXIT_SUCCESS;
}