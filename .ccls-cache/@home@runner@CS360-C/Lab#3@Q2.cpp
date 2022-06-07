#include <stdio.h>
#include <iostream>

using namespace std;

class Student{
  /*
  a. Define a class called student that has the following data members:
  i.int student number
  ii.string student name
  iii.double student average
  */
  int stdNumber;
  string stdName;
  double stdAverage;
  
  /*
  b.The following member functions:
  i.Constructor that initialize the data members with default values.
  ii.set and get functions for each data member
  iii.Print function to print the values of data members.
  */
  public:
  Student(){ //need to initialize
    stdNumber=0;
    stdName="";
    stdAverage=0;
  };

  void setNumber(int n){
    stdNumber = n;
  }
  int getNumber(){
    return stdNumber;
  }
  void setName(string name){
    stdName = name;
  }
  string getName(){
    return stdName;
  }
  void setAve(double ave){
    stdAverage = ave;
  }
  double getAve(){
    return stdAverage;
  }

  void sPrint(int n, string s, double a){
    cout << "Student number is: " << n << endl;
    cout << "Student name is: " << s << endl;
    cout << "Student average is: " << a << endl;
  }
};

/*
c.Define a class called graduatestudent that inherits data members and
functions from the class student, and then declare the following data members :
i.int level
ii.int year
*/

class GraduateStudent {
  public: 
  //data member  
  int level;
  int year;
  
  /*
  d.Member functions:
  i.constructor 
  ii.set and get functions for each data member
  iii.Print function.
  */
  GraduateStudent(){
    level=0;
    year=0;
  };
  
  void setLevel(int l){
    level = l;
  }
  
  int getLevel(){
    return level;
  }

  void setYear(int y){
    year = y;
  }
  
  int getYear(){
    return year;
  }

  void gPrint(int l, int y){
    cout << "Level is: " << l << endl;
    cout << "Year is: " << y << endl;
  }
};

/*
e.Define a class called master that inherits data members and functions from
		graduatestudent class, and then declare the following data member:
i.int newid
*/
class Master : public GraduateStudent{
  int newid;
  public:  
  /*
  f.Member function:
  i.constructor
  ii.set and get function for the data member
  iii.Print function
  */
  Master(){
    
  }

  void setNewid(int num){
    newid = num;
  }
  
  int getNewid(){
    return newid;
  }
  
  void mPrint(int num){
    cout << "New id: " << num << endl;
  }
  
};

/*
g.Write a driver program(i.e. main function) that:
i.Declare object of type student with suitable values then print it
ii.Declare object of type master with your information then print it.
*/
int main(void){
  Student s;
  s.setNumber(12345);
  s.setName("Peter");
  s.setAve(96.8);
  s.sPrint(s.getNumber(),s.getName(), s.getAve());

  Master m;
  m.setLevel(4);
  m.setYear(2018);
  m.setNewid(54321);
  m.gPrint(m.getLevel(),m.getYear());
  m.mPrint(m.getNewid());
  return 0;
}








