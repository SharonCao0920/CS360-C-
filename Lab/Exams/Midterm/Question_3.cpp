/*
3.Knowing that "if class B is a friend of class A, A is not necessarily a friend of B", write a program to verify it for class A with a private member. 
*/
#include <iostream>
using namespace std;

class A {
  private:
    int x = 4;
  public:
    void getX(){
      cout << "Value of x in class A is: " << x << endl;
    }
    friend class B; // Friend Class
};

class B {
  public:
    void getXinA(A& a){
      cout << "value of x is: " << a.x << endl;
    }
};

int main(void){
  A a;
  B b;
  a.getX();
  b.getXinA(a);
  return 0;
}