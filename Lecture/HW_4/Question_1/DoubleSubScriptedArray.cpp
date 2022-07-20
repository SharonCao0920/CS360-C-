#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include "DoubleSubScriptedArray.h"
using namespace std;

DoubleSubScriptedArray::DoubleSubScriptedArray(int rowSize, int colSize){
  if (rowSize > 0 && colSize > 0){
    rows = rowSize;
    cols = colSize;
    size = rowSize * colSize;
  }
  else{
    throw invalid_argument("Array size must be greater than 0");
  }
    ptr = new int[size]; 
  
  for (int i = 0; i < size; ++i)
    ptr[i] = 0; 
} 

DoubleSubScriptedArray::DoubleSubScriptedArray(const DoubleSubScriptedArray &arrayToCopy): size(arrayToCopy.size){
  ptr = new int[size]; 
  
  for (int i = 0; i < size; ++i)
    ptr[i] = arrayToCopy.ptr[i]; 
} 

DoubleSubScriptedArray::~DoubleSubScriptedArray(){
  delete[] ptr; 
} 

int DoubleSubScriptedArray::getSize() const{
  return size; 
} 

const DoubleSubScriptedArray &DoubleSubScriptedArray::operator=(const DoubleSubScriptedArray &right){
  if (&right != this) {
    if (size != right.size){
      delete[] ptr; 
      size = right.size; 
      ptr = new int[size]; 
    } 
    for (int i = 0; i < size; ++i)
      ptr[i] = right.ptr[i]; 
    rows = right.rows;
    cols = right.cols;
  } 
  return *this; 
} 

bool DoubleSubScriptedArray::operator==(const DoubleSubScriptedArray &right) const{
  if (size != right.size)
    return false; 
  
  for (int i = 0; i < size; ++i)
    if (ptr[i] != right.ptr[i])
      return false; 
  
  return true; 
} 

int &DoubleSubScriptedArray::operator[](int subscript){
  if (subscript < 0 || subscript >= size)
    throw out_of_range("Subscript out of range");
  
  return ptr[subscript]; 
} 

int DoubleSubScriptedArray::operator[](int subscript) const{
  if (subscript < 0 || subscript >= size)
    throw out_of_range("Subscript out of range");
  
  return ptr[subscript]; 
}

int &DoubleSubScriptedArray::operator()(int row, int column){
  if (row < 0 || row > rows - 1)
    throw out_of_range("Row out of range");
  else if (column < 0 || column > cols - 1)
    throw out_of_range("Column out of range");
  else
    return ptr[row * cols + column]; 
}

int DoubleSubScriptedArray::operator()(int row, int column) const{
  if (row < 0 || row > rows - 1)
    throw out_of_range("Row out of range");
  else if (column < 0 || column > cols - 1)
    throw out_of_range("Column out of range");
  else
    return ptr[row * cols + column];
}

istream &operator>>(istream &input, DoubleSubScriptedArray &a){
  for (int i = 0; i < a.size; ++i)
    input >> a.ptr[i];
  
  return input; 
} 

ostream &operator<<(ostream &output, const DoubleSubScriptedArray &a){
  int i;
  
  for (i = 0; i < a.size; ++i){
    output << setw(12) << a.ptr[i];
    if ((i + 1) % a.cols == 0) 
      output << endl;
  } 
  
  return output; 
} 