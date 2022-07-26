#include <iostream>
#include "clockType.h"
#include "extClockType.h"

using namespace std;

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
