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
                       //                       
  int x;       // class variable x;
public:
  // 
  int& X() { return x; } 
};

A::A()
  : x(0)
{ 
  cout << "Hello from A::A() Default constructor" << endl;
}

A::A(int i)
    : x(i)
{
  cout << "Hello from A::A(int) constructor" << endl;
}

A::A(const A& a)
    : x(a.x)
{
  cout << "Hello from A::A(const A&) constructor" << endl;
}

A::~A()
{
  cout << "Hello from A::A destructor" << endl;
}

void A::operator=(const A& rhs)
{
  x = rhs.x;
  cout << "Hello from A::operator=" << endl;
}

void A::Print()
{
  cout << "A::Print(), x " << x << endl;
}

void A::PrintC() const
{
  cout << "A::PrintC(), x " << x << endl;
}

void PassAByValue(A a)
{
  cout << "PassAByValue, a.x " << a.x << endl;
  a.x++;  //
  a.Print();
  a.PrintC();
}

void PassAByReference(A& a)
{
  cout << "PassAByReference, a.x " << a.x << endl;
  a.x++;  // 
  a.Print();
  a.PrintC();
}

void PassAByConstReference(const A& a)
{
  cout << "PassAByReference, a.x " << a.x << endl;
a.PrintC();  //

//a.Print(); // Call to "non-const" print function fails!
  // Compiler error from above line.  Why?
}

void PassAByPointer(A* a)
{
  cout << "PassAByPointer, a->x " << a->x << endl;
  a->x++;
  a->Print(); 
  a->PrintC();
}

int main()
{
  cout << "Creating a0"; getchar();
  A a0;    // 

  cout << "Creating a1"; getchar();
  A a1(1); // 

  cout << "Creating a2"; getchar();
  A a2(a0); // 

  cout << "Creating a3"; getchar();
  A a3 = a0; // 

  cout << "Assigning a3 = a1"; getchar();
  a3 = a1; // 

  // Call some of the "A" subroutines
  cout << "PassAByValue(a1)"; getchar();
  PassAByValue(a1); // 
  cout << "After PassAByValue(a1)" << endl;
  a1.Print();
  
  cout << "PassAByReference(a1)"; getchar();
  PassAByReference(a1); // 
  cout << "After PassAByReference(a1)" << endl;
  a1.Print();
  
  cout << "PassAByConst(a1)"; getchar();
  PassAByConstReference(a1); // 
  cout << "After PassAByConstReference(a1)" << endl;
  a1.Print();
  
  cout << "PassAByPointer(&a1)"; getchar();
  PassAByPointer(&a1); // 
  cout << "After PassAByPointer(a1)" << endl;
  a1.Print();

  // 
  cout << "a1.X() = 10"; getchar();
  a1.X() = 10;
  a1.Print();

  cout << "PassAByConstReference"; getchar();
  PassAByConstReference(20);

  // Why does the above compile?  What does it do?

  return 0;
}