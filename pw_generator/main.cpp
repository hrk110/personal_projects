#include <iostream>
#include <random>
#include <string>
#include <algorithm>

void generate_pw(int length, char symbol, int times){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::string raw_str = "";
  for(int i=0; i<10; ++i){ raw_str += '0' + i; }
  for(int i=0; i<26; ++i){ raw_str += 'A' + i; }
  for(int i=0; i<26; ++i){ raw_str += 'a' + i; }
  if(symbol == 'y'){ raw_str += "/*-+.,!#$%&()~|_"; }

  // std::cout << raw_str << std::endl;

  std::cout << std::endl;
  for(int i=0; i<times; ++i){
    shuffle(raw_str.begin(), raw_str.end(), engine);
    std::cout << raw_str.substr(0,length) << std::endl;
  }

}

int main(int argc, char *argv[])
{
  // length: pw length
  int length;
  std::cout << "length? "; std::cin >> length;
  char symbol = 0;
  while(symbol != 'y' && symbol != 'n'){
  std::cout << "contain symbol?(y/n) "; std::cin >> symbol;
  }
  int candidate_num;
  std::cout << "how many candidates? "; std::cin >> candidate_num;

  generate_pw(length, symbol, candidate_num);

  return EXIT_SUCCESS;
}