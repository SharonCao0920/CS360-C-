#include <iostream>
#include "GradeBook.cpp"

using namespace std;

int main(void){
  GradeBook g("CS494", "Wonderful");
  g.displayMessage();
  cout << "After setting new names: "<< endl;
  g.setCourseName("CS489 Project Management");
  g.setInstructorName("Prof. Wonderful");

  g.displayMessage();
  return 0;
}