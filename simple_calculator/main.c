#include <assert.h>
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

// expr ::= term [(+|-) term]*
int expr(const char* S, size_t* i);
// term ::= factor [(*|/) factor]*
int term(const char* S, size_t* i);
// factor ::= number | '(' expr ')'
int factor(const char* S, size_t* i);
// number ::= [0-9]+
int number(const char* S, size_t* i);

int expr(const char* S, size_t* i) {
  int val = term(S, i);

  while (S[*i]) {
    if (S[*i] == '+') {
      (*i)++;
      val += term(S, i);
    }
    else if (S[*i] == '-') {
      (*i)++;
      val -= term(S, i);
    }
    else
      break;
  }

  return val;
}

int term(const char* S, size_t* i) {
  int val = factor(S, i);

  while (S[*i]) {
    if (S[*i] == '*') {
      (*i)++;
      val *= factor(S, i);
    }
    else if (S[*i] == '/') {
      (*i)++;
      val /= factor(S, i);
    }
    else
      break;
  }
  return val;
}

int factor(const char* S, size_t* i) {
  if (S[*i] == '(') {
    (*i)++;
    int val = expr(S, i);
    assert(S[*i] == ')');
    return val;
  }
  else {
    return number(S, i);
  }
}

int number(const char* S, size_t* i) {
  int val = 0;
  while (S[*i] && ('0' <= S[*i] && S[*i] <= '9')) {
    val = val * 10 + (S[(*i)++] - '0');
  }
  return val;
}

int main(int argc, char* argv[]) {
  printf("Enter an expression (q for exit): ");
  char S[256] = {0};
  scanf("%s", S);

  if (strcmp(S, "q") == 0 ) return 0;

  size_t* i = (size_t)0;
  int result = expr(S, i);
  printf("%d\n", result);
  return 0;
}