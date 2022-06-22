#include <string> 

/*
a.Include a second string data member that represents the course instructor’s name.
b. Provide a set function to change the instructor’s name and a get function to retrieve it.

*/
class GradeBook{
  public:
  	explicit GradeBook(std::string, std::string); // constructor 
  	void setCourseName(std::string); // sets the course name
  	std::string getCourseName() const; // gets the course name
    void setInstructorName(std::string); // sets the course name
  	std::string getInstructorName() const; // gets the course name
  	void displayMessage() const; // displays a welcome message
    
  private:
  	std::string courseName; // course name
    std::string instructorName; // instructor name
};
