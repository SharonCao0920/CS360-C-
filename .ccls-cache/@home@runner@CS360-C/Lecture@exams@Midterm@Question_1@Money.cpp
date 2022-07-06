/*
  1.Create a class called Money. It should store money amounts as long doubles. Use the
function mstold() to convert a money string entered as input into a long double, and
the function ldtoms() to convert the long double to a money string for display. You can call the input and output member functions getmoney() and putmoney(). Write another member function that adds two Money amounts; you can call it madd(). Adding Money objects is easy: Just add the long double member data amounts in two Money objects. Write a main() program that repeatedly asks the user to enter two money strings, and then displays the sum as a money string. Here’s how the class might look:
*/

#include <iostream>
#include <string>
using namespace std;

class Money{
  private:
      long double mny;
  
  public:
      Money(){
          mny = 0.0;
      }

      Money(string s){
          mny = stold(s);
      }
      //input string and converet to long double
      void mstold(){
          string mStr;
          cout << "Please enter the money: " << endl;
          cin >> mStr;
          mny = stold(mStr);
      }
      //convert the long double to a money string for display
      void ldtoms(){
          string mStr = to_string(mny);
          cout << "The money amount is: " << mStr << endl;
          ;
      }
      //add two money
      void madd(Money m1, Money m2){
          this->mny = m1.mny + m2.mny;
          cout << "After adding two money: " << endl;
          ldtoms(); //print string
      }
      //print money as string
      void getmoney(){
          ldtoms();
      }
      // user to put money
      void putmoney(){
          mstold(); //convert to long double
      }
};

int main(void){
  // creating 2 Money class objects
  Money m1, m2;
  
  m1.putmoney();
  m2.putmoney();

  Money m3;
  m3.madd(m1, m2);
  
  return 0;
}