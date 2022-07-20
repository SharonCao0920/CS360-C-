#include <iostream>
#include <string>
#include "DoubleSubScriptedArray.h"
using namespace std;

int main(void){
  DoubleSubScriptedArray chessBoard(3, 5);
  chessBoard[0] = 10;
  chessBoard[1] = 20;
  chessBoard[2] = 30;
  
  
  chessBoard(1, 3) = 24;
  chessBoard(1, 4) = 27;
  cout << "Value at (1, 3): " << chessBoard(1, 3) << endl;
  cout << "Value at (1, 4): " << chessBoard(1, 4) << endl;
  cout << "chessBoard: " << endl << chessBoard << endl;
  
  // == operator:
  DoubleSubScriptedArray myArray(2, 2);
  myArray[0] = 10;
  myArray[1] = 20;
  myArray[2] = 30;
  myArray[3] = 40;
  cout << "myArray: " << endl << myArray << endl;
  cout << "chessBoard == myArray : " << (chessBoard == myArray) << endl;
  myArray[3] = 50;
  cout << "myArray: " << endl << myArray << endl;
  cout << "chessBoard == myArray : " << (chessBoard == myArray) << endl;
  
  // != operator:
  cout << "chessBoard != myArray : " << (chessBoard != myArray) << endl;
  myArray[3] = 40;
  cout << "myArray: " << endl << myArray << endl;
  cout << "chessBoard != myArray : " << (chessBoard != myArray) << endl;
  
  // = operator:
  DoubleSubScriptedArray myScondArray(2, 5);
  myScondArray(1, 0) = 100;
  cout << "myScondArray: " << endl << myScondArray << endl;
  myScondArray = myArray;
  cout << "myScondArray: " << endl << myScondArray << endl;
  
  // >> operator:
  int newRows, newCols;
  cout << "How many rows do you need?" << endl;
  cin >> newRows;
  cout << "How many columns?" << endl;
  cin >> newCols;
  DoubleSubScriptedArray myThirdArray(newRows, newCols);
  cout << "Enter " << newRows*newCols << " numbers:" << endl;
  cin >> myThirdArray;
  
  cout << "myThirdArray:" << endl << myThirdArray << endl;

} 