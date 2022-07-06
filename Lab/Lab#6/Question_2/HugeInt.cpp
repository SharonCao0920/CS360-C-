#include <iostream>
using std::cout;
using std::endl;

#include <cctype>
using std::isdigit;
#include <cstring>
using std::strlen;

#include"Hugeint.h"

HugeInt::HugeInt( long value ){
  for ( int i = 0; i <= 29; i++ )
    integer[ i ] = 0; 
  for ( int j = 29; value != 0 && j >= 0; j-- ){
    integer[ j ] = value % 10;
    value /= 10;
  }
}

HugeInt::HugeInt( const char *string ){
  for ( int i = 0; i <= 29; i++ )
    integer[ i ] = 0;
  int length = strlen( string );
  for ( int j = 30 - length, k = 0; j <= 29; j++, k++ )
    if ( isdigit( string[ k ] ) )
      integer[ j ] = string[ k ] - '0';
}

int HugeInt::getLength() const{
  for ( int i = 0; i <= 29; i++ )
    if ( integer[ i ] != 0 )
      break;
  return 30 - i;
}

HugeInt HugeInt::operator+( const HugeInt &op2 ) const{
  HugeInt temp;
  int carry = 0;

  for ( int i = 29; i >= 0; i-- ){
    temp.integer[ i ] =integer[ i ] + op2.integer[ i ] + carry;
  if ( temp.integer[ i ] > 9 ){
    temp.integer[ i ] %= 10;  // reduce to 0-9
    carry = 1;
  }
  else
    carry=0;
  }
  return temp;
}

HugeInt HugeInt::operator+( int op2 ) const{
  return *this + HugeInt(op2);
}

HugeInt HugeInt::operator+( constchar *op2 ) const{
  return *this + HugeInt( op2 );
}

bool HugeInt::operator==( const HugeInt &op2 ) const{
  for ( int i = 0; i < 30; i++ )
    if ( op2.integer[ i ] != integer[ i ] )
      return false;
  return true;
}

bool HugeInt::operator!=( const HugeInt &op2 ) const{
  return !( *this == op2 );
}

bool HugeInt::operator<( const HugeInt &op2 ) const{
  for ( int i = 0; i < 30; i++ ){
    if ( integer[ i ] == op2.integer[ i ] )
      continue;
    else if ( integer[ i ] > op2.integer[ i ] )
      return false;
    else 
      return true;
  }
  return false;
}
bool HugeInt::operator<=( const HugeInt &op2 ) const{
  return ( ( *this == op2 ) || ( *this < op2 ) );
}

bool HugeInt::operator>( const HugeInt &op2 ) const{
  return !( *this <= op2 );
}

bool HugeInt::operator>=( const HugeInt &op2 ) const{
  return ( ( *this == op2 ) || ( *this > op2 ) );
}
ostream& operator<<( ostream &output, const HugeInt &num ){
  int i;
  for ( i = 0; ( num.integer[ i ] == 0 ) && ( i <= 29 ); i++ );
  if ( i == 30 )
    output << 0;
  else
    for ( ; i <= 29; i++ )
      output << num.integer[ i ];

  return output;
}

HugeInt HugeInt::operator-( const HugeInt &op2 ) const{
  if ( op2 > ( *this ) ){
    cout << "Error: Tried to subtract larger value from smaller value."<< endl;
    return HugeInt( "0" );
  }
  HugeInt result( "0" );
  bool minusOne = false;

  for ( int i = 29; i >= 0; i-- ){
    int topValue = ( *this ).integer[ i ];
    int bottomValue = op2.integer[ i ];

    if ( minusOne ){
      if ( topValue == 0 )
        topValue = 9;
      else{
        topValue -= 1;
        minusOne = false;
      }
    }
    if ( topValue >= bottomValue )
      result.integer[ i ] = topValue - bottomValue;
    else{
      topValue += 10;
      minusOne = true;
      result.integer[ i ] = topValue - bottomValue;
    } 
  }
  return result;
}

HugeInt HugeInt::operator*( const HugeInt &op2 ) const{
  int carryOver = 0;
  HugeInt total( "0" );
HugeInt smaller = ( *this < op2 ) ? *this : op2;
  HugeInt larger = ( *this > op2 ) ? *this : op2;

  for ( int x = 0; ( x <= 29 ) && ( larger.integer[ x ] == 0 ); x++ ) ;
  int indexOfFirstDigitForLarger = x;
  for ( int i = 30; i > 30 - smaller.getLength(); i-- ){
    HugeInt currentInt( "0" );
    int currentIntFrontHandle = i - 1;
    for ( int j = 30; j > 30 - larger.getLength(); j-- ){
      int currentResult = carryOver +( larger.integer[ j - 1 ] * smaller.integer[ i - 1 ] );
      if ( j - 1 == indexOfFirstDigitForLarger ){
        carryOver = 0;
        currentInt.integer[ currentIntFrontHandle ] =currentResult % 10;
        currentIntFrontHandle -= 1;
        currentInt.integer[ currentIntFrontHandle ] =currentResult / 10;
        currentIntFrontHandle -= 1;
      }
      else{
        carryOver = currentResult / 10;
        currentInt.integer[ currentIntFrontHandle ] =currentResult % 10;
        currentIntFrontHandle -= 1;
      }
    }
    total = total + currentInt;
  }
  return total;
}

HugeInt HugeInt::operator/( const HugeInt &op2 ) const{
  HugeInt remainderIntegers( *this );
  HugeInt currentValue( "0" );
  HugeInt result( "0" );

  int maxSolutionLength = ( *this ).getLength();
  for ( int i = 30 - maxSolutionLength; i < 30; i++ ){
    currentValue = currentValue * HugeInt( "10" );
    currentValue.integer[ 29 ] = remainderIntegers.integer[ i ];
    HugeInt tempResult( "0" );
    if ( op2 > currentValue )
      result.integer[ i ] = 0;
    else{
      for ( int j = 1; j <= 10; j++ ){
        HugeInt tempProduct = op2 * HugeInt( j );
        if ( tempProduct > currentValue )
          break;
      }
      result.integer[ i ] = j - 1;
      tempResult = op2 * HugeInt( j - 1 );
    }
    currentValue = currentValue - tempResult;
  }
  return result;
}

























