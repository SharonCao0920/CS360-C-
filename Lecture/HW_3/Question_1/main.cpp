#include<iostream>
#include "DeckOfCards.h"
using namespace std;

int main(void){
  DeckOfCards cards;
  cards.shuffle();
  
  while(cards.moreCards()){
    cout << cards.dealCard().toString() << endl;
  }
  return 0;
}