#include <stdio.h>

/* factorial returns n!, where n is the parameter passed */
unsigned int factorial(unsigned int n) {
  unsigned int tmp;
  if (n <= 1) return 1;
  tmp = factorial(n-1); /* tmp = (n-1)! */
  return n*tmp;
}

int main() {
  int x;

  while (1) {
    scanf("%d", &x);
    printf("%d! = %d\n", x, factorial(x));
  }
}
