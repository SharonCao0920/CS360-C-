//#main.cpp
#include <iostream>
#include "myClass.h"
using std::cout;
using std::endl;
int main(){
  myClass a;
  cout << a.getNumber() <<endl;
  a.Func();
  return 0;
}