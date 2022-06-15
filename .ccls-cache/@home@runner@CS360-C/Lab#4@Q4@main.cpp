//include required header files
#include<iostream>
#include "savingAcc.cpp"
#include "savingAcc.h"
using namespace std;

int main(void){

  SavingsAccount saver1(0.03,2000.00); 
  SavingsAccount saver2(0.03,3000.00);

  //print current balance
  cout << "FOR Saver1" << endl;
  saver1.printBalance();
  cout << "FOR Saver2" << endl;
  saver2.printBalance();
  cout << "--------------------------------------------------";

  //calculate current rate
  cout << "For 3% annual interest rate" << endl;
  cout << "FOR Saver1" << endl;
  saver1.calculateMonthlyInterest();
  saver2.calculateMonthlyInterest();
  saver1.printBalance();
  cout << "FOR Saver2" << endl;
  saver2.printBalance();


 /* 
  saver1.modifyInterestRate(0.04);
  cout << "Balance of saver1 and saver2 on 4% interest Rate\n";
  cout << "---------------------------------------------------\n";
  cout << "New Balance of saver1 = " << saver1.calculateMonthInt()        << endl;
  cout << "New Balance of saver2 = " << saver2.calculateMonthInt()    << endl<<endl;*/
  return 0;
}