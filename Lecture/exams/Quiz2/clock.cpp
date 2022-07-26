#include <string>
#include <iostream>

using namespace std;

/*
Header for clockType
*/
class clockType {
  public:
    clockType();
    clockType(int, int, int);
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType&) const;
  
  private:
    int hr;
    int min;
    int sec;
};

/*
Class function definitions for clockType
*/
clockType::clockType(){
    setTime(0, 0, 0);
}

clockType::clockType(int hours, int minutes, int seconds){
    setTime(hours, minutes, seconds);
}

void clockType::setTime(int hours, int minutes, int seconds){
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;
    if (0 <= minutes && minutes < 60)
        min = minutes;
    else
        min = 0;
    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
        sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const{
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::printTime() const{
    if (hr < 10)
        cout << "0";
        cout << hr << ":";
    if (min < 10)
        cout << "0";
        cout << min << ":";
    if (sec < 10)
        cout << "0";
        cout << sec;
}

void clockType::incrementHours(){
    hr++;
    if (hr > 23)
        hr = 0;
}

void clockType::incrementMinutes(){
    min++;
    if (min > 59) {
        min = 0;
        incrementHours(); //increment hours
    }
}

void clockType::incrementSeconds(){
    sec++;
    if (sec > 59) {
        sec = 0;
        incrementMinutes(); //increment minutes
    }
}

bool clockType::equalTime(const clockType& otherClock) const{
    return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

/*
Header for extClockType
*/
class extClockType : public clockType {
  private:
    string timezone;
  public:
    extClockType();
    extClockType(int, int, int, string);
    // print time with time zone
    void printTime() const;
    void setTimezone(string s);
    string getTimezone();
};

/*
Class function definitions for extClockType
*/
extClockType::extClockType() {} //default constructor

extClockType::extClockType(int h, int m, int s, string t) : clockType(h, m, s) {
   timezone = t;
}

//inheritated from ClockType class
void extClockType::printTime() const{
   clockType::printTime();
   cout << " " << timezone;
}

void extClockType::setTimezone(string s) {
   timezone = s;
}

string extClockType::getTimezone() {
   return timezone;
}

/*
main function
*/
int main(void) {
  extClockType time1;
  extClockType time2( 11, 30, 0, "PST");

  //time1 is call default constructor
  cout << "Time with default constructor : ";
  time1.printTime();
  cout << endl;

  //time2 is calling constructor with parameter value 
  cout << "Time with parameterized constructor : ";
  time2.printTime();
  cout << endl;
  
  //operate the default time1
  time1.incrementHours();
  time1.incrementMinutes();
  time1.incrementSeconds();
  time1.setTimezone("CST");

  //print time after increment
  cout << "After changing time : ";
  time1.printTime();
  cout << endl;
    
  return 0;
}