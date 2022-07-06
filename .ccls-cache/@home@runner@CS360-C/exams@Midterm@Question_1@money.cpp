#include<iostream>
#include <string>
using namespace std;

long double mstold(string s){
    long double x = stold(s);
    return x;
}

string ldtoms(long double s){
	string str = to_string(s);
	return str;
}

class Money{
  private:
      long double money;
  public:
      Money(){}
      Money(string s){
        money = mstold(s);  
      }

      void madd(Money m1, Money m2){
          money = m1.money + m2.money;
      }

      void getmoney(){
          string st;
          cin >> st;
          money = mstold(st);
      }
      
      void putmoney(){
          cout<<ldtoms(money)<<endl;
      }
};


int main()
{
    char ch;
    do{
    Money m1, m2;
    cout<<"Enter money string :";
    m1.getmoney();
    
    cout<<"Enter money string :";
    m2.getmoney();

    Money m3;
    m3.madd(m1, m2);

    m1.putmoney();
    m2.putmoney();
    cout<<"After addition: ";
    m3.putmoney();
  cout<<"Enter y to continue or n to stop\n";
  cin>>ch;	
    	
	} while(ch != 'n');
	cout<<"Terminated successfully\n";

    return 0;
}