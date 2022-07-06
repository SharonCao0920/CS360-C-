#include <map> 
#include <iostream>
class Poly{
private:
    // stores the coeff, exp
    map<double, double> coeffOfExp;
    // private constructors
    Poly(){ }
public:
    // constructor 
    Poly(double coeff, double exp) { 
        // create a singleton item
        coeffOfExp[exp] = coeff;
    }

    // override the operator +
    Poly operator+(Poly const &obj) {
        Poly poly;
        map<double, double> m(this->coeffOfExp);
        for (auto iter = obj.coeffOfExp.begin(); iter != obj.coeffOfExp.end(); iter++) {
            auto findIter = m.find(iter->first);
            if (findIter == m.end()) {
                m.insert(make_pair(iter->first, iter->second));
            } else {
                findIter->second += iter->second;
            }
        }
        poly.coeffOfExp = m;
        return poly;
    }

    // override the operator -
    Poly operator-(Poly const &obj) {
        Poly poly;
        map<double, double> m(this->coeffOfExp);
        for (auto iter = obj.coeffOfExp.begin(); iter != obj.coeffOfExp.end(); iter++) {
            auto findIter = m.find(iter->first);
            if (findIter == m.end()) {
                m.insert(make_pair(iter->first, -1*iter->second));
            } else {
                findIter->second -= iter->second;
            }
        }
        poly.coeffOfExp = m;
        return poly;
    }

    // override += 
    Poly& operator+=(const Poly& obj) {
        *this = *this + obj;
        return *this;
    } 

    // override -= 
    Poly& operator-=(const Poly& obj) {
        *this = *this - obj;
        return *this;
    } 

    // override *= 
    Poly& operator*=(const double& x) {
        for (auto iter = coeffOfExp.begin(); iter != coeffOfExp.end(); iter++)
            iter->second *= x; 
        return *this;
    }


    // member function at 
    double at(double x) {
        // iterate through coefficients and find the value
        double value = 0.0;
        for (auto iter = coeffOfExp.begin(); iter != coeffOfExp.end(); iter++){
            value = value + iter->second * pow(x, iter->first);
        }
        // return the computed value
        return value;
    }


    // prints the polynomial
    // not relevant to problem statement there!
    void display() {
        vector<double> keys;
        for (auto iter = coeffOfExp.begin(); iter != coeffOfExp.end(); iter++)
            keys.push_back(iter->first);
        sort(keys.begin(), keys.end());
        int index = keys.size() - 1;
        while (index >= 0) {
            double exp = keys[index--];
            double coeff = coeffOfExp.find(exp)->second;
            cout << coeff << "x^" << exp << (index >= 0 ? " + " : " ");
        }
        cout << endl;
    }
};
