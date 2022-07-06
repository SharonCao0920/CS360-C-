/*
3.Design & implement, and test a class Polynomial for Polynomialnomials. A Polynomialnomial has the form

You’ll need to use an object to store exponents and coefficients. You should implement a constructor that takes a coefficient and an exponent as arguments so that you can write

Polynomial c = Polynomial(3,4) + Polynomial(2,2) + Polynomial(7,1) + Polynomial(-5,0);

To get the Polynomialnomial, you should overload arithmetic operators
+=, -= and +, - for addition and subtraction. You should overload *= to multiply a Polynomialnomial by a constant: 

Finally, you should include a member function at, that evaluates a Polynomialnomial at a specific value for x. For example

Polynomial c = Polynomial(4,2) + Polynomial(3,1) + Polynomial(5,0); 	//

	double d = c.at(7)	// 
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Polynomial{
private:
    // using map to store the a, b  ==> ax^b
    map<double, double> acoeffb; 
    
public:
    Polynomial(){ }
    Polynomial(double coeff, double exp) { 
      // create a singleton item
      acoeffb[exp] = coeff;
    }

    // override the operator +
    Polynomial operator+(Polynomial const &obj) {
        Polynomial Polynomial;
        map<double, double> m(this->acoeffb);
        for (auto iter = obj.acoeffb.begin(); iter != obj.acoeffb.end(); iter++) {
            auto findIter = m.find(iter->first);
            if (findIter == m.end()) {
                m.insert(make_pair(iter->first, iter->second));
            } else {
                findIter->second += iter->second;
            }
        }
        Polynomial.acoeffb = m;
        return Polynomial;
    }

    // override the operator -
    Polynomial operator-(Polynomial const &obj) {
        Polynomial Polynomial;
        map<double, double> m(this->acoeffb);
        for (auto iter = obj.acoeffb.begin(); iter != obj.acoeffb.end(); iter++) {
            auto findIter = m.find(iter->first);
            if (findIter == m.end()) {
                m.insert(make_pair(iter->first, -1*iter->second));
            } else {
                findIter->second -= iter->second;
            }
        }
        Polynomial.acoeffb = m;
        return Polynomial;
    }

    // override += 
    Polynomial& operator+=(const Polynomial& obj) {
        *this = *this + obj;
        return *this;
    } 

    // override -= 
    Polynomial& operator-=(const Polynomial& obj) {
        *this = *this - obj;
        return *this;
    } 

    // override *= 
    Polynomial& operator*=(const double& x) {
        for (auto iter = acoeffb.begin(); iter != acoeffb.end(); iter++)
            iter->second *= x; 
        return *this;
    }


    // member function at 
    double at(double x) {
        // iterate through coefficients and find the value
        double value = 0.0;
        for (auto iter = acoeffb.begin(); iter != acoeffb.end(); iter++){
            value = value + iter->second * pow(x, iter->first);
        }
        // return the computed value
        return value;
    }`
