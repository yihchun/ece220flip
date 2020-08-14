#include <iostream>

using namespace std;

class Shape {
	protected:
	double width, height;
	public:
	Shape() {width = 1; height = 1;}
	Shape(double a, double b) { width = a; height = b; }
	virtual double area() { cout << "Base class area unknown" << endl; 						 return 0; }
};

class Rectangle : public Shape{
	public:
	Rectangle(double a, double b) : Shape(a,b){}
	double area() { 
	  cout << "Rectangle area is " << width << "*" << height <<
	    " = " << (width*height) << endl;
	  return width * height;
	}
};

class Triangle : public Shape{
	public:
	Triangle(double a, double b) : Shape(a,b){}
	double area() {
	  cout << "Triangle area is 0.5 * " << width << "*" << height <<
	    " = " << (0.5*width*height) << endl;
	  return 0.5 * width * height;

	}
};

int main(){
    Rectangle rec(3,5);
    Triangle tri(4,5);
    Shape *s = &rec;

    rec.area();
    tri.area();
    s->area();

    return 0;
}
