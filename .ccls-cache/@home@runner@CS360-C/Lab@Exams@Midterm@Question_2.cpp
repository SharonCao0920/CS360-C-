/*
Create a class A with a private static variable x, initialize x, and increase 1 to x in a method within the class A file. after that, verify it in the main function 
*/
#include <iostream>
using namespace std;

class A{
  private:
    static int x;
  public:
    A(){}
    void increaseOne(){
      x++;
    }
    static int getX(){
      return x;
    }
};
int A::x = 0;

int main(void){
  A a;
  a.increaseOne();
  cout << "After increasing x is: " << a.getX() << endl;
  return 0;
}