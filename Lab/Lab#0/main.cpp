// Program Area calculates the area of a square.
// The user is prompted to enter the number of inches on each
// side. Note that "endl" in line 7 ends in the letter "l", not
// the number one.
			
#include <iostream>
			
using namespace std;

int main (){
int  inches; // initialize the integer variable

cout  << "Enter the number of inches on a side " //print the line on screen
         << endl; // end of the line
cout  << "Press the return key."  // //print the line on screen
         << endl; // end of the line
cin    >> inches; // user input save to variable inches 
cout  << endl // end of line
  // printi on screen the area is square of inches      
  << "The area is "  << inches * inches  <<"." 
         << endl; // end of line
return 0; // return sucessful
				}