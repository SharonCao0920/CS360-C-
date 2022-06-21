/*
1.Write a function that takes a vector of integers as argument and reverses its elements.

void rvrs(Vector<int>& vct){
				//Complete your program  
}
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//reverse vectors
void rvrs(vector<int>& vct){
  //reverse(vct.begin(), vct.end());
  int n = vct.size();
  int temp;
  for (int i=0; i < n/2; i++){
    temp = vct[i];
    vct[i] = vct[n-1];
    vct[n-1] = temp;
    n--;
  }
}

void printV(vector<int>& vct){
  for (int i=0; i<vct.size(); i++){
    cout<<vct[i]<<" ";
  }
  cout<<endl;
}

int main(void){
  vector<int> vct = { 1,2,3,4,5,6,7,8,9,10};
  cout<<"Original Vector: ";
  printV(vct);

  rvrs(vct);

  cout<<"Reversed Vector: ";
  printV(vct);

  return 0;
}