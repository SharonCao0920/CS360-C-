#include <iostream>
#include "Card.h"
using namespace std;

const string Card::FACES[]{"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

const string Card::SUITS[]={"Heart","Diamond","Club","Spade"};

Card::Card(){
  face=suit=0;
}

Card::Card(int suit1,int face1){
  face=face1;
  suit=suit1;
}

string Card::toString(){
  return FACES[face]+" of "+SUITS[suit];
}