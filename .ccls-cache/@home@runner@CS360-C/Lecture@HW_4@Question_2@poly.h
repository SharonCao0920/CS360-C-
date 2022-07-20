// Header files


#include <iostream>

using namespace std;

class Polynomial{
public:
  static const int MAX_TERMS = 100;
  Polynomial();
  ~Polynomial();
  int getExponent(int);
  int getCoefficient(int);
  void setTerm(int, int);
  Polynomial operator+(const Polynomial&) const;
  Polynomial operator-(const Polynomial&) const;
  Polynomial operator*(const Polynomial&);
  Polynomial operator=(const Polynomial&);
  Polynomial& operator+=(const Polynomial&);
  Polynomial& operator-=(const Polynomial&);
  Polynomial& operator*=(const Polynomial&);
  void readTerms();
  int getTermsCount();
  void print();

private:
  int expons[MAX_TERMS];
  int coeffs[MAX_TERMS];
  int termsCount;
  static void combineCommonTerms(Polynomial&);

};


