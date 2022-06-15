//include required header files
#include<iostream>
#include"savingAcc.h"
using namespace std;

SavingsAccount::SavingsAccount(double a, double b){
  annualInterestRate=a;
  savingsBalance=b;
}

void SavingsAccount::setInterestRate( double a){
  annualInterestRate = a;
}

//static funtion modify interest rate
void SavingsAccount::modifyInterestRate(double newRate){
   annualInterestRate = newRate;
}

//calculating savings balance with monthly interest
//calculateMonthlyInterest that calculates the monthly interest by multiplying the savingsBalance by annualInterestRate divided by 12; this interest should be added to savingsBalance.
void SavingsAccount::calculateMonthlyInterest(){
  double monthlyInterest = savingsBalance*annualInterestRate / 12;
  savingsBalance += monthlyInterest;
}

void SavingsAccount::printBalance(){
  cout << "The balance in saving account is: " << savingsBalance << endl;
}

