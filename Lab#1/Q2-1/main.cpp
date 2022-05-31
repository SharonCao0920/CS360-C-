// Program Shell

#include <iostream>

using namespace std;

int main (){
  //name input
  string fName, lName;
  cout << "Enter your last name: " << endl;
  cin >> lName;
  cout << "Enter your first name: " << endl;
  cin >> fName;

  //date input
  string year, month, day;
  cout << "What year is today: " << endl;
  cin >> year;
  cout << "What month is today: " << endl;
  cin >> month;
  cout << "What date is today: " << endl;
  cin >> day;

  cout << endl;
  cout << "The name entered is: " << fName + " " + lName << endl << endl;
  cout << "The date is: " << month + ":" + day + ":" + year << endl;

return 0;
}