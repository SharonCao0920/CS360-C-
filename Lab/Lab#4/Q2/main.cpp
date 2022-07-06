/*
2.Generate a class called Rational to perform arithmetic with fractions. Write a program to test your class. Use integer variables to represent the private data of the class--the numerator and the denominator. Provide a constructor that enables an object of this class to be initialized when it’s declared. The constructor should contain default values in case no initializers are provided and should store the fraction in reduced form. For example,2/4, the fraction would be stored in the object as 1 in the numerator and 2 in the denominator. Provide public member functions that perform each of the following tasks:
a.Adding two Rational numbers. The result should be stored in reduced form.
b.Subtracting two Rational numbers. The result should be stored in reduced form.
c.Multiplying two Rational numbers. The result should be stored in reduced form.
d.Dividing two Rational numbers. The result should be stored in reduced form.
e.Printing Rational numbers in the form a/b, where a is the numerator and b is the denominator.
f.Printing Rational numbers in floating-point format.
*/

#include <iostream>
#include "Rational.cpp"

using namespace std;

int main(void){
  int a, b, x, y;
  cout << "Please enter numeritor and denominator for first rational: " << endl;
  cin >> a >> b;
  cout << "Please enter numeritor and denominator for second rational: " << endl;
  cin >> x >> y;
  Rational c(a,b), d(x, y), t; 
  //print 2 rationals
  c.printRational();
  d.printRational();
  t.printRational();

  //addtion
  t = c.addRational(d);
  t.printRational();
  t.printRationalAsFloat();

  //substract
  t = c.subtractRational(d);
  t.printRational();
  t.printRationalAsFloat();

  //Multiply
  t = c.multiplyRational(d);
  t.printRational();
  t.printRationalAsFloat();

  //Divide
  t = c.divideRational(d);
  t.printRational();
  t.printRationalAsFloat();

  return 0;
} 