#include <iostream>
using namespace std;

class Card{
  private:
    int face;
    int suit;
    static const string FACES[];
    static const string SUITS[];
  public:
    Card();
    Card(int suit1,int face1);
    string toString();
};