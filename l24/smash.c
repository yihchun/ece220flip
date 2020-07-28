#include <stdio.h>

void readstring() {
  char s[256];
  gets(s);
}

int arraysum() {
  int vals[10];
  int i = 0;
  int sum = 0;

  while (1) {
    scanf("%d", vals+i);
    if (vals[i] == -1) break;
    i++;
  }

  i = 0;
  while (vals[i] != -1) {
    sum += vals[i];
    i++;
  }

  if (!i) return 0;
  printf("The average of your values is %d\n", sum/i);
  return sum/i;
}

int main() {
  arraysum();
  return 0;
}
