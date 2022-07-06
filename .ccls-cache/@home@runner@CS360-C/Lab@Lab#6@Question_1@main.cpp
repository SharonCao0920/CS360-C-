// main.cpp
// Complex class test program.
#include <iostream>
#include "Complex.h"

using std::cout;
using std::cin;

int main(void){
  Complex x;
  Complex y( 4.3, 8.2 );
  Complex z( 3.3, 1.1 );

  cout << "x: ";
  x.print();
  cout << "\ny: ";
  y.print();
  cout << "\nz: ";
  z.print();
  
  x = y + z;
  cout << "\n\nx = y + z:" << endl;
  cout << " = ";
  y.print();
  cout << " + ";
  z.print();
  
  x = y - z;
  cout << "\n\nx = y - z:" << endl;
  x.print();
  cout << " = ";
  y.print();
  cout << " - ";
  z.print();
  cout << endl;
} // end main