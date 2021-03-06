/*
2.Create a class called Date that includes three pieces of information as data members--a month (type int), a day (type int) and a year (type int). Your class should have a constructor with three parameters that uses the parameters to initialize the three data members. Assume that the values provided for the year and day are correct, but ensure that the month value is in the range 1-12; if it isn’t, set the month to 1. Provide a set and a get function for each data member. Provide a member function displayDate that displays the month, day and year separated by forward slashes (/). Write a test program that demonstrates class Date’s capabilities.
*/
class Date{
	public:
		Date ( int m, int d, int y);
		void setMonth (int m);
		int getMonth();
		void setDay (int d);	
		int getDay();
		void setYear (int y);
		int getYear();
		void displayDate();
	private:
		int month;
		int day;
		int year;
};