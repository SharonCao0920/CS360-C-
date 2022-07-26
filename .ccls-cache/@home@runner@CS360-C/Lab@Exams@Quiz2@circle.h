#include <iostream>
#include "point.cpp"

class circleType : public pointType
{
  private:
  double r;
  
  public:
  circleType(double=0.0);
  
  void setR(double);
  double getR();
  
  double getArea();
  double getCircumference();
  
  void print();

};

circleType::circleType(double radius) { r = radius; }

void circleType::setR(double radius) { r = (radius < 0.0 ? 0.0 : radius); }

double circleType::getR() { return r; }

double circleType::getArea() { return 3.14 * r * r; }
double circleType::getCircumference() { return 2 * r * 3.14; }

void circleType::print()
{
pointType::print();

cout<<" Radius of the circle is = "<<r<<endl;
cout<<" Area of the circle is = "<<circleType::getArea()<<endl;
cout<<" Circumference of the circle is = "<<circleType::getCircumference()<<endl;


}