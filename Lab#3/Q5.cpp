#include <stdio.h>
#include <iostream>
#include<cstring>

using namespace std;

class Sample{
  private:
    int x;
    double y;
  public :
    Sample(); //Constructor 1
    Sample(int); //Constructor 2
    Sample(int, int); //Constructor 3
    Sample(int, double); //Constructor 4
};

/*
a.Write the definition of the constructor 1 so that the private member variables are initialized to 0
*/
Sample :: Sample():x(0),y(0.0){}

/*
b.Write the definition of the constructor 2 so that the private member variable x is initialized according to the value of the parameter, and the private member variable y is initialized to 0
*/
Sample :: Sample(int i):x(i),y(0.0){}

/*
c.Write the definition of the constructors 3 and 4 so that the private
member variables are initialized according to the values of the parameters.
*/
Sample :: Sample(int i, int j):x(i),y(j){}

Sample :: Sample(int i, double j):x(i),y(j){}