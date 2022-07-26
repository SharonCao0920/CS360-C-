#include <iostream>
#include "clockType.h"
using namespace std;

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