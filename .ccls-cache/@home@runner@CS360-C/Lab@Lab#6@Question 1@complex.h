include<string>
#include<iostream>
using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{
public:
   explicit Complex(double = 0.0, double = 0.0);
   Complex operator+(const Complex&) const;
   Complex operator-(const Complex&) const;
   Complex operator*(const Complex&) const;
   Complex operator/(const Complex&) const;
   friend istream& operator>>(istream & input, Complex & cNumber);
   friend ostream& operator<<(ostream & output, const Complex & cNumber);
   bool operator== (const Complex &) const;
   bool operator!= (const Complex &) const;
private:
   double real;
   double imaginary;
};
#endif // !COMPLEX_H