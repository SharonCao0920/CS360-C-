// Abstract class 'CarbonFootprint'

#ifndef CARBON_FOOTPRINT_H
#define CARBON_FOOTPRINT_H

#include <iostream>
using namespace std;

class CarbonFootprint {
    public:
        // Only Required pure virtual function
        virtual void getCarbonFootprint() = 0;
};

#endif