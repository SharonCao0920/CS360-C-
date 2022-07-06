/*
5.Compare const pointer related syntax of p and q as below by the program. And explain what the difference between them is?
*/
#include <iostream>
using namespace std;

int main(void){
  int a=123, b=456;
  const int* p;
  int const* q;
  p = &a;
  cout<<"p="<<*p<<endl;
  p = &b;
  cout<<"p="<<*p<<endl;
  // *p = 789;
  // cout<<"p="<<*p<<endl;
  
  q = &a;
  cout<<"q="<<*q<<endl;
  q = &b;
  cout<<"q="<<*q<<endl;
  *q=*q-1;  // trying to change pointer
  cout<<"q="<<*q<<endl;
      
  return 0;
}