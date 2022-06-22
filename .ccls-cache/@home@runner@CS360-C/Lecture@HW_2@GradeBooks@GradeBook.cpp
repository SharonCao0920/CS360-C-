#include <iostream>
using namespace std;
#include "gradebook.h"

/*
c.Modify the constructor to specify course name and instructor name parameters.
d.Modify function displayMessage to output the welcome message and course name,
then the string "This course is presented by: " followed by the instructor’s name.
*/

GradeBook::GradeBook(string courseName, string instructorName):courseName(courseName), instructorName(instructorName){}

void GradeBook::setCourseName(string courseName){
  this->courseName = courseName; 
}

string GradeBook::getCourseName() const{
  return courseName;
} 

void GradeBook::setInstructorName(string instructorName){
  this->instructorName = instructorName; 
}

string GradeBook::getInstructorName() const{
  return instructorName;
} 

void GradeBook::displayMessage() const{
  cout << "Welcome to the grade book for " << getCourseName() << "!" << endl;
  cout << "The instructor of " << getCourseName() << " is " << getInstructorName()<< "." << endl;
}
