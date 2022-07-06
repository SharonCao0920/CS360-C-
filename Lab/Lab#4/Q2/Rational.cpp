#include <iostream>
#include "Rational.h"
using namespace std;      

Rational::Rational(int a, int b){
  numerator = a;   
  denominator = b; 
  reduction();    
}               

//a. Adding two Rational numbers. The result should be stored in reduced form.
Rational Rational::addRational(const Rational & r) 
{
  Rational x; // creates Rational object to store value
  x.numerator = r.numerator * denominator + r.denominator * numerator;
  x.denominator = r.denominator * denominator;
  x.reduction(); 
  return x;
} 

//b. Subtracting two Rational numbers. The result should be stored in reduced form.
Rational Rational::subtractRational(const Rational & r)
{
  Rational x; // creates Rational object to store value
  x.numerator =  numerator * r.denominator - r.numerator * denominator;
  x.denominator = r.denominator * denominator;
  x.reduction(); // store the fraction in reduced form
  return x;
} 

//c. Multiplying two Rational numbers. The result should be stored in reduced form.
Rational Rational::multiplyRational(const Rational & r) 
{
  Rational x; // creates Rational object to store value
  x.numerator = r.numerator * numerator;
  x.denominator = r.denominator * denominator;
  x.reduction(); // store the fraction in reduced form
  return x;
}

//d. Dividing two Rational numbers. The result should be stored in reduced form.
Rational Rational::divideRational(const Rational & r) 
{
  Rational x; // creates Rational object to store value
  x.numerator = numerator * r.denominator;
  x.denominator = denominator * r.numerator;
  x.reduction(); // store the fraction in reduced form
  return x;
} 

//e. Printing Rational numbers in the form a/b, where a is the numerator and b is the denominator.
void Rational::printRational() 
{
  if (denominator == 0) {
    cout << "\nERROR!!! Denominator should not be 0" << endl;
  }
  else if (numerator == 0) {
    cout << "The number is: " << 0 <<endl;
  }
  else{
    cout << "The rational number is: " << numerator << '/' << denominator << endl;
  }
} 
//f. Printing Rational numbers in floating-point format.
void Rational::printRationalAsFloat() 
{
  cout << "The rational number in float is : " << static_cast < float > (numerator) / denominator << endl;
} 

void Rational::reduction() 
{
  int min;
  min = numerator < denominator ? numerator : denominator;
  int largestCom = 0; // largest common divisor
  for (int i = min; i >= 1; i--){
    if (numerator % i == 0 && denominator % i == 0){
      numerator /= i;
      denominator /= i;
      break;
    }
  }
} 