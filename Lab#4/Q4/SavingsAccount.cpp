#include<iostream>
#include<string>
using namespace std;

class SavingsAccount{
	static float annualInterestRate;
	float savingsBalance;
public:
	SavingsAccount(float _savingsBalance=0):savingsBalance(_savingsBalance){}
	
  void calculateMonthlyInterest(){
		savingsBalance+=savingsBalance*annualInterestRate / 12;
		//return savingsBalance*annualInterestRate / 12;
	}

	static void modifyInterestRate(float rate){
		annualInterestRate = rate;
	}
	
  void printBalance(){
		cout << "The balance of the account is: " << savingsBalance << endl;
	}
};

float SavingsAccount::annualInterestRate = 0;


int main(void){
	SavingsAccount saver1(2000);
	SavingsAccount saver2(3000);
  saver1.printBalance();
  saver2.printBalance();
  
	saver1.modifyInterestRate(0.03);
  saver1.calculateMonthlyInterest();
  saver2.calculateMonthlyInterest();
  cout << "For annual interest rate of 0.03: " << endl;
  saver1.printBalance();
  saver2.printBalance();
	
  saver1.modifyInterestRate(0.04);
  saver1.calculateMonthlyInterest();
  saver2.calculateMonthlyInterest();
  cout << "For annual interest rate of 0.04: " << endl;
  saver1.printBalance();
  saver2.printBalance();

  return 0;
}