#include <stdio.h>

typedef struct twodvect_t {
  double x, y;
} twodvect;

twodvect add(twodvect a, twodvect b) {
  twodvect ret = {a.x+b.x, a.y+b.y};
  return ret;
}

int main() {
  twodvect xbasis = {1,0};
  twodvect ybasis = {0,1};
  twodvect tmp = add(xbasis,ybasis);
  printf("%lf %lf\n", tmp.x, tmp.y);
}
