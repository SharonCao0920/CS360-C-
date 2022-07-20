#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;
using std::fixed;

#include "Account.h" 
#include "SavingsAccount.h" 
#include "CheckingAccount.h" 

int main(void){
  Account account1( 150.0 ); 
  SavingsAccount account2( 125.0, .03 ); 
  CheckingAccount account3( 220.0, 1.0 ); 
  
  cout << fixed << setprecision( 2 );
  
  cout << "account1 balance: $" << account1.getBalance() << endl;
  cout << "account2 balance: $" << account2.getBalance() << endl;
  cout << "account3 balance: $" << account3.getBalance() << endl;
  
  cout << "\nAttempting to debit $30.00 from account1." << endl;
  account1.debit( 30.0 ); 
  cout << "\nAttempting to debit $38.00 from account2." << endl;
  account2.debit( 38.0 ); 
  cout << "\nAttempting to debit $45.00 from account3." << endl;
  account3.debit( 45.0 ); 
  
  cout << "\naccount1 balance: $" << account1.getBalance() << endl;
  cout << "account2 balance: $" << account2.getBalance() << endl;
  cout << "account3 balance: $" << account3.getBalance() << endl;
  
  cout << "\nCrediting $80.00 to account1." << endl;
  account1.credit( 80.0 ); 
  cout << "\nCrediting $75.00 to account2." << endl;
  account2.credit( 75.0 ); 
  cout << "\nCrediting $17.00 to account3." << endl;
  account3.credit( 17.0 ); 
  
  cout << "\naccount1 balance: $" << account1.getBalance() << endl;
  cout << "account2 balance: $" << account2.getBalance() << endl;
  cout << "account3 balance: $" << account3.getBalance() << endl;
  
  double interestEarned = account2.calculateInterest();
  cout << "\nAdding $" << interestEarned << " interest to account2." << endl;
  account2.credit( interestEarned );
  
  cout << "\nNew account2 balance: $" << account2.getBalance() << endl;
  return 0;
} 