/*
2.Generate a class called Rational to perform arithmetic with fractions. Write a program to test your class. Use integer variables to represent the private data of the class--the numerator and the denominator. Provide a constructor that enables an object of this class to be initialized when it’s declared. The constructor should contain default values in case no initializers are provided and should store the fraction in reduced form. For example,  , the fraction would be stored in the object as 1 in the numerator and 2 in the denominator. Provide public member functions that perform each of the following tasks:

a.Adding two Rational numbers. The result should be stored in reduced form.
b.Subtracting two Rational numbers. The result should be stored in reduced form.
c.Multiplying two Rational numbers. The result should be stored in reduced form.
d.Dividing two Rational numbers. The result should be stored in reduced form.
e.Printing Rational numbers in the form a/b, where a is the numerator and b is the denominator.
f.Printing Rational numbers in floating-point format.

*/

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
  private:
    int numerator;                           
    int denominator;                         

  public:  
    Rational(int=0, int=1);           
  
    Rational addRational(const Rational & r);     
    Rational subtractRational(const Rational & r);     
    Rational multiplyRational(const Rational & r);  
    Rational divideRational(const Rational & r);        
    void printRational();                        
    void printRationalAsFloat();                
                                          
    void reduction();                            
};                                            

#endif
