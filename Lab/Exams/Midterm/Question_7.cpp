/*
7.Write a program to implement user-define casting operator to covert a class A to the other class 
A::operator otherClass() const;
*/
#include<iostream>
using namespace std;

class A{
  private:
    int x, y;
  public:
    A(int n1, int n2){
      x=n1;
      y=n2;
   }
    operator float() const;
};

A::operator float() const{
        float d = (float) x/y;
        return d;
}

int main(void){
  A test(10,20);
  cout<<"The number is: " << float(test)<<endl;
  float num = 3.8 + test;
  cout<<"After operating: " << num << endl; 
  return 0;
}