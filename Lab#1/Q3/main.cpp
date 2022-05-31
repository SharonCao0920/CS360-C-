// Program Strings applies string functions.

#include <iostream>

using std::cout;
using std::string;
using std::endl;

int main (void){
  string name = "Sharon Cao";
  cout << "The string length is: " << name.length() << endl;
  cout << "The string size is: " << name.size() << endl;

  int pos = name.find(" ");
  
  cout << name.substr(pos+1) + ", " + name.substr(0, 1) << endl;
return 0;
}