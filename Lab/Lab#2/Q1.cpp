#include <iostream> 

using std::cout; 
using std::cin; 
using namespace std;

#define MAX 10 

class Student { 
  private: 
    char name[30]; 
    int courseNum; 
    int total; 
    float perc; 
  public: 
    void getDetails(void); //member function to get student's details 
    void putDetails(void); //member function to print student's details 
}; 
void Student:: getDetails(void) //member function definition, outside of the class 
{ 
  cout << "Enter name: " ; 
  cin >> name; 
  cout << "Enter course number: "; 
  cin >> courseNum; 
  cout << "Enter total grades out of 500: "; 
  cin >> total; 
  perc=(float)total/500*100; 
} 
void Student:: putDetails(void) //member function definition, outside of the class 
{  
  cout << "Name:"<< name 
       << "\ncourse Number:" << courseNum 
      << "\nTotal:" << total 
      << "\nPercentage:" << perc << endl;
}

int main(void){
 	//Write your program here
  int n;
  cout << "Enter total number of students: " << endl;
  cin >> n;
  Student stdList[n];
  
  //get information from each student object in array
  for (int i=0; i<n; i++){
    cout << "\nPlease enter details for student " << (i+1) << ":" << endl;
    stdList[i].getDetails();
  }
  //put information from each student object in array
  for (int i=0; i<n; i++){
    cout << "\nDetail of student " << (i+1) << ":" << endl;
    stdList[i].putDetails();
  }
  
  return 0;
}