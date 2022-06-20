#include <iostream>
#include <array>
#include "FourIntsLinkedList.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 5) {
    cerr << "invalid arguments" << endl;
    exit(EXIT_FAILURE);
  }
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = atoi(argv[3]);
  int d = atoi(argv[4]);
  cout << '[' << a << ' '
              << b << ' '
              << c << ' '
              << d << ']' << endl;
  // constexpr array<char, 4> op_list = {'+', '*', '-', '/'};
  constexpr array<char, 3> op_list = {'+', '*', '-'};

  for(int i=0; i<3; ++i){
    for(char op1: op_list){
      for(int j=0; j<2; ++j){
        for(char op2: op_list){
          for(char op3: op_list){
            FourIntsLinkedList l(a, b, c, d);
            l.calc_at(i, op1);
            l.calc_at(j, op2);
            l.calc_at(0, op3);
            l.is_calculated = true;
            string result = l.get_result();
            int answer = l.get_answer();
            if(answer == 10) cout << result << " = " << answer << endl;
          }
        }
      }
    }
  }

  return EXIT_SUCCESS;
}