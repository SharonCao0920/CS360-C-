#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void){
    //a. print integer 40000 left justified in 15-digit field.
    cout<<"print integer 40000 left justified in 15-digit field.\n";
    cout.width(15);   //setting width to 15
    cout << left << 40000 << '\n'; 
    cout<<"\n"; 
    
    //b. Read a string into character array variable state.
    cout<<"Read a string into character array variable state.\n";
    char state[255]; //declaring variable
    cin.get(state,255); //reads value in state
    cout<<"string read is: "<<state;
    cout<<"\n";
    
    //c. Print 200 with sign and wthout sign
    cout<<"\nWithout sign: "<<200;
    cout<<"\nWith sign: "<<showpos<<200; //showpos for positive sign
    cout<<"\n";
    
    //d. print 100 in hexadecimal
    cout<<"\nPrint 100 in hexadecimal\n";
    printf("0x%x",100);
    cout<<"\n";

    //e. Read characters into array charArray until the character 'p' is 
    //encountered, up to a limit of 10 characters (including the terminating 
    //null character). Extract the delimiter from the input stream, and discard it.
    cout<<"\nPrint charArray until 'p' up to 10 char\n";
    int i;
    char chararray [10];
    cout << "Enter input string: ";
    
    for (i = 0; i < 9; i++) {
        cin >> chararray [i];
        if (chararray[i] == 'p') break;
    }
    chararray [i] = '\0';

    cout << chararray << endl;

    //f. f.Print 1.234 in a 9-digit field with preceding zeros.
    cout<<"\nPrint 1.234 in a 9-digit field with preceding zeros.\n";     
    double d = 1.234;
    cout << setfill('0') << setw(9) << d << endl;   
    
    return 0;
}