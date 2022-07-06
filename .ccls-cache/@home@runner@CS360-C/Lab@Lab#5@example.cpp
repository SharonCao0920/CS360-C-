#include <iostream>

using namespace std;

class Example{
  public:
    Example( int y = 10): data( y ){
      count = count + 1;  //increment here
    } 
    int getIncrementedData(){ //delete const to change data value
      return ++data; //increment then return
    } 
    //static function can only access static variable
    static int getCount(){ 
      //cout << "Data is " << data << endl;
      return count;
    } 
  private:
    int data;
    static int count;
}; 

int Example::count=0; //initialize the count

int main(void){
  Example example(33);
  int a, b;
  a = example.getIncrementedData();
  b = example.getCount();
  cout << "incremented a: " << a << endl;
  cout << "count is: " << b << endl;
  return 0;
}



