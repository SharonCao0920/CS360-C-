//# myClass.cpp
#include <iostream>
#include "myClass.h"
using std::cout;
using std::endl;
void myClass::Func(void){
cout << "this is a test function :)" << endl;
}
int myClass::getNumber(void){
return number;
}