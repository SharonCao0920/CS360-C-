#include <iostream>
#include "CarbonFootprint.h"
#include "Building.h"
#include "Car.h"
#include "Bicycle.h"
#include <vector>

using namespace std;

int main(void) {
    // Creating three objects of all three classes
    Building f1; f1.setSquareFeet(1);
    Car f2; f2.setNumOfGallons(2);
    Bicycle f3;
    // Adding these in vector of CarbonFootprints
    vector<CarbonFootprint*> footPrints;
    footPrints.push_back(&f1);
    footPrints.push_back(&f2);
    footPrints.push_back(&f3);
    // Iterating through vector and calling getCarbonFootprint method
    for (int i=0; i<footPrints.size(); i++) {
        footPrints[i]->getCarbonFootprint();
        cout << endl;
    }
    return 0;
}