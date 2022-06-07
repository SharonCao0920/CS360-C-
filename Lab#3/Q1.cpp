#include <stdio.h>
#include <iostream>

using namespace std;

class A {
public:
  A();         // empty constructor
  A(int);      // constructor with one integer parameter 
  A(const A&); //constructor with one const alis parameter 
               // 
  ~A();        // deconstruct
public:
  void operator=(const A& rhs); // copy assignment
  void Print();        // non-const Print function method
  void PrintC() const; //const Print function method
                                             
  int x;       // class variable x;
public:
  //function to return x
  int& X() { return x; } 
};

A::A() //class A inital funtion without parameters
  : x(0) // inital class A data x=0
{ 
  cout << "Hello from A::A() Default constructor" << endl;
}

A::A(int i)//class A inital funtion with parameters
    : x(i) // inital class A data x=i
{
  cout << "Hello from A::A(int) constructor" << endl;
}

A::A(const A& a)//class A inital funtion with alias of class A
    : x(a.x) // inital class A data x=0
{
  cout << "Hello from A::A(const A&) constructor" << endl;
}

A::~A() //destructor funtion
{
  cout << "Hello from A::A destructor" << endl;
}

void A::operator=(const A& rhs) //operator function in A with const alias of A
{
  x = rhs.x; 
  cout << "Hello from A::operator=" << endl;
}

void A::Print()//A class non-const function 
{
  cout << "A::Print(), x " << x << endl;
}

void A::PrintC() const //A class const function 
{
  cout << "A::PrintC(), x " << x << endl;
}

void PassAByValue(A a)  // gloable function with class object parameter
{
  cout << "PassAByValue, a.x " << a.x << endl;
  a.x++;  //access x by dot expression to increment
  a.Print();
  a.PrintC();
}

void PassAByReference(A& a) // gloable function with class alias parameter
{
  cout << "PassAByReference, a.x " << a.x << endl;
  a.x++;  // non-const function call non-const and const func
  a.Print();
  a.PrintC();
}

void PassAByConstReference(const A& a)// gloable function with const class alias parameter
{
  cout << "PassAByReference, a.x " << a.x << endl;
a.PrintC();  //const a call only const method  

//a.Print(); // Call to "non-const" print function fails!
  // Compiler error from above line.  Why?
}

void PassAByPointer(A* a) // gloable function with non-const class pointer
{
  cout << "PassAByPointer, a->x " << a->x << endl;
  a->x++;
  a->Print(); //able to point to non-const and const function
  a->PrintC();
}

int main()
{
  cout << "Creating a0"; getchar();
  A a0;    // create class A object a0 

  cout << "Creating a1"; getchar();
  A a1(1); // create class A object a1 with value-> A(int), a.x=1

  cout << "Creating a2"; getchar();
  A a2(a0); // create class A object a2 with object ->A(const A&)

  cout << "Creating a3"; getchar();
  A a3 = a0; // create class A object a3 copy a0; 

  cout << "Assigning a3 = a1"; getchar();
  a3 = a1; // change a3 to a1 witih value 1

  // Call some of the "A" subroutines
  cout << "PassAByValue(a1)"; getchar();
  PassAByValue(a1); // x=1-2-2 non-const
  cout << "After PassAByValue(a1)" << endl;
  a1.Print();//x=1
  
  cout << "PassAByReference(a1)"; getchar();
  PassAByReference(a1); // x=1-2-2 non-const
  cout << "After PassAByReference(a1)" << endl;
  a1.Print();//x=2
  
  cout << "PassAByConst(a1)"; getchar();
  PassAByConstReference(a1); // x=2
  cout << "After PassAByConstReference(a1)" << endl;
  a1.Print();//x=2
  
  cout << "PassAByPointer(&a1)"; getchar();
  PassAByPointer(&a1); // x=2-3-3
  cout << "After PassAByPointer(a1)" << endl;
  a1.Print();//x=3

  // x=10
  cout << "a1.X() = 10"; getchar();
  a1.X() = 10;
  a1.Print();

  cout << "PassAByConstReference"; getchar();
  PassAByConstReference(20);//x=20
  //passing the class alias to value 20, since x initial as a.x x=20 
  // Why does the above compile?  What does it do?

  return 0;
}