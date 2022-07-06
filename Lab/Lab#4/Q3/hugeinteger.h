/*
3.Create a class HugeInteger that uses a 40-element array of digits to store integers as large as 40 digits each. Provide member functions input, output, add and subtract.For comparing HugeInteger objects, provide functions isEqualTo, isNotEqualTo, isGreaterThan, isLessThan, isGreaterThanOrEqualTo and isLessThanOrEqualTo--each of these is a "predicate " function that simply returns true if the relationship holds between the two HugeIntegers and returns false if the relationship does not hold. Also, provide a predicate function isZero. After that, provide member functions multiply, divide and modulus.
*/

//class definitions
#ifndef HUGEINT1_H
#define HUGEINT1_H
class HugeInteger {
private:
  int integer[ 40 ];
public:
  HugeInteger( long = 0 ); // conversion/default constructor
  HugeInteger add( const HugeInteger & );//addition operator; HugeInt + HugeInt
  HugeInteger subtract( const HugeInteger & );//subtraction operator; HugeInt - HugeInt
  
  bool isEqualTo( HugeInteger & );
  bool isNotEqualTo( HugeInteger & );
  bool isGreaterThan(HugeInteger & );
  bool isLessThan( HugeInteger & );
  bool isGreaterThanOrEqualTo( HugeInteger & );
  bool isLessThanOrEqualTo( HugeInteger & );
  bool isZero();
  void output();

  int* getInteger(){
    return integer;
  }
};
#endif