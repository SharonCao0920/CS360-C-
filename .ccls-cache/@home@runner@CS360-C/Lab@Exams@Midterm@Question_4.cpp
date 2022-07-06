/*
4.Given class A & class B, and an object b of B in class A, write a program to initialize b in class A by the constructor with some arguments that you decide  
*/
#include <iostream>

using namespace std;

class B{
  private:
    int x;
  public:
    B(int a){
      x=a;
      cout << "Value of variable in class B is: " << x << endl;
    }
};

class A{
  public:
    A(int a){
      B b(a);
    }
};

int main(void){
  A a(10); 
  return 0;
}