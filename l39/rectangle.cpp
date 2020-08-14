#include <iostream>
using namespace std;

class Rectangle {
  int width, height;
public:
  Rectangle() { width = height = 0; }
  Rectangle(int, int);
  int area() const { return width * height; }
};

Rectangle::Rectangle(int w, int h) {
  width = w; height = h;
}

int main() {
  Rectangle a(3,4);
  Rectangle b;
  cout << a.area() << endl;
  cout << b.area() << endl;
  return 0;
}
