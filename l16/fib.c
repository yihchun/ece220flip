#include <stdio.h>

unsigned int fib(unsigned int n) {
  if (n <= 1) return n;
  return fib(n-1)+fib(n-2);
}

int main() {
  printf("The 6th Fibonacci number is %d\n", fib(6));
  return 0;
}
