#include <iostream>
#include <iomanip>
using namespace std;

int main(void){   
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Length of string is: " << s.length() << "\nThe string is:" << endl;
    cout << setw (s.length() * 2) << s << endl;
    
    return 0;
}