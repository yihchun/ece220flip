#include <iostream>

using namespace std;

class Base {
public:
  virtual void show() { cout << "I am a Base\n"; }
};

class Foo : public Base {
public:
  void show() { cout << "I am a Foo\n"; }
};

class Bar : public Base {
public:
  void show() { cout << "I am a Bar\n"; }
};

int main() {
  Foo foo;
  Bar bar;
  Base *a = &foo;
  a->show();
  a = &bar;
  a->show();
  a = new Base;
  a->show();
}

