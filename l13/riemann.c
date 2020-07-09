#include <stdio.h>

int main() {
  float a,b;
  int N;
  int i;
  float width;
  float x;
  float accum = 0;

  printf("This program Riemann integrates x*x from a to b with N steps.\n");
  printf("What is your lower limit of integration? ");
  scanf("%f", &a);
  printf("What is your upper limit of integration? ");
  scanf("%f", &b);
  printf("How many steps? ");
  scanf("%d", &N);

  if (N <= 0) {
    printf("I don't know how to have fewer than 1 step\n");
    return 0;
  }

  width = (b-a)/N;
  x=a;
  for (i=0; i<N; i++) {
    accum += x*x*width;
    x += width;
  }
  printf("Integral from %f to %f of x*x is approximately (%d steps) %f\n",
	 a, b, N, accum);
  return 0;
}
