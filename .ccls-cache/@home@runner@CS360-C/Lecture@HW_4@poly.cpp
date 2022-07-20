// Polynomial class
#include "poly.h"

Polynomial::Polynomial(){
  for(int i = 0; i < MAX_TERMS; i++){
    coeffs[i] = 0;
    expons[i] = 0;
  }
  termsCount = 0;
}
  
Polynomial::~Polynomial(){}

int Polynomial::getExponent(int index){
  return expons[index];
}

int Polynomial::getCoefficient(int index){
  return coeffs[index];
}

void Polynomial::setTerm(int index, int coef){
  if(coeffs[index] == 0)
    cout << "Invalid Index!" << endl;
  else
    coeffs[index] = coef;
}

Polynomial Polynomial::operator+(const Polynomial& rhs) const{
  Polynomial newPoly;
  bool isExpo;
  int i, j, k;
  newPoly.coeffs[0] = coeffs[0] + rhs.coeffs[0];
  for(i = 1; i < MAX_TERMS && rhs.expons[i] != 0; i++){
    newPoly.coeffs[i] = rhs.coeffs[i];
    newPoly.expons[i] = rhs.expons[i];
  }
  
  for(j = 1; j < MAX_TERMS; j++){
    isExpo = false;
    for(int k = 1; k < MAX_TERMS && !isExpo; k++){
      if(expons[j] == newPoly.expons[k] ){
        newPoly.coeffs[k] += coeffs[j];
          isExpo = true;
      }
    }

    if(!isExpo){
      newPoly.expons[i] = expons[j];
      newPoly.coeffs[i] += coeffs[j];
      i++;
    }
  }
  return newPoly;
}

Polynomial Polynomial::operator-(const Polynomial& rhs) const{
  Polynomial newPoly;
  bool isExpo;
  int i, j, k;
  
  newPoly.coeffs[0] = coeffs[0] - rhs.coeffs[0];
  
  for(i = 1; i < MAX_TERMS && expons[i] != 0; i++){
    newPoly.coeffs[i] = coeffs[i];
    newPoly.expons[i] = expons[i];
  }
  
  for(j = 1; j < MAX_TERMS; j++){
    isExpo = false;
    
    for(k = 1; k < MAX_TERMS && !isExpo; k++){
      if(rhs.expons[j] == newPoly.expons[k]){
        newPoly.coeffs[k] -= rhs.coeffs[j];
        isExpo = true;
      }
    }
  
    if(!isExpo){
      newPoly.expons[i] = rhs.expons[j];
      newPoly.coeffs[i] -= rhs.coeffs[j];
      i++;
    }
  }
  return newPoly;
}

Polynomial Polynomial::operator*(const Polynomial& rhs){
  Polynomial newPoly;
  int i = 1, j, k;
  for(j = 0; j < MAX_TERMS && (j == 0 || coeffs[j] != 0); j++){
    for(k = 0; k < MAX_TERMS && ( k == 0 || rhs.coeffs[ k] != 0 ); k++ ){
      if ( coeffs[ j ] * rhs.coeffs[ k] ){
        if ( ( expons[j ] == 0 ) && ( rhs.expons[k] == 0 ) )
          newPoly.coeffs[ 0 ] += coeffs[ j] * rhs.coeffs[k];
        else{
          newPoly.coeffs[ i ] = coeffs[j] * rhs.coeffs[ k ];
          newPoly.expons[ i ] = expons[j] + rhs.expons[k];
          i++;
        }
      }
    }
  }
  combineCommonTerms( newPoly );
  return newPoly;
}

Polynomial Polynomial::operator=(const Polynomial& rhs){
  expons[ 0 ] = rhs.expons[ 0 ];
  coeffs[ 0 ] = rhs.coeffs[ 0 ];
  int i;
  for ( i = 1; i < MAX_TERMS; i++ ){
    if ( rhs.expons[i ] != 0 ){
      expons[i] = rhs.expons[i];
      coeffs[i] = rhs.coeffs[i];
    }
    else{
      if ( expons[i] == 0 )
      break;
      expons[i] = 0;
      coeffs[i] = 0;
    }
  }
  return *this;
}

Polynomial &Polynomial::operator+=( const Polynomial &rhs){
  *this = *this + rhs;
  return *this;
}

Polynomial &Polynomial::operator-=( const Polynomial& rhs ){
  *this = *this - rhs;
  return *this;
}

Polynomial &Polynomial::operator*=( const Polynomial& rhs ){
  *this = *this * rhs;
  return *this;
}

void Polynomial::readTerms(){
  int i, ct, et;
  int count;
  bool found = false;
  cout << "\nEnter number of terms in polynomial: ";
  cin >> termsCount;
  
  for ( i = 1; i <= termsCount; i++ ){
    cout << "\nEnter coefficient: ";
    cin >> ct;
    cout << "Enter exponent: ";
    cin >> et;
    if ( ct != 0 ){
      if ( et == 0 ){
      coeffs[ 0 ] += ct;
      continue;
      }
      for ( count = 1; ( count < 100 ) && ( coeffs[ count ] != 0 ); count++ ){
        if ( et == expons[ count ] ){
          coeffs[ count ] += ct;
          expons[ count ] = et;
          found = true;
        }
      }
      if ( !found ){
        coeffs[ count ] += ct;
        expons[ count ] = et;
      }
    }
  }
}

int Polynomial::getTermsCount(){
  return termsCount;
}

void Polynomial::print(){
  int i;
  bool isZero = false;
  if ( coeffs[ 0 ] ){
    cout << coeffs[ 0 ];
    i = 1;
    isZero = true;
  }
  else{
    if ( coeffs[ 1 ] ){
      cout << coeffs[ 1 ] << 'x';
    if ( ( expons[ 1 ] != 0 ) && ( expons[ 1 ] != 1 ) )
      cout << '^' << expons[ 1 ];
    isZero = true;
    }
    i = 2;
  }
  
  for ( int x = i; x < 100; x++ ){
    if ( coeffs[ x ] != 0 ){
      cout << showpos << coeffs[ x ]<< noshowpos << 'x';
    if ( ( expons[ x ] != 0 ) &&( expons[ x ] != 1 ) )
      cout << '^' << expons[ x ];
    isZero = true;
    }
  }
  
  if ( !isZero )
    cout << '0';
  cout << endl;
}

void Polynomial::combineCommonTerms(Polynomial& other){
  Polynomial newPoly = other;
  int et;
  for ( int i = 0; i < MAX_TERMS; i++ ){
    other.coeffs[i ] = 0;
    other.expons[i] = 0;
  }
  
  for ( int i = 1; i < MAX_TERMS; i++ ){
    et = newPoly.expons[ i ];
    for ( int j = i + 1; j < 100; j++ )
      if ( et == newPoly.expons[j] ){
        newPoly.coeffs[i ] += newPoly.coeffs[ j];
        newPoly.expons[j] = 0;
        newPoly.coeffs[j] = 0;
      }
  }
  other = newPoly;
}