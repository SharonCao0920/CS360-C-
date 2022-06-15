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