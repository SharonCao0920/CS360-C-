#include<iostream>
#include<vector>
using namespace std;

void diagonal(vector<vector<int>>  vals){
  //if empty vector
  if(vals.size()==0){
    return;
  }
  //rows
  int rows = vals.size();

  for(int i=rows-1;i>=0;i--){ //from the last element
    //at() to get element reference
    for(int j=0;j<vals.at(i).size();++j){
      //print the element on diagnal
      if(i == (rows-j-1)){
        cout<<vals.at(i).at(j)<<" ";
      }
    } 
  }
  cout << endl;
}

void printMatrix(vector<vector<int>>  vals){
  //if empty vector
  if(vals.size()==0){
    return;
  }
  //rows
  int rows = vals.size();

  for(int i=0;i<rows;i++){ //from the last element
    //at() to get element reference
    for(int j=0;j<vals.at(i).size();j++){
        cout<<vals.at(i).at(j)<<" ";
    }
    cout << endl; 
  }
}

//main function to test
int main(void){
  //create a sample matrix 3X3
  vector<int> r1 = {1, 2, 3};
  vector<int> r2 = {4, 5, 6};
  vector<int> r3 = {7, 8, 9};
  vector<vector<int>> v = {r1, r2, r3};
  
  cout<< "The original matrix is: "<<endl;
  printMatrix(v);

  cout << "The diagonals are: "<< endl;
  diagonal(v);

  return 0;
}