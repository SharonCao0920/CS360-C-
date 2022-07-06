#include"Complex.h"

Complex::Complex(double realPart, double imaginaryPart):real(realPart),imaginary(imaginaryPart){}

Complex Complex::operator+(const Complex & operand2)const
{
   return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex & operand2)const
{
   return Complex(real - operand2.real, imaginary - operand2.imaginary);
}
Complex Complex::operator*(const Complex& operand2) const
{
   return Complex((real*operand2.real) - (imaginary*operand2.imaginary), (imaginary*operand2.real) + (real*operand2.imaginary));
}
Complex Complex::operator/(const Complex& operand2) const
{
   Complex ans;
   ans.real = ((imaginary*operand2.imaginary) + (imaginary*operand2.imaginary)) / ((operand2.real*operand2.real) + (operand2.imaginary*operand2.imaginary));
   ans.imaginary = ((imaginary*operand2.real) - (real*operand2.imaginary)) / ((operand2.real*operand2.real) + (operand2.imaginary*operand2.imaginary));
   return ans;
}
istream& operator>>(istream & input, Complex & cNumber)
{
   double r, i;
  

   input >> r; //read real part

   input >> i; //read imaginary part

   if (input.good())
   {
       cNumber.real = r;
       cNumber.imaginary = i;
   }

   return input; // enable cin >> c1 >> c2 >> c3
}
ostream& operator<<(ostream & output, const Complex & cNumber)
{
   output << "(" << cNumber.real << ", " << cNumber.imaginary << ")";
   return output;
}
bool Complex::operator== (const Complex &right) const
{
   if (real == right.real && imaginary == right.imaginary)
       return true;
   return false;
}
bool Complex::operator!= (const Complex &right) const
{
   return !(*this == right);
}