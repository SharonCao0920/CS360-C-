/*
3.Write a base class number that holds a single integer value and contains one 
member function, print_it. Define three derived classes to print the value in hex, octal, 
and decimal.
*/
#include <iostream>
using namespace std;
class number{
    public:
        int num;
        virtual void print_it(int num)=0;  //pure virtual function
};

class hexVal : public number{
    public:
        void print_it(int num){    //Printing Hexadecimal value
            cout<< "Hexadecimal value: "<<hex<<num<<"\n";  
        }
};

class octVal : public number{
    public:
        void print_it(int num){     //Printing Octal value
            cout<<"Octal value: "<< oct << num <<"\n";  
        }
};
class decVal : public number{
    public:
        void print_it(int num) {    //Printing Decimal value
            cout<< "Decimal value: "<<dec<<num<<"\n" ;
        }
};

int main(void) {
    int numVal=10;
    cout<<"Number: "<<numVal<<"\n";

    number *h=new hexVal();    //Display Hexadecimal value
    h->print_it(numVal);
   
    number *o=new octVal();    //Display Octal value
    o->print_it(numVal);
   
    number *d=new decVal();    //Display Decimal value
    d->print_it(numVal);

    return 0;
}