// Complex.cpp : Defines the entry point for the console application.
//

#include "complex.h"

#include <iostream>

using namespace std;

// Constructor

Complex::Complex(double realPart, double imaginaryPart): real(realPart), imaginary(imaginaryPart)  {}

// Addition (+) operator

Complex Complex::operator+(const Complex &operd2) const{
   return Complex(real + operd2.real,imaginary + operd2.imaginary);
}

// Subtraction (-) operator

Complex Complex::operator-(const Complex &operd2) const

{

   return Complex(real - operd2.real,

       imaginary - operd2.imaginary);

}

// Multiplication (*) operator

Complex Complex::operator*(const Complex &operd2) const

{

   return Complex(

       (real * operd2.real) - (imaginary * operd2.imaginary),

       (real * operd2.imaginary) + (imaginary * operd2.real));

}

Complex Complex::operator/(const Complex &operd2) const

{

   return Complex(

       (((real * operd2.real) + (imaginary * operd2.imaginary))/((operd2.real*operd2.real) + (operd2.imaginary*operd2.imaginary))),

       ((-(real * operd2.imaginary) + (imaginary * operd2.real))/((operd2.real*operd2.real)+(operd2.imaginary*operd2.imaginary))));

}

// Overloaded = operator

Complex& Complex::operator=(const Complex &right)

{

   real = right.real;

   imaginary = right.imaginary;

   return *this; // enables concatenation

} // end function operator=

bool Complex::operator==(const Complex &right) const

{

   return (right.real == real) && (right.imaginary == imaginary)

       ? true : false;

}

bool Complex::operator!=(const Complex &right) const

{

   return !(*this == right);

} // end function operator!=

ostream& operator<<(ostream &output, const Complex &complex)

{

   output << "(" << complex.real << ", " << complex.imaginary << ")";

   return output;

}

istream& operator >> (istream &input, Complex &complex)

{

   input.ignore();

   input >> complex.real;

   input.ignore();
   // not reading the imaginary value here
   input >> complex.imaginary;
   input.ignore();

   return input;

}

// Overloaded = operator

Complex& Complex::operator=(const Complex &right)

{

   real = right.real;

   imaginary = right.imaginary;

   return *this; // enables concatenation

} // end function operator=

bool Complex::operator==(const Complex &right) const

{

   return (right.real == real) && (right.imaginary == imaginary)

       ? true : false;

}

bool Complex::operator!=(const Complex &right) const

{

   return !(*this == right);

} // end function operator!=

ostream& operator<<(ostream &output, const Complex &complex)

{

   output << "(" << complex.real << ", " << complex.imaginary << ")";

   return output;

}

istream& operator >> (istream &input, Complex &complex)

{

   input.ignore();

   input >> complex.real;

   input.ignore();
   // not reading the imaginary value here
   input >> complex.imaginary;
   input.ignore();

   return input;

}