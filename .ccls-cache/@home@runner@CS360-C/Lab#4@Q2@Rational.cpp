#include <iostream>
#include "Rational.h"
using std::cout;

Rational::Rational(int a, int b)
{
  numerator = a;   // sets numerator
  denominator = b; // sets denominator
  reduction();     // store the fraction in reduced form
}                  // end Rational constructor

//a. Adding two Rational numbers. The result should be stored in reduced form.
Rational Rational::addition(const Rational & x) 
{
  Rational t; // creates Rational object
  t.numerator = x.numerator * denominator;
  t.numerator += x.denominator * numerator;
  t.denominator = x.denominator * denominator;
  t.reduction(); // store the fraction in reduced form
  return t;
} 

//b. Subtracting two Rational numbers. The result should be stored in reduced form.
Rational Rational::subtraction(const Rational & s)
{
  Rational t; // creates Rational object
  t.numerator = s.denominator * numerator;
  t.numerator -= denominator * s.numerator;
  t.denominator = s.denominator * denominator;
  t.reduction(); // store the fraction in reduced form
  return t;
} 

//c. Multiplying two Rational numbers. The result should be stored in reduced form.
Rational Rational::multiplication(const Rational & m) 
{
  Rational t; // creates Rational object
  t.numerator = m.numerator * numerator;
  t.denominator = m.denominator * denominator;
  t.reduction(); // store the fraction in reduced form
  return t;
}

//d. Dividing two Rational numbers. The result should be stored in reduced form.
Rational Rational::division(const Rational & v) 
{
  Rational t; // creates Rational object
  t.numerator = v.denominator * numerator;
  t.denominator = denominator * v.numerator;
  t.reduction(); // store the fraction in reduced form
  return t;
} 

//e. Printing Rational numbers in the form a/b, where a is the numerator and b is the denominator.
void Rational::printRational() 
{
  if (denominator == 0) // validates denominator
    cout << "\nERROR!!! Denominator should not be 0" << '\n';
  else if (numerator == 0) // validates numerator
    cout << 0;
  else
    cout << numerator << '/' << denominator;
} 
//f. Printing Rational numbers in floating-point format.
void Rational::printRationalAsFloat() 
{
  cout << static_cast < float > (numerator) / denominator;
} 

void Rational::reduction() 
{
  int largest;
  largest = numerator > denominator ? numerator : denominator;
  int lcd = 0; // largest common divisor
  for (int loop = 2; loop <= largest; loop++)
    if (numerator % loop == 0 && denominator % loop == 0)
      lcd = loop;
  if (lcd != 0) {
    numerator /= lcd;
    denominator /= lcd;
  } 
} 