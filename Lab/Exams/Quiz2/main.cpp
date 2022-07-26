#include <iostream>
#include "circle.cpp"

using namespace std;


int main(void) {
  CircleType c1(2, 3, 5);
  double x, y;
  cout << "Circle: " <<endl;
  
  c1.print();

  return 0;
}