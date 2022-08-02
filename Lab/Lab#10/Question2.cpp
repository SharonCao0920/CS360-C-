/*
2.Write a base class called person that describes a person of either gender. 
Define two derived classes called man and woman that define gender specific items. 
Write pure virtual functions in the base class for operations that are common to both 
sexes yet are handled in different ways by each of them.
*/
#include <iostream>
using namespace std;
class Person{
    public:
        virtual void printName()=0;  //pure virtual function
        virtual void printGender()=0;
};

class Man : public Person{
    public:
        string name;
        void printName(){  //Print name of the person
            cout<<"Name: "<<name<<"\n";
        }
        void printGender(){ //Print gender
            cout<<name<<" is a Male\n";
        }
};
class Woman : public Person{
    public:
        string name;
        void printName(){     //Print name of the person
            cout<<"Name: "<<name<<"\n";
        }
        void printGender() {   //Print gender
            cout<<name<<" is a Female\n";
        }    
};
int main(void) {
    Man m;
    Woman w;
   
    m.name="Christopher";
    m.printName();
    m.printGender();
    
    w.name="Linda";
    w.printName();
    w.printGender();

    return 0;
}