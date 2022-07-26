#include <iostream>
#include "point.cpp"
#include "cmath"

class CircleType : public PointType{
  private:
    double r;
  
  public:
    CircleType(double x, double y, double=0.0);
    
    void setR(double);
    double getR();
    
    double getArea();
    double getCircumference();
    
    void print();
};

//constructor
CircleType::CircleType(double x, double y, double radius) : PointType( x, y ){
  setR(radius);
}


//setter
void CircleType::setR(double radius) { 
  r = (radius < 0.0 ? 0.0 : radius); 
}

//getter
double CircleType::getR() { 
  return r; 
}

double CircleType::getArea() { 
  return M_PI * r * r; //pi from cmath
}

double CircleType::getCircumference() { 
  return 2 * r * M_PI; //pi from cmath
}

void CircleType::print(){
  cout << "\tCenter of the circle is: ";
  PointType::print();

  cout<<"\tRadius of the circle is = " << r <<endl;
  cout<<"\tArea of the circle is = " << getArea() <<endl;
  cout<<"\tCircumference of the circle is = "<< getCircumference() <<endl;
}