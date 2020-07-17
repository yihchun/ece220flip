#include <stdio.h>

unsigned int fib(unsigned int n) {
  unsigned int tmp;
  if (n <= 1) return n;
  tmp = fib(n-1);
  return tmp+fib(n-2);
}

int main() {
  printf("The 6th Fibonacci number is %d\n", fib(6));
  return 0;
}
