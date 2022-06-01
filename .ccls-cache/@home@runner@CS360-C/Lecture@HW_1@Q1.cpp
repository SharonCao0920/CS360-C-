#include<iostream>
using namespace std;
class Complex {
   int real, img;
   public:
      //a constructor with no arguments (default constructor)
      Complex() {
         real = 0; img = 0;
      }
      //constructor with two arguments
      Complex(int r, int i) {
         real = r; img = i;
      }
      //constructor with const string&
      Complex(const string &s) {
         
      }

      void set();
      void get();
      void print();
      friend Complex add(Complex, Complex);
      friend Complex sub(Complex, Complex);
      int length(); 
      bool empty();
      int calMag (Complex);

};
void Complex::set() {
   cout << "Enter Real part: ";
   cin >> real;
   cout << "Enter Imaginary Part: ";
   cin >> img;
}
void Complex::get() {
   cout << "The complex number is: "<< real << "+" << img << "i" << endl;
}
void Complex::print() {
   if(img < 0)
      if(img == -1)
         cout << "The complex number is: "<< real << "-i" << endl;
      else
         cout << "The complex number is: "<< real << img << "i" << endl;
      else
         if(img == 1)
            cout << "The complex number is: "<< real << " + i"<< endl;
         else
            cout << "The complex number is: "<< real << " + " << img << "i" <<
   endl;
}
Complex add(complex c1, complex c2) {
   Complex res;
   res.real = c1.real + c2.real;//addition for real part
   res.img = c1.img + c2.img;//addition for imaginary part
   return res;//the result after addition
}
Complex sub(Complex c1, Complex c2) {
   Complex res;
   res.real = c1.real - c2.real;//subtraction for real part
   res.img = c1.img - c2.img;//subtraction for imaginary part
   return res;//the result after subtraction
}
int main(void) {
   Complex n1(3, 2), n2(4, -3);
   Complex result;
   result = add(n1,n2);
   result.print();
   result = sub(n1,n2);
   result.print();
}