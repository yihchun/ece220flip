#include <stdio.h>

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int x, y;
  x = 2;
  y = 3; 
  printf("PRE: %d %d\n", x, y);
  swap(&x,&y);
  printf("POST: %d %d\n", x, y);
  return 0;
}
