// Child class derived from CarbonFootprint

#include "CarbonFootprint.h"

class Building : public CarbonFootprint {
    private:
        // Required attributes
        double squareFeet;

    public:
        // Setter and Getter for squareFeet
        void setSquareFeet(double s){
            squareFeet = s;
        }
        double getSquareFeet(){
            return squareFeet;
        }

        // Implementing getCarbonFootprint method
        void getCarbonFootprint() {
            // Using Building Carbon Footprint formula
            cout << "----Building Carbon Footprint----" << endl
            <<"squareFeet * (50 + 20 +47 + 17) = " << squareFeet * (50 + 20 +47 + 17) << endl;
        }
};