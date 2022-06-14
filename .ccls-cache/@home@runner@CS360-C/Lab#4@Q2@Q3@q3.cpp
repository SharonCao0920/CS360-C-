#include <iostream>
using std::cout; using std::endl;
#include "hugeint1.h"
int main()
{
HugeInteger n1( 7654321 );
HugeInteger n2( 7891234 );
HugeInteger n3;
HugeInteger n4( 5 );
HugeInteger n5;
n5 = n1.add( n2 );
n1.output();
cout << " + "; n2.output();
cout << " = "; n5.output();
cout << "\n\n";
n5 = n2.subtract( n4 );
n2.output();
cout<< " - "; n4.output();
cout << " = "; n5.output();
cout << "\n\n";
if ( n1.isEqualTo( n1 ) == true )
{n1.output();cout << " is equal "; n1.output(); cout << "\n\n";}
if ( n1.isNotEqualTo( n2 ) == true )
{n1.output();cout << " is not equal to ";n2.output();cout << "\n\n";}
if ( n2.isGreaterThan( n1 ) == true )
{n2.output();cout << " is greater than ";n1.output();cout <<"\n\n";}
if ( n2.isLessThan( n4 ) == true )
{n4.output();cout << " is less than ";n2.output();cout << "\n\n";}
if( n4.isLessThanOrEqualTo( n4 ) == true )
{n4.output();cout << " is less than or equal to ";n4.output();
cout << "\n\n";}
if ( n3.isGreaterThanOrEqualTo( n3 ) == true )
{n3.output();cout << " is greater than or equal to ";n3.output();
cout << "\n\n";}
if ( n3.isZero() != true )
{cout << "n3 contains value ";n3.output();cout << "\n\n";}
return 0;
}

//class definitions
#ifndef HUGEINT1_H
#define HUGEINT1_H
class HugeInteger {
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
short* getInteger()
{
return integer;
}
private:
short integer[ 40 ];
};
#endif
//implemetations
#include <iostream>
using std::cout;
#include "hugeint1.h"
// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
HugeInteger::HugeInteger( long value )
{
// initialize array to zero
for ( int i = 0; i < 40; i++ )
integer[ i ] = 0;
// place digits of argument into array
for ( int j = 39; value != 0 && j >= 0; j-- )
{
integer[ j ] = value % 10;
value /= 10;
}
}
// addition operator; HugeInteger + HugeInteger
HugeInteger HugeInteger::add( const HugeInteger &op2 )
{
HugeInteger temp;
int carry = 0;
// iterate through HugeInteger
for ( int i = 39; i >= 0; i-- ) {
temp.integer[ i ]=integer[ i ] + op2.integer[ i ] + carry;
// determine whether to carry a 1
if ( temp.integer[ i ] > 9 )
{ temp.integer[ i ] %= 10; // reduce to 0-9
carry = 1;}
else
carry = 0;}
return temp;
}
void HugeInteger::output()
{
int i;
for ( i = 0; ( integer[ i ] == 0 ) && ( i <= 39 ); i++ )
; // skip leading zeros
if ( i == 40 )
cout << 0;
else
for ( ; i <= 39; i++ )
cout << integer[ i ];
}
// function to subtract two HugeIntegers
HugeInteger HugeInteger::subtract( const HugeInteger &op2 )
{
HugeInteger temp;
int borrow = 0;
for ( int i = 39; i >= 0; i-- )
{// determine to add 10 to smaller integer
if ( integer[i] < op2.integer[i] )
{temp.integer[ i ]=(integer[i]+10)-op2.integer[i]- borrow;
borrow = 1;}
else
{temp.integer[ i ]=integer[i] - op2.integer[ i ] - borrow;
borrow = 0;}
}
return temp;
}
// function that tests if two HugeIntegers are equal
bool HugeInteger::isEqualTo( HugeInteger &x )
{ return integer == x.getInteger(); }
// function that tests if two HugeIntegers are not equal
bool HugeInteger::isNotEqualTo( HugeInteger &x )
{ return !( this->isEqualTo( x ) ); }
// function to test if one HugeInteger is greater than another
bool HugeInteger::isGreaterThan( HugeInteger &x )
{ return integer < x.getInteger(); }
// function that tests if one HugeInteger is less than another
bool HugeInteger::isLessThan( HugeInteger &x )
{ return integer > x.getInteger(); }
// function that tests if one HugeInteger is greater than
// or equal to another
bool HugeInteger::isGreaterThanOrEqualTo( HugeInteger &x )
{ return integer <= x.getInteger(); }
// function that tests if one HugeInteger is less than or
// equal to another
bool HugeInteger::isLessThanOrEqualTo( HugeInteger &x )
{ return integer >= x.getInteger(); }
// function that tests if a HugeInteger is zero
bool HugeInteger::isZero()
{ return ( getInteger() == 0 ); }
//main file
#include <iostream>
using std::cout; using std::endl;
#include "hugeint1.h"
int main()
{
HugeInteger n1( 7654321 );
HugeInteger n2( 7891234 );
HugeInteger n3;
HugeInteger n4( 5 );
HugeInteger n5;
n5 = n1.add( n2 );
n1.output();
cout << " + "; n2.output();
cout << " = "; n5.output();
cout << "\n\n";
n5 = n2.subtract( n4 );
n2.output();
cout<< " - "; n4.output();
cout << " = "; n5.output();
cout << "\n\n";
if ( n1.isEqualTo( n1 ) == true )
{n1.output();cout << " is equal "; n1.output(); cout << "\n\n";}
if ( n1.isNotEqualTo( n2 ) == true )
{n1.output();cout << " is not equal to ";n2.output();cout << "\n\n";}
if ( n2.isGreaterThan( n1 ) == true )
{n2.output();cout << " is greater than ";n1.output();cout <<"\n\n";}
if ( n2.isLessThan( n4 ) == true )
{n4.output();cout << " is less than ";n2.output();cout << "\n\n";}
if( n4.isLessThanOrEqualTo( n4 ) == true )
{n4.output();cout << " is less than or equal to ";n4.output();
cout << "\n\n";}
if ( n3.isGreaterThanOrEqualTo( n3 ) == true )
{n3.output();cout << " is greater than or equal to ";n3.output();
cout << "\n\n";}
if ( n3.isZero() != true )
{cout << "n3 contains value ";n3.output();cout << "\n\n";}
return 0;
}