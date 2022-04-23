#include <iostream>
#include <string>
#include "LinkedList.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  LinkedList<int> list;
  string command;
  int key;
  while(true){
    cout << "command(append/erase/search/exit): ";
    cin >> command;
    if(command == "append" | command == "erase" | command == "search"){
      cout << "key?: ";
      cin >> key;
    }
    if(command == "append"){
      list.append(key);
    }
    else if(command == "erase"){
      list.erace(key);
    }
    else if(command == "search"){
      if(list.is_contained(key)){
        cout << "key " << key << " is in the list" << endl;
      }
      else{
        cout << "key " << key << " is not in the list" << endl;
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