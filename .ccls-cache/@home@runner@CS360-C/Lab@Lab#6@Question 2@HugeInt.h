#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
friend ostream &operator<<(ostream &, const HugeInt &);
public:
static const int digits = 150; // maximum digits in a HugeInt

HugeInt(long = 0); // conversion/default constructor
HugeInt(const string &); // conversion constructor

// addition operator
HugeInt operator+(const HugeInt &) const;
HugeInt operator+(long op2) const { return *this + HugeInt(op2); }
HugeInt operator+(const string & op2) const { return *this + HugeInt(op2); }

// subtraction operator
HugeInt operator-(const HugeInt &) const;
HugeInt operator-(long op2) const { return *this - HugeInt(op2); }
HugeInt operator-(const string & op2) const { return *this - HugeInt(op2); }

// multiplication operator
HugeInt operator*(const HugeInt &) const;
HugeInt operator*(long op2) const { return *this * HugeInt(op2); }
HugeInt operator*(const string & op2) const { return *this * HugeInt(op2); }

// division operator
HugeInt operator/(const HugeInt &) const;
HugeInt operator/(long op2) const { return *this / HugeInt(op2); }
HugeInt operator/(const string & op2) const { return *this / HugeInt(op2); }

// assignment operator
void operator=(const HugeInt &);
void operator=(long op2) { *this = HugeInt(op2); }
void operator=(const string& op2) { *this = HugeInt(op2); }

//less than overloaded operator
bool operator<(const HugeInt &) const;
bool operator<(const string& op2) const { return *this < HugeInt(op2); }
bool operator<(long op2) const { return *this < HugeInt(op2); }

//greater than overloaded operator
bool operator>(const HugeInt & op2) const { return !(*this <= op2); }
bool operator>(const string& op2) const { return *this < HugeInt(op2); }
bool operator>(long op2) const { return *this < HugeInt(op2); }

//equal to overloaded operator
bool operator==(const HugeInt &) const;
bool operator==(const string& op2) const { return *this < HugeInt(op2); }
bool operator==(long op2) const { return *this < HugeInt(op2); }

//less than or equal tooverloaded operator
bool operator<=(const HugeInt& op2) const { return *this < op2 || *this == op2; }
bool operator<=(const string& op2) const { return *this < HugeInt(op2); }
bool operator<=(long op2) const { return *this < HugeInt(op2); }

//greater than or equal to overloaded operator
bool operator>=(const HugeInt & op2) const { return !(*this < op2); }
bool operator>=(const string& op2) const { return *this < HugeInt(op2); }
bool operator>=(long op2) const { return *this < HugeInt(op2); }

private:
short integer[digits];
};

#endif