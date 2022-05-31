#include <iostream>
#include <fstream>		// pkg is for file processing	
#include <iomanip>		// for printing format on the monitor 	

using namespace std;

int GetInches(ifstream& rainFile, int numberOfDays);
// Function returns the total inches of rain
// Pre:  File rainFile has been opened; numberOfDays is the
//       first value on the file, followed by numberOfDays
//       real values representing inches of rain.

int main(){
float average;          	 // Average rainfall
float totalRain;        	 // Total accumulated rain
int numberOfDays;         // Number of days in calculation
ifstream  rainFile;      	 // Data file – read from hard drive to memory 

cout  << fixed  << showpoint;

rainFile.open("Rain.In");
rainFile >> numberOfDays;
totalRain = GetInches(rainFile, numberOfDays);
if (totalRain == 0.0)
cout  << "There was no rain during this period."  << endl;
else{
average = totalRain / numberOfDays;
cout << "The average rain fall over "
       << numberOfDays;
cout << " days is " << setw(1)  << setprecision(3)
       << average  << endl;
}

return 0;
}
//******************************************************
int GetInches(ifstream& rainFile, int numberOfDays){
float inches;         // Day's worth of rain
int counter;          // Loop control variable
float totalRain = 0.0;
counter = 1;
while (counter <= numberOfDays){
rainFile >> inches;
totalRain = totalRain + inches;
counter++;
}
return totalRain;
}