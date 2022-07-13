#include <iostream>
#include <cstdlib>
#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards(){
  for(int suit=0,k=0; suit<4; suit++){
    for(int face=0; face<13; face++){
      deck[k]=Card(suit,face);
      k++;
    }
  }
  currentCard=0;
}

void DeckOfCards::shuffle(){
  Card temp;
  int j;
  srand(time(NULL));
  for(int i=0; i<52; i++){
    j=rand() % 52;
    temp=deck[i];
    deck[i]=deck[j];
    deck[j]=temp;
  }
}

Card DeckOfCards::dealCard(){
  Card c=deck[currentCard];
  if(currentCard < 52)
    currentCard++;
  return c;
}

bool DeckOfCards::moreCards(){
  return currentCard < 52;
}