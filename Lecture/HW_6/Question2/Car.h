#include "CarbonFootprint.h"

class Car : public CarbonFootprint {
    private:
        // Required attributes
        int numOfGallons;
    public:
        void setNumOfGallons(int n){
            numOfGallons = n;
        }
        int getNumOfGallons(){
            return numOfGallons;
        }

        // Implementing getCarbonFootprint method
        void getCarbonFootprint() {
            cout << "----Car Carbon Footprint----" << endl
            << "One gallon of gas yields 20 pounds of C02" << endl
            << numOfGallons << " gallon(s) of gas yield " << numOfGallons * 20 << " pounds of C02" << endl;
        }
};