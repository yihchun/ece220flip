#include <iostream>

using namespace std;

template <class T>
T sum(T a, T b) { return a+b; }

class myint {
  int a;
  friend ostream &operator<<(ostream &, const myint &);
public:
  myint() { a = 0; }
  myint(int x) { a = x; }
  myint &operator=(const myint &y) { a = y.a; return *this; }
  bool operator>(const myint &y) const { return a>y.a; }
};

ostream &operator<<(ostream &os, const myint &x) {
  os << x.a;
  return os;
}

template <class T>
class mypair {
  T a, b;
public:
  mypair(const T &a_, const T &b_) { a = a_; b = b_; }
  T getmax() const { return a>b ? a:b; }
};

int main(){
  myint a(100);
  myint b(75);
  mypair<myint> z(a,b);
  myint y = z.getmax();
  cout << z.getmax() << endl;
  /*
  cout << sum(1,2) << endl;
  cout << sum(1.1, 2.1) << endl;
  cout << sum<int>(1.1, 2) << endl;
  */

  return 0;
}
