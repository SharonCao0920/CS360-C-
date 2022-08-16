#include <iomanip>
#include <ios>
#include <iostream>
using namespace std;

int main(void){
    //a
    cout << "a\n" << "12345" << endl;
    cout.width( 5 );
    cout.fill( '*' );
	cout << 123 << endl << 123;
    //b.
    cout << "\nb\n";
    cout << setw( 10 ) << setfill( '$' ) << 10000;
    //c.
    cout << "\nc\n"; 
    cout << setw( 8 ) << setprecision( 3 ) << 1024.987654;
    //d.
    cout << "\nd\n";
    cout << showbase << oct << 99 << endl << hex << 99;
    //e.
    cout << "\ne\n";
    cout << 100000 << endl << showpos << -100000;
    //f.
    cout << "\nf\n";
    cout << setw( 10 ) << setprecision( 2 ) << scientific << 444.93738;

    return 0;
}