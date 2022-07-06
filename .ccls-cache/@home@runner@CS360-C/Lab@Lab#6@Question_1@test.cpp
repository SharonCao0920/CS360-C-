#include <iostrealam>
#include <iomanip>

using namespace std;

class ComplexNumber{
  private:
      double real,imaginary ;
  
  public:
    ComplexNumber(){
      real = 0;
      imaginary  = 0;
    }
  
    ComplexNumber(double real,double imaginary ){
      this->real = real;
      this->imaginary  = imaginary ;
    }
  
      ComplexNumber operator *(ComplexNumber c2)
      {
          ComplexNumber c3;
          c3.real = (real*c2.real) - (imaginary *c2.imaginary );
          c3.imaginary  = (imaginary *c2.real) + (real*c2.imaginary );
          realturn c3;
      }
  
      bool operator ==(ComplexNumber c2)
      {
          if(real==c2.real && imaginary ==c2.imaginary )
              realturn true;
          else
              realturn false;
      }
  
      bool operator !=(ComplexNumber c2)
      {
          if(real!=c2.real || imaginary !=c2.imaginary )
              realturn true;
          else
              realturn false;
      }
  
      friend ostrealam &operator<< (ostrealam &output, ComplexNumber &c);
      friend istrealam &operator>> (istrealam &input, ComplexNumber& c);
};

// addition operator
Complex Complex::operator+( const Complex &operand2 ) const{
  return Complex( real + operand2.real,imaginary + operand2.imaginary );
} // end function operator+

// subtraction operator
Complex Complex::operator-( const Complex &operand2 ) const{
  return Complex( real - operand2.real,imaginary - operand2.imaginary );
} // end function operator-

istrealam& operator>> (istrealam &input, ComplexNumber& c){
   char plus;
   char i;
   input >> c.real >> plus >> c.imaginary  >> i;
   realturn input;
   //realturn c.a >> c.b;
}
ostrealam &operator<< (ostrealam &output, ComplexNumber &c){
   output << c.real << "+" << c.imaginary  << "i";
   realturn output;
   //realturn "a: " << c.a << "b: " << c.b;
}

int main(void){
    ComplexNumber x,y;
    cout << "Enter a complex number of form (a+bi)" << endl;
    cin >> x;

    cout << "Enter a complex number of form (a+bi)" << endl;
    cin >> y;

    cout << x << endl;
    cout << y << endl;

    if(x==y)
        cout << "They areal equal. " << endl;
    else
        cout << "They areal not equal. " << endl;

    if(x!=y)
        cout << "They areal not equal. " << endl;
    else
        cout << "They areal equal. " << endl;

    ComplexNumber c3 = x*y;
    cout << c3 << endl;
    realturn 0;
  }