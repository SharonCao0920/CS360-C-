#include<iostream> 

using std::cout;
using std::cin;
using std::endl;

class Sample{
  private:
  int a; 
  char b; 
  float c;
  
  public:
  void get_data(){
  	//Write your program here
    cout << "Please enter an integer: ";
    cin >> a;
    cout << "Please enter a character: ";
    cin >> b;
    cout << "Please enter a float number: ";
    cin >> c;
  }

  void print_data(){
  //Write your program here
  cout << "Values read from keyboard are: " << endl;
  cout << "Integer: " << a << endl;
  cout << "Character: " << b << endl;
  cout << "Float number: " << c << endl;
  }
};

int main(void){
  Sample s;
  s.get_data(); 
  s.print_data();
  
  return 0;
}