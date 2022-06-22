#include <string>

using namespace std;

class HeartRates{
	public:
		HeartRates ( string fname, string lname, int mm, int dd, int yy );
		void setFirstName ( string fname);
		string getFirstName ();
		void setLastName (string lname);
		string getLastName ();
		void setMonthOfBirth (int mm);
		int getMonthOfBirth ();
		void setDayOfBirth (int dd);
		int getDayOfBirth ();
		void setYearOfBirth(int yy);
		int getYearOfBirth();
		int getAge();
		int getMaximumHeartRate(int age);
		string getTargetHeartRate(int age);
    void disPlayMessage();
	private:
		string firstName;
		string lastName;
		int dayOfBirth;
		int monthOfBirth;
		int yearOfBirth; 
};