#include <stdio.h>

int main() {
  int a, i;

  printf("Please enter a number greater than 1: ");
  scanf("%d", &a);

  if (a <= 1) {
    printf("I don't know how to handle that.\n");
    return 0;
  }

  for (i=2; i<a; i++) {
    if (a%i == 0) {
      printf("%d is composite\n", a);
      return 0;
    }
  }

  printf("%d is prime\n", a);
  return 0;
}
