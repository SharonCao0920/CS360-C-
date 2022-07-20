#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H

#include <iostream>
using namespace std;

class DoubleSubScriptedArray{
  friend ostream &operator<<(ostream &, const DoubleSubScriptedArray &);
  friend istream &operator>>(istream &, DoubleSubScriptedArray &);
  
  public:
    explicit DoubleSubScriptedArray(int = 2, int = 2); 
    DoubleSubScriptedArray(const DoubleSubScriptedArray &); 
    ~DoubleSubScriptedArray(); 
    int getSize() const; 
    
    const DoubleSubScriptedArray &operator=(const DoubleSubScriptedArray &); 
    bool operator==(const DoubleSubScriptedArray &) const; 
    
    bool operator!=(const DoubleSubScriptedArray &right) const{
      return !(*this == right); 
    } 
    
    int &operator[](int);
    
    int operator[](int) const;
    
    int &operator()(int, int);
    
    int operator()(int, int) const;
  
  private:
    int size; 
    int *ptr; 
    int rows;
    int cols;
}; 

#endif