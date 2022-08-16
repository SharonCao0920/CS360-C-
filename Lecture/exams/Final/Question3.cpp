// arrover3.cpp
// creates safe array (index values are checked before access)
// uses overloaded [] operator for both put and get
#include <iostream>
using namespace std;
#include <cstdlib> //for exit()

const int LIMIT = 100; //array size

////////////////////////////////////////////////////////////////

//Template Declaration
template< typename T >
class safearay{
    private:
        T arr[LIMIT];
    public:
        T& operator [](int n)
        {
            if( n< 0 || n>=LIMIT )
            { cout << "\nIndex out of bounds"; exit(1); }
            return arr[n];
        }
};

////////////////////////////////////////////////////////////////

int main(){
    //integer type
    safearay <int>sa1=safearay<int>();
    for(int j=0; j<LIMIT; j++) //insert elements
        sa1[j] = j*10; //*left* side of equal sign
    for(int j=0; j<LIMIT; j++) //display elements
    {
        int temp = sa1[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }

    //next line
    cout<<endl;

    //char type
    safearay<char> sa2 = safearay<char>();
    for(int j=0; j<10; j++){ //insert elements}
        cout << "Enter Char: ";
        cin >>sa2[j]; //*left* side of equal sign
    }
    for(int j=0; j<10; j++) //display elements
    {
        char temp = sa2[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }
    return 0;
}