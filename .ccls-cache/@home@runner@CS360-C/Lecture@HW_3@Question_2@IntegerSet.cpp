#include "IntegerSet.h"
#include <iomanip>
#include <iostream>

using namespace std;

IntegerSet::IntegerSet() {
  emptySet();
}

IntegerSet::IntegerSet(int arr[], int size){
  emptySet();
  
  for (int i = 0; i < size; i++)
  insertElement(arr[i]);
}

void IntegerSet::emptySet(){
  for (int i = 0; i < 101; i++){
    set [i] = 0;
  }
}

void IntegerSet::inputSet(){
  int number;
  
  do{
    cout << "Mash in some number (-1 will stop): ";
    cin >> number;
    if (validEntry (number) == 1)
      set[number] = 1;
    else if (number != -1)
      cerr << "Invalid numbah\n";
  } while (number != -1);
  
  cout << "Entry Complete\n";
}

void IntegerSet::printSet() const {
  bool empty = true;
  cout << '{';
  
  for (int u = 0; u < 101; u++){
    if (set[u] == 1){
      cout << u << " ";
      empty = false;
    }
  }
  if (empty)
    cout << "...";
  cout << '}';
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet &r) {
  IntegerSet temp;
  
  for (int n = 0; n < 101; n++)
    if ((set [n] == 1 || r.set[n] == 1) || (set [n] == 1 && r.set[n] == 1))
      temp.set[n] = 1;
    return temp;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &r) {
  IntegerSet temp;
  
  for (int n = 0; n < 101; n++)
    if (set [n] == 1 && r.set[n] == 1)
      temp.set[n] = 1;
      return temp;
}

void IntegerSet::insertElement(int k) {
  if (validEntry(k))
    set [k] = 1;
  else
    cerr << "how are you!??!?!\n";
}

void IntegerSet::deleteElement(int k) {
  set[k] = 0;
}

bool IntegerSet::isEqualTo(const IntegerSet &r) {
  for(int i = 0; i < 101; i++)
    if(set[i] != r.set[i])
      return false;
  return true;
}