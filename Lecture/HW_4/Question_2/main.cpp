#include "poly.h"

int main(void){

  Polynomial p1, p2, p3, p4, p5;
  p1.readTerms();
  p2.readTerms();
  
  p3 = p1 + p2;
  p4 = p1 - p2;
  p5 = p1 * p2;
  
  
  cout << "p1: ";
  p1.print();
  
  cout << "p2: ";
  p2.print();
  
  cout << "\np1 + p2: ";
  p3.print();
  
  cout << "\np1 - p2: ";
  p4.print();
  
  cout << "\np1 * p2: ";
  p5.print();
  
  cout << endl;

  return 0;
}