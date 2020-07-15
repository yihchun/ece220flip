#include <stdio.h>

int Fact(int);

int main() {
  int n, res;
  scanf("%d", &n);
  res = Fact(n);
  printf("%d! = %d\n", n, res);
}

int Fact(int n) {
  int ret, i;
  if (n < 0) {
    printf("We don't know how to take factorial of negative numbers\n");
    return 1;
  }
  ret = 1;
  for (i=1; i<=n; i++)
    ret *= i;
  return ret;
}
  
