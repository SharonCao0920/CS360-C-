/*
  1.Complete the program, relying on class container sort function to implement sorting for a given array.
*/

#include <iostream>   
#include <algorithm>  
#include <vector>       
using namespace std;

class Container{
  public:  
    //bubble sort
    void sort(int arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
      for (j = 0; j < n - i - 1; j++)
        if (arr[j] > arr[j + 1])
          swap(arr[j], arr[j + 1]);
  }
    
    void printArray(int arr[], int size){
      int i;
      for (i = 0; i < size; i++)
          cout << arr[i] << " ";
      cout << endl;
    }
};

int main (void) {
  int arr[] = {3,7,12,45,26,81,52,33};
  //Write the source code here
  int len = sizeof(arr) / sizeof(arr[0]);
  cout << "Array length is: " << len << endl;
  Container c;
  cout << "Original array is: " << endl;
  c.printArray(arr, len);

  cout << "Array after sorting is: " << endl;
  c.sort(arr, len);
  c.printArray(arr, len);

  return 0;
  
}
