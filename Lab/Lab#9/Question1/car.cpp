#include "car.h"

Car::Car( long n, const string& prod){
  cout << "Creating an object of type Car." << endl;
  nr = n; producer = prod;
}

Car::~Car(){
  cout << "Destroying an object of type Car" << endl;
}

void Car::display() const{
  cout << "\n---------------------------- "<< "\nCar number: " << nr<< "\nProducer: " << producer<< endl;
}

PassCar::PassCar(const string& tp, bool sd, int n,const string& hs): Car( n, hs), PassCarTyp( tp ), sunRoof( sd ){
  cout << "I create an object of type PassCar." << endl;
}

PassCar::~PassCar(){
    cout << "\nDestroying an object of type PassCar"<< endl;
}

void PassCar::display( void) const{
  Car::display(); // Base class method
  cout << "Type: " << passCarType<< "\nSunroof: ";
  if(sunRoof)
    cout << "yes "<< endl;
  else
    cout << "no " << endl;
}

Truck::Truck( int a, double t, int n, const string& hs): Car( n, hs), axles(a), tons(t){
  cout << "Creating an object of type Truck." << endl;
}

Truck::~Truck(){
  cout << "\nDestroying an object of type Truck\n";
}
void Truck::display() const{
  Car::display();
  cout << "Axles: " << axles<< "\nCapacity: " << tons << " long tons\n";
}