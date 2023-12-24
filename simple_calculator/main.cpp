/*
  - Using index rather than iterator.
  - require C++23.
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

// expr ::= term [(+|-) term]*
int expr(const string& S, size_t& i);
// term ::= factor [(*|/) factor]*
int term(const string& S, size_t& i);
// factor ::= number | '(' expr ')'
int factor(const string& S, size_t& i);
// number ::= [0-9]+
int number(const string& S, size_t& i);

// cerr << "Error: unexpexted symbol at i = " << i << endl;

int expr(const string& S, size_t& i) {
  int val = term(S, i);

  while (0 <= i && i < S.length()) {
    if (S.at(i) == '+') {
      val += term(S, ++i);
    }
    else if (S.at(i) == '-') {
      val -= term(S, ++i);
    }
    else {
      break;
    }
  }
  return val;
}

int term(const string& S, size_t& i) {
  int val = factor(S, i);

  while (0 <= i && i < S.length()) {
    if (S.at(i) == '*') {
      val *= factor(S, ++i);
    }
    else if (S.at(i) == '/') {
      val /= factor(S, ++i);
    }
    else {
      break;
    }
  }
  return val;
}

int factor(const string& S, size_t& i) {
  if (S.at(i) == '(') {
    auto ret = expr(S, ++i);
    assert(S.at(i++) == ')');
    return ret;
  }
  else {
    return number(S, i);
  }
}

int number(const string& S, size_t& i) {
  int num = 0;
  while ((0 <= i && i < S.length()) && ('0' <= S.at(i) && S.at(i) <= '9')) {
    num = num * 10 + (S.at(i++) - '0');
  }

  return num;
}

int main(int argc, char* argv[]) {
  // cin.tie(nullptr);
  // ios_base::sync_with_stdio(false);

  string avail = "0123456789+-*/()";

  while (true) {
    cout << "Enter an expression (q for exit): ";
    string S;
    cin >> S;

    if (S == "q") {
      break;
    }
    for (auto c : S) {
      if (!avail.contains(c)) {
        cerr << "Error: contains unavailable character: " << c << endl;
        exit(EXIT_FAILURE);
      }
    }

    size_t i = 0;
    cout << expr(S, i) << endl;
  }
  return EXIT_SUCCESS;
}