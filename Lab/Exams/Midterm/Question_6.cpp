/*
6.Write a method in a class HugeInteger to implement operator overloading as follows, and verify it in the main function
*/

#include <iostream>

using namespace std;

class HugeInteger{
  private:
    int x;
  public:
    HugeInteger(){x = 0;}

    HugeInteger operator +(int x){
      HugeInteger out;
      out.x = this->x + x;
      return out;
    }
  
    int getX(){
      return x;
    }
};

int main(void) {
  HugeInteger bigInteger;
  int integer = 12;

  bigInteger = bigInteger + integer;
  cout<< "bigInteger = " << bigInteger.getX() << endl;
  return 0;
}