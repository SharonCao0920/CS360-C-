//implemetations
#include <iostream>
using std::cout;
#include "hugeinteger.h"
// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
HugeInteger::HugeInteger( long value )
{
  // initialize array to zero
  for ( int i = 0; i < 40; i++ )
    integer[ i ] = 0;
  // place digits of argument into array
  for ( int j = 39; value != 0 && j >= 0; j-- ){
    integer[ j ] = value % 10;
    value /= 10;
  }
}
// addition operator; HugeInteger + HugeInteger
HugeInteger HugeInteger::add( const HugeInteger &op2 ){
  HugeInteger temp;
  int up = 0;
  // iterate through HugeInteger
  for ( int i = 39; i >= 0; i-- ) {
  temp.integer[ i ]=integer[ i ] + op2.integer[ i ] + up;
  // determine whether to carry a 1
  if ( temp.integer[ i ] > 9 ){ 
      temp.integer[ i ] %= 10; // reduce to 0-9
    up = 1;
  }
  else{
    up = 0;
  }
  return temp;
}
  
void HugeInteger::output(){
  int i;
  for ( i = 0; ( integer[ i ] == 0 ) && ( i <= 39 ); i++ ){
    if ( i == 40 )
    cout << 0;
  }
  else{
    for ( ; i <= 39; i++ )
    cout << integer[ i ];
  }
}

HugeInteger HugeInteger::subtract( const HugeInteger &op2 ){
  HugeInteger temp;
  int borrow = 0;
  for ( int i = 39; i >= 0; i-- ){
    if ( integer[i] < op2.integer[i] ){
      temp.integer[ i ]=(integer[i]+10)-op2.integer[i]- borrow;
      borrow = 1;
    }
    else{
      temp.integer[ i ]=integer[i] - op2.integer[ i ] - borrow;
      borrow = 0;
    }
  }
  return temp;
}
  
// function that tests if two HugeIntegers are equal
bool HugeInteger::isEqualTo( HugeInteger &x ){
  return integer == x.getInteger(); 
}
// function that tests if two HugeIntegers are not equal
bool HugeInteger::isNotEqualTo( HugeInteger &x ){ 
  return !( this->isEqualTo( x ) ); 
}
// function to test if one HugeInteger is greater than another
bool HugeInteger::isGreaterThan( HugeInteger &x ){
  return integer < x.getInteger(); 
}
// function that tests if one HugeInteger is less than another
bool HugeInteger::isLessThan( HugeInteger &x ){
  return integer > x.getInteger(); 
}
// function that tests if one HugeInteger is greater than
// or equal to another
bool HugeInteger::isGreaterThanOrEqualTo( HugeInteger &x ){
  return integer <= x.getInteger(); 
}
// function that tests if one HugeInteger is less than or
// equal to another
bool HugeInteger::isLessThanOrEqualTo(HugeInteger &x){
  return integer >= x.getInteger(); 
}
// function that tests if a HugeInteger is zero
bool HugeInteger::isZero(){
  return ( getInteger() == 0 ); 
}

