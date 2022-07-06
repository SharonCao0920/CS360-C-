#include <cctype> // isdigit function prototype
#include "HugeInt.h" // HugeInt class definition
//#include <math.h>
using namespace std;


// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt(long value)
{
// initialize array to zero
for (int i = 0; i < digits; ++i)
integer[i] = 0;

// place digits of argument into array
for (int j = digits - 1; value != 0 && j >= 0; --j)
{
integer[j] = value % 10;
value /= 10;
} // end for
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt(const string &number)
{
// initialize array to zero
for (int i = 0; i < digits; ++i)
integer[i] = 0;

// place digits of argument into array
int length = number.size();

for (int j = digits - length, k = 0; j < digits; ++j, ++k)
if (isdigit(number[k])) // ensure that character is a digit
integer[j] = number[k] - '0';
}

// overloaded output operator
ostream& operator<<(ostream& output, const HugeInt& num)
{
int i;

for (i = 0; (num.integer[i] == 0) && (i <= HugeInt::digits); ++i); // skip leading zeros

if (i == HugeInt::digits)
output << 0;
else
for (; i < HugeInt::digits; ++i)
output << num.integer[i];

return output;
}


// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+(const HugeInt &op2) const
{
HugeInt temp; // temporary result
int carry = 0;

for (int i = digits - 1; i >= 0; --i)
{
temp.integer[i] = integer[i] + op2.integer[i] + carry;

//carry a 1 if needed
carry = temp.integer[i] / 10;
temp.integer[i] %= 10;

if (carry > 0 && i == 0)
throw string("Overflow error!");
} // end for

return temp; // return copy of temporary object
} // end function operator+

//the subtraction operator overloaded
HugeInt HugeInt::operator-(const HugeInt &op2) const
{
HugeInt tempThis;
if (*this < op2)
{
tempThis = op2 - *this;
int x;
for (x = 0; x < digits && tempThis.integer[x] == 0; ++x);
tempThis.integer[x] *= -1;
return tempThis;
}
tempThis = *this;

HugeInt temp;
int carry = 0;
for (int i = digits - 1; i >= 0; --i)
{
//carrying a 10 from the next digit if needed
if (tempThis.integer[i] < op2.integer[i])
{
tempThis.integer[i] += 10;
tempThis.integer[i - 1] -= 1;
}
//setting the result
temp.integer[i] = tempThis.integer[i] - op2.integer[i] + carry;

//getting the carryover variable
carry = temp.integer[i] / 10;
//making sure every digit is 0-9
temp.integer[i] %= 10;

}
return temp;
}


//the multiplication operator overloaded
HugeInt HugeInt::operator*(const HugeInt &op2) const
{
//getting the divisor lenth
int x, y, op1L, op2L;
for (x = 0; x < digits && op2.integer[x] == 0; ++x);

op2L = digits - x;

//getting the dividend length
for (y = 0; y < digits && integer[y] == 0; ++y);

op1L = digits - y;

if (op1L + op2L >= digits)
throw string("Overflow error!");

HugeInt res;

int temp, carry, i , j;
//loop for first HugeInt
for (i = 0; i < digits; ++i)
{
carry = 0;
//loop for second HugeInt
for (j = digits - 1; j >= i; --j)
{

//calculating the result for each digit
temp = res.integer[j - i] + integer[j] * op2.integer[digits -1-i] + carry;
//getting the carry over variable
carry = temp/10;

//making sure each digit is 0-9
res.integer[j-i] = temp % 10;
}
}

return res;
}

//LONG DIVISION
HugeInt HugeInt::operator/(const HugeInt& op2) const
{
HugeInt result;
//throwing the dividing by zero exception
if (op2 == 0) throw string("Error: Dividing by zero");

//if we are dividing by a number greater, we will return 0
if (op2 > * this) return result;

HugeInt temp, multiplied;
int i, j,
divisorLength, dividendLength, resultLength,
quotient, resIndex, dividendIndex;

//getting the divisor lenth
for (i = 0; i < digits && op2.integer[i] == 0; ++i);

divisorLength = digits - i;

//getting the dividend length
for (j = 0; j < digits && integer[j] == 0; ++j);

dividendLength = digits - j;

//setting the temporary HugeInt to the part of the dividend of length equal to the divisor
for (int t = digits-divisorLength; j < digits - dividendLength + divisorLength; ++j, ++t)
temp.integer[t] = integer[j];

//getting the result length
resultLength = dividendLength - divisorLength;// +(temp >= op2);
resIndex = digits - resultLength - 1;
dividendIndex = digits - dividendLength + divisorLength;

//looping through the dividend
while (dividendIndex <= digits)
{
quotient = 0;
multiplied = 0;
if (op2 <= temp)
{

//multiplying the a HugeInt until we reach the temp HugeInt and keeping track of the times we multiplied... this wil be the divison
while (multiplied+op2 <= temp)
{
++quotient;
multiplied = multiplied + op2;
}
}

//setting the result at the index
result.integer[resIndex] = quotient;

//setting the next temp by subtracting the variable we multiplied up to it and addng the next digit
if (dividendIndex != digits)
{
if (quotient != 0)
temp = (temp - multiplied);
temp = temp * 10;

temp = temp + integer[dividendIndex];

++resIndex;
}
++dividendIndex;
}

return result;
}

//setter using the assignmnet operator
void HugeInt::operator=(const HugeInt & op2)
{
for (int i = 0; i < digits; ++i)
integer[i] = op2.integer[i];
}

//less than operator overloaded
bool HugeInt::operator<(const HugeInt& op2) const
{
int i;
//moving down all the 0's
for (i = 0; i < digits && integer[i] == 0; ++i) {
//if we reach a non-zero in the second operand, then this hugeint is smaller
if (op2.integer[i] != 0)
return true;
}
//moving down until we reach an unequal digit in the two operands
for (; i < digits && integer[i] == op2.integer[i]; ++i);

return integer[i] < op2.integer[i];
}

//equlity operator overloaded
bool HugeInt::operator==(const HugeInt& op2) const
{
for (int i = 0; i < digits; ++i)
if (integer[i] != op2.integer[i])
return false;
return true;
}