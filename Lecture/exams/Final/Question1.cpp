// staken.cpp
// overloading functions in base and derived classes
#include <iostream>
using namespace std;
#include <cstdlib> //for exit()
////////////////////////////////////////////////////////////////
class Stack{
  protected: //NOTE: can’t be private
    enum { MAX = 6 }; //size of stack array
    int st[MAX]; //stack: array of integers
    int top; //index to top of stack

  public:
    Stack() //constructor
    { top = -1; }
    void push(int var) //put number on stack
    { st[++top] = var; }
    int pop() //take number off stack
    { return st[top--]; }
};
////////////////////////////////////////////////////////////////
class Stack2 : public Stack
{
    public:
        void push(int var) //put number on stack
        {
            if(top >= MAX-1) //error if stack full
            { cout << "\nError: stack is full"; exit(1); }
            Stack::push(var); //call push() in Stack class
        }

        int pop() //take number off stack
        {
            if(top < 0) //error if stack empty
            { cout << "\nError: stack is empty\n"; exit(1); }
            return Stack::pop(); //call pop() in Stack class
        }
};

class pairStack : public Stack2
{
    public:
        void push(pair<int, int> var)
        {
            Stack2::push(var.first);
            Stack2::push(var.second); 
        }
        
        pair<int,int> pop(){
            pair<int,int> ans;
            ans.first = Stack2::pop();
            ans.second = Stack2::pop();
            return ans;
        }
};


int main(){
  pairStack s1;

  s1.push(make_pair(45, 37)); //push some values onto stack
  s1.push(make_pair(90, 20));
  s1.push(make_pair(36, 85));

  pair<int,int> p = s1.pop();
  cout  << endl << "First pair: \n"<< p.first << " " << p.second; //pop some values from stack
  p = s1.pop();
  cout  << endl << "Second pair: \n"<< p.first << " " << p.second;
  p = s1.pop();
  cout  << endl << "Third pair: \n"<< p.first << " " << p.second;
  p = s1.pop();
  //check empty stack
  cout << endl << p.first << " " << p.second; 
  cout << endl;
  return 0;
}