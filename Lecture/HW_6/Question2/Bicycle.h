#include "CarbonFootprint.h"

class Bicycle : public CarbonFootprint {
    public:
        // Implementing getCarbonFootprint method
        void getCarbonFootprint() {
            cout << "----Bicycle Carbon Footprint----" << endl
            << "A bicycle has no carbon footprint" << endl;
        }
};