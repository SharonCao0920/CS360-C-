#include<iostream>
using std::cout;
int a;
int myfun(void);
int main(void){
  a = 123; //a is a
  cout<<"a="<<a<<"\n";
  cout<<"myfun="<<myfun()<<"\n"; //123 or 456
  
  return 0;
}