#include "Complex.h"

#include<iostream>
using std::ostream;
using std::istream;


Complex::Complex ( double realPart, double imaginaryPart): real (realPart), imaginary(imaginaryPart){}

Complex Complex::operator+( const Complex &operand2) const{
  return Complex (real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-( const Complex &operand2) const{
  return Complex (real - operand2.real, imaginary - operand2.imaginary);
}

Complex Complex::operator*( const Complex &operand2) const{
  return Complex (( real * operand2.real ) + ( imaginary * operand2.imaginary ),( real * operand2.imaginary ) + ( imaginary * operand2.real ));
}

Complex& Complex::operator=( const Complex &right){
  real = rigiht.real;
  imaginary = right.imaginary;
  return *this;
}

bool Complex::operator==( const Complex &right ) const{ 
  return (right.real == real) && (right.imaginary == imaginary)? true : false;
}

bool Complex::operator!=( const Complex &right ) const{
  return !( *this == right ); 
}

ostream& operator<<( ostream &output, const Complex &complex ){
  output << "(" << complex.real << ", " << complex.imaginary << ")";
  return output;
}

istream& operator>>( istream &input, Complex &complex ){
  input.ignore();
  input >> complex.real;
  input.ignore( 2 ); 
  input >> complex.imaginary;
  input.ignore(); 
  return input;
}

void Complex::print() const{
  cout << '(' << real << ", " << imaginary << ')';
}