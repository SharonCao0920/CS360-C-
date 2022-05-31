#include<iostream>
using namespace std;;

typedef struct{
  int id = 12345;
  float gpa = 4.0;
}Std;

int main(){
  Std michael;
  Std *ptr;
  ptr = &michael;
  cout << "Michale's id in dot: "<< michael.id<< endl;
  cout << "Michale's id in ptr: "<< ptr->id<< endl;

  return 0;
  
}