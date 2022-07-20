#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h" // Account class definition

class CheckingAccount : public Account{
  public:
    CheckingAccount( double, double );
    void credit( double ); 
    bool debit( double ); 
  private:
    double transactionFee; 
    void chargeFee();
}; 

#endif
