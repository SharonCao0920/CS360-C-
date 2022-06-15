#include <iostream>
using namespace std;

class Time { 
  public: 
     void Time(){
       cout << "Without parameters"<<endl;
     }; 

    // Time( int h = 0, int m = 0, int s = 0 ){
     // cout << "With Parameters" << endl;
    //};
     void setTime( int, int, int ); 
     void printMilitary(); 
     void printStandard(); 
  private: 
     int hour;     // 0 - 23 
     int minute;   // 0 - 59 
     int second;   // 0 - 59 
  }; 

int main (void){
  Time t;
  //Time t1(1, 2, 3);
  
  return 0;
}