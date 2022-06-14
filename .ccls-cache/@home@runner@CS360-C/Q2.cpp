/*
Generate a class called Rational to perform arithmetic with fractions. Write a program to test your class. Use integer variables to represent the private data of the class--the numerator and the denominator. Provide a constructor that enables an object of this class to be initialized when it’s declared. The constructor should contain default values in case no initializers are provided and should store the fraction in reduced form. For example, 2/4 , the fraction would be stored in the object as 1 in the numerator and 2 in the denominator. Provide public member functions that perform each of the following tasks:
*/

#include <iostream>>

using namespace std;

class Rational{
  private:
  int numberitor, denominator;

  public:
  //default constructor
  Rational (int=0; int=1);

  int findLargestDivisor(int a, int b){
    int max;
    if ( a >= b ){
      max = a;
    }
    else{
      max = b;
    }
    for (int i = max; i>= a && i >= b; i--){
      if ( a%i == 0 && b%i ==0){
        return i;
      } 
    }
    return 0;
  }

  //a. Adding two Rational numbers. The result should be stored in reduced form.
  int add(int a, int b){
    int x = findLargestDivisor(a, b);
    if (x==0){
      return a+b;
    }
    else{
      return (a+b)/x
    }
  }

  //b. Subtracting two Rational numbers. The result should be stored in reduced form.
  int substract(int a, int b){
    int x = findLargestDivisor(a, b);
    if (x==0){
      return abs(a-b) ;
    }
    else{
      return abs((a-b)/x)
    }
  }

  //c. Multiplying two Rational numbers. The result should be stored in reduced form.
  int multiply(int a, int b){
    int x = findLargestDivisor(a, b);
    if (x==0){
      return a*b ;
    }
    else{
      return a*b/x
    }
  }
  
  //d. Dividing two Rational numbers. The result should be stored in reduced form.
  float divide(int a, int b){
    int x = findLargestDivisor(a, b);
    if (x==0){
      return static_cast< float >a/static_cast< float >b ;
    }
    else{
      return static_cast< float >a/static_cast< float >b/x
    }
  }

  //e. Printing Rational numbers in the form a/b, where a is the numerator and b is the denominator.
  void printRational(int a, int b){
    
  }
    
    //f. Printing Rational numbers in floating-point format.
  
}
  