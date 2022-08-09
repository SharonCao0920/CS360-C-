#include <iostream>
using namespace std;

int main(void){
    int x, y, z;
    cout << "Enter decimal integer: "; 
    cin >> x;
    cout << "Enter octal integer: ";
    cin >> oct >> y;
    cout << "Enter hexadecimal integer: ";
    cin >> hex >> z;
    
    cout << "First number is decimal: " << dec << x << " octal: " << oct << x << " hex: " << hex << x << endl;
    cout << "Second number is decimal: " << dec << y << " octal: " << oct << y << " hex: " << hex << y << endl;
    cout << "Third number is decimal: " << dec << z << " octal: " << oct << z << " hex: " << hex << z << endl;
    return 0;
}