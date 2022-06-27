#include <iostream>
#include <string>
#include "Heap.hpp"
using std::cin, std::cout, std::cerr, std::endl;

int main(int argc, char *argv[])
{
  Heap<int> h;
  std::string command;
  int key;
  cout << "----- heap -----" << endl;

  while(true){
    cout << "command(append/deletemin/exit)?\n> ";
    cin >> command;
    if(command == "append" | command == "erase" | command == "search"){
      cout << "key?\n> ";
      cin >> key;
    }
    if(command == "append"){
      h.append(key);
    }
    else if(command == "deletemin"){
      if(h.is_empty()){
        cerr << "Heap does not have any elements." << endl;
      }
      else{
        auto min = h.deletemin();
        cout << "The minimum value is " << min << '.' << endl;
      }
    }
    else if (command == "exit"){
      break;
    }
    else{
      cerr << "invalid command" << endl;
    }
    h.display();
  }

  return EXIT_SUCCESS;
}