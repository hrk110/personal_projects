/**
 * @file Trie.cpp
 * @brief Trie source code
 */
#include <iostream>
#include <random>
#include <climits>
#include "Trie.hpp"

using namespace std;

string generate_random_string(size_t N) {
  // static random_device seed_gen;
  static mt19937_64 e(1);

  static uniform_int_distribution<int> d(static_cast<int>('A'), static_cast<int>('z'));

  string str("");
  for (auto i = 0; i < N; ++i) {
    str += static_cast<char>(d(e));
  }

  return str;
}

int main(int argc, char* argv[]) {
  // int num_words = 10000;
  // if (argc == 2) num_words = stoi(argv[1]);
  // int word_length = 10;
  // Trie<uint8_t> t;
  // for (auto i = 0; i < num_words; ++i) {
  //   t.insert({generate_random_string(word_length), i});
  // }

  // cout << "sizeof(Node*) = " << sizeof(Node*) << endl;                        // 8
  // cout << "sizeof(shared_ptr<Node>) = " << sizeof(shared_ptr<Node>) << endl;  // 16

  Trie<uint8_t> t2;
  t2.insert({"he", 0});
  t2.insert({"she", 1});
  t2.insert({"his", 2});
  t2.insert({"hers", 3});
  t2.insert({"àâaaaaaaaa", -1});
  t2.count("he");
  // t2.find("shis"); // not implemented
  t2.print();
  // cout << "inserted" << endl;

  unsigned char str[] = "àâ";  // 2 + 2 + 1 byte
  // size_t length = sizeof(str) / sizeof(str[0]);
  unsigned char* p = str;

  while (true) {
    // cout << static_cast<uint32_t>(c) << endl;
    printf("%#x\n", *p);
    if (!*p) break;
    p++;
  }
  // shared_ptr -> Node*で1.5GBから900MBに

  string str2("àâ");
  cout << sizeof("àâ") << endl;     // 5
  cout << sizeof(str2) << endl;     // 32, '\0' eliminated, each char has 8 bytes
  cout << (1 << CHAR_BIT) << endl;  // 256
  // 1,2,4,8,16,32,64,128,256
  for (auto c : str2) {
    printf("%#x\n", c);
  }

  char c;
  while (true) {
    cin >> c;
    if (c == 'q') break;
  }
  return EXIT_SUCCESS;
}
