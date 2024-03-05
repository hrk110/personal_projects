#include <assert.h>
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

// expr ::= term [(+|-) term]*
int expr(const char* S);
// term ::= factor [(*|/) factor]*
int term(const char* S);
// factor ::= number | '(' expr ')'
int factor(const char* S);
// number ::= [0-9]+
int number(const char* S);

int expr(const char* S) {
  int val = term(&S);

  while (*S) {
    if (*S == '+') {
      S++;
      val += term(S);
    }
    else if (*S == '-') {
      S++;
      val -= term(S);
    }
    else
      // syntax error
      break;
  }

  return val;
}

int term(const char* S) {
  int val = factor(S);

  while (*S) {
    if (*S == '*') {
      S++;
      val *= factor(S);
    }
    else if (*S == '/') {
      S++;
      val /= factor(S);
    }
    else
      // syntax error
      break;
  }
  return val;
}

int factor(const char* S) {
  if (*S == '(') {
    S++;
    int val = expr(S);
    assert(*S == ')');
    return val;
  }
  else {
    return number(S);
  }
}

int number(const char* S) {
  int val = 0;
  while (*S && ('0' <= *S && *S <= '9')) {
    val = val * 10 + (*(S++) - '0');
  }
  return val;
}

int main(int argc, char* argv[]) {
  char S[256] = {0};

  while (1) {
    printf("Enter an expression (q for exit): ");
    if ((scanf("%255[^\n]%*[^\n]", S) == 1)) break;
    scanf("%*c");
  }

  if (strcmp(S, "q") == 0) return 0;


  int result = expr(S);
  printf("%d\n", result);
  return 0;
}