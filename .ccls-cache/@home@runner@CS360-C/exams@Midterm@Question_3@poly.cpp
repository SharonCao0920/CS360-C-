#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Polynomials{
private:
    // using map to store the coeff, exp
    map<double, double> acoeffb;
    
public:
    // constructors 
    Polynomials(){ }
    Polynomials(double coeff, double exp) { 
        acoeffb[exp] = coeff; //map key and value
    }

    // override the operator +
    Polynomials operator+(Polynomials const &obj) {
        Polynomials Polynomials;
        map<double, double> m (this->acoeffb); //map all the (exp, coeff)
        for (auto iter = obj.acoeffb.begin(); iter != obj.acoeffb.end(); iter++) {
            auto findIter = m.find(iter->first);
            if (findIter == m.end()) { 
              m.insert(make_pair(iter->first, iter->second));
            } 
            else {
              findIter->second += iter->second;
            }
        }
        Polynomials.acoeffb = m;
        return Polynomials;
    }

    // override the operator -
    Polynomials operator-(Polynomials const &obj) {
        Polynomials Polynomials;
        map<double, double> m (this->acoeffb);
        for (auto iter = obj.acoeffb.begin(); iter != obj.acoeffb.end(); iter++) {
            auto findIter = m.find(iter->first);
            if (findIter == m.end()) {
                m.insert(make_pair(iter->first, -1*iter->second));
            } 
            else {
              findIter->second -= iter->second;
            }
        }
        Polynomials.acoeffb = m;
    
        return Polynomials;
    }

    // override += 
    Polynomials& operator+=(const Polynomials& obj) {
      *this = *this + obj;
      return *this;
    } 

    // override -= 
    Polynomials& operator-=(const Polynomials& obj) {
      *this = *this - obj;
      return *this;
    } 

    // override *= 
    Polynomials& operator*=(const double& x) {
      for (auto iter = acoeffb.begin(); iter != acoeffb.end(); iter++)
          iter->second *= x; 
      return *this;
    }

    // member function at to return the function value when x at value
    double at(double x) {
        double value = 0.0;
        for (auto iter = acoeffb.begin(); iter != acoeffb.end(); iter++){
            value = value + iter->second * pow(x, iter->first);
        }
        return value;
    }
    //display "+"
    void display() {
        vector<double> keys;
        for (auto iter = acoeffb.begin(); iter != acoeffb.end(); iter++)
            keys.push_back(iter->first);
        sort(keys.begin(), keys.end());
        int index = keys.size() - 1;
        while (index >= 0) {
            double exp = keys[index--];
            double coeff = acoeffb.find(exp)->second;
            cout << coeff << "x^" << exp << (index >= 0 ? " + " : " ");
        }
        cout << endl;
    }

    //display "-"
    void display_() {
        vector<double> keys;
        for (auto iter = acoeffb.begin(); iter != acoeffb.end(); iter++)
            keys.push_back(iter->first);
        sort(keys.begin(), keys.end());
        int index = keys.size() - 1;
        while (index >= 0) {
            double exp = keys[index--];
            double coeff = acoeffb.find(exp)->second;
            cout << coeff << "x^" << exp << (index >= 0 ? " " : " ");
        }
        cout << endl;
    }
};

int main(void) {

  Polynomials f = Polynomials(2, 3) + Polynomials(6, -2) + Polynomials(9, 0);
  cout << "f(x) = ";
  f.display();


  Polynomials g = Polynomials(4, 7) - Polynomials(9, -1) - Polynomials(3, 1);
  cout << "g(x) = ";
  g.display_();

  Polynomials f1;
  f1 += Polynomials(9, 4);
  f1 += Polynomials(3, 5);
  f1 += Polynomials(2, 3);
  cout << "f1(x) = ";
  f1.display();

  // verify -= 
  Polynomials f2;
  f2 -= Polynomials(4, 4);
  f2 -= Polynomials(5, -2);
  f2 -= Polynomials(3, 1);
  cout << "f2(x) = ";
  f2.display_();

  // verfify the *
  f *= 2;
  cout << "2*f(x) = ";
  f.display();
  
  g *= 2;
  cout << "2*g(x) = ";
  g.display();

  f1 *= 2;
  cout << "2*f1(x) = ";
  f1.display();

  f2 *= 2;
  cout << "2*f2(x) = ";
  f2.display();
  
  // verify the at
  cout << "f(5) = " << f.at(5) << endl;

  // successful termination
  return 0;
}