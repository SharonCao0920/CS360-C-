/*
1.Define a base class shape that can describe any simple shape such as a square, 
circle or equilateral triangle. The size of all these shapes can be reduced to a 
single dimension, such as area & perimeter of the shape based the all sizes
-Define derived classes for each of the three shapes.
-Create a virtual function in the base class that returns the area of each shape.
Note: You will need to more precisely define what dimensions are stored in the base 
class. (Is the size in the base class for circle, the radius, or the diameter?)
*/

#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

class shape{
    public:
    virtual void area()=0; // pure virtual function
};

class circle: public shape{
    float r; //r=radius
    public:
        void area(){
            cout<<"\nEnter radius : ";
            cin>>r;
            cout<<"\nArea of circle : "<<(3.146*r*r);
        }
};
class square: public shape{
    int b;
    public:
        void area()
        {
        cout<<"\n\nEnter length of square: ";
        cin>>b;
        cout<<"\nArea of square : "<<b*b;
        }
};
    
class equilateraltriangle: public shape{
    int b;
    float a;
    public:
    void area(){
        cout<<"\n\nEnter side of a Equilateral triangle : ";
        cin>>b;
        a=sqrt(3)/4*(b*b);
        cout<<"\nArea of triangle : "<<a;
    }
};

int main(void){
    circle c; // object created
    c.area();
    square r; // object created
    r.area();
    equilateraltriangle t; // object created
    t.area();
    getch();
    return(0);
}