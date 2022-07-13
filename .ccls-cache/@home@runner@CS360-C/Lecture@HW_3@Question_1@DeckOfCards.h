#include <iostream>
#include <cstdlib>
#include "Card.h"
using namespace std;

class DeckOfCards{
  private:
    Card deck[52];
    int currentCard;
  public:
    DeckOfCards();
    void shuffle();
    Card dealCard();
    bool moreCards();
};