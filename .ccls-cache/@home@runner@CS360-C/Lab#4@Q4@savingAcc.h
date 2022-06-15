/*
4.Create a SavingsAccount class. Use a static data member annual-InterestRate to store the annual interest rate for each of the savers. Each member of the class contains a private data member savingsBalance indicating the amount the saver currently has on deposit. Provide member function calculateMonthlyInterest that calculates the monthly interest by multiplying the savingsBalance by annualInterestRate divided by 12; this interest should be added to savingsBalance. Provide a static member function modifyInterestRate that sets the static annualInterestRate to a new value. Write a driver program to test class SavingsAccount. Instantiate two different objects of class SavingsAccount, saver1 and saver2, with balances of $2000.00 and $3000.00, respectively. Set the annualInterestRate to 3 percent. Then calculate the monthly interest and print the new balances for each of the savers. Then set the annualInterestRate to 4 percent, calculate the next month's interest and print the new balances for each of the savers.    
*/

#pragma once
#ifndef SAVINGACC_H
#define SAVINGACC_H
//SavingsAccount class declaration
class SavingsAccount
{
  //declare data members
private:
  //set annualInterestRate to 0.0 default value
  static double annualInterestRate;
  double savingsBalance;

public:
  //constructor
  SavingsAccount(double=0, double=0);

  void setInterestRate(double);

  //modify interest rates
  static void modifyInterestRate(double);

  //retruns total balance with interest

  void calculateMonthlyInterest();
  void printBalance();
};

#endif