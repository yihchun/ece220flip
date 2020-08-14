#include <iostream>

using namespace std;

class twodvec {
public:
  twodvec(double _x, double _y) { x = _x; y = _y; howmany++; }
  twodvec operator+(const twodvec &b) { twodvec tmp(x+b.x, y+b.y); return tmp; }
  double operator[](int z) const { if (!z) return x; if (z==1) return y; return 0;}
  void show() { cout << x << " " << y << endl; cout << "we have made " << howmany << " twodvecs" << endl;}
private:
  double x, y;
  static int howmany;
};

int twodvec::howmany;

int main() {
  twodvec xbasis(1,0);
  twodvec ybasis(0,1);
  twodvec tmp = xbasis+ybasis;
  tmp.show();
  cout << tmp[1] << endl;
}
