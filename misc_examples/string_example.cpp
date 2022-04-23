#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  string str = "hello";
  cout << str << endl;

  // not work
  const char* str2 = "こんにちは";
  cout << str2[0] << endl;

  // also not work
  string str3 = "こんにちは";
  cout << str3.at(0) << endl;
  return EXIT_SUCCESS;
}