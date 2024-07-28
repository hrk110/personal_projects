#include <iostream>

#include "ByteHashMap.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  byte b{3};
  // cout << (uint8_t)(3) << endl;
  // cout << (int8_t)3 << endl;
  // cout << (int16_t)3 << endl;
  // cout << (uint16_t)3 << endl;
  // cout << static_cast<uint8_t>(b) << endl;
  // cout << static_cast<uint16_t>(b) << endl;
  // 1バイトの型だとcharとして出力されてしまう
  ByteHashMap<int> hm;
  int index = 0;
  hm.emplace(static_cast<byte>('a'), index++);
  hm.emplace(static_cast<byte>('b'), index++);
  hm.emplace(static_cast<byte>('d'), index++);
  hm.emplace(static_cast<byte>(0xce), index++);

  cout << (hm.contains('d') ? "contained" : "not contained") << endl;
  cout << (hm.contains('e') ? "contained" : "not contained") << endl;
  cout << hm << endl;
  cout << hm.size() << endl;
  for (auto itr = hm.begin(); itr != hm.end(); ++itr) {
    cout << *itr << endl;
  }

  return EXIT_SUCCESS;
}
