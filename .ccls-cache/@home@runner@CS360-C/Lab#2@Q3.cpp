/*
Write a class called Rectangle
floating point data members' length and width
void setlength(float) to set the length data member; 
void setwidth(float)to set the width data member; 
float perimeter(void)to calculate and return the perimeter of the rectangle; float area(void)to calculate and return the area of the rectangle; 
void show(void)to display the length and width of the rectangle; 
int sameArea(Rectangle)that has one parameter of type Rectangle, and sameArea returns 1 if the two Rectangles have the same area, otherwiese returns 0 if they don't. 
*/

#include <iostream> 

using namespace std;

class Rectangle{
  private:
  float length;
  float width;

  public:
  void setlength(float); //set lenght with new value
  void setwidth(float); //set lenght with new value
  float perimeter(void); //calculate perimeter
  float area(void); //calculate area
  void show(void); //dosplay length and width
  int sameArea(Rectangle);  //check if area is same
};

//set lenght with new value
void Rectangle:: setlength (float thisLength){
   length = thisLength;
}

 //set lenght with new value
 void Rectangle :: setwidth (float thisWidth){
  width = thisWidth;
}

//calculate perimeter
float Rectangle :: perimeter(void){
  return 2 * ( length + width );
}

//calculate area
float Rectangle :: area(void){
  return length * width;
}

//display length and width
void Rectangle :: show(void){
  cout << "Length is: " << length << endl;
  cout << "Width is: " << width << endl;
}

//check if area is same
int Rectangle :: sameArea(Rectangle obj){
  if ( (length * width) == obj.area() )
    return 1;
  else
    return 0;
}

//main function
int main(void){
  //create 2 objects
  Rectangle obj1, obj2;

  //set obj1 values
  obj1.setlength(15);
  obj1.setwidth(6.3);
  
  //set obj2 values
  obj2.setlength(5);
  obj2.setwidth(18.9);

  //Display
  cout << "For object 1: " << endl;
  obj1.show();
  cout << endl;
  cout << "For object 2: " << endl;
  obj2.show();

  cout << endl;
  
  //display area
  cout << "The area of object 1 is: " << obj1.area() << endl;
  cout << "The area of object 2 is: " << obj2.area() << endl;

  cout << endl;
  
  //display perimeter
  cout << "The perimeter of object 1 is: " << obj1.perimeter() << endl;
  cout << "The perimeter of object 2 is: " << obj2.perimeter() << endl;

  //check if is smae area
  if (obj1. sameArea(obj2))
    cout << "Obj1 and obj2 has same area." << endl;
  else
    cout << "Obj1 and obj2 has different area." << endl;

  return 0;
}