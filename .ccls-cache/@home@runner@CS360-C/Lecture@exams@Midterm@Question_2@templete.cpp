/*
2.Define a function template interpolSearch() that looks up a given element in a sorted, numeric array. The array elements are of the same type as the template parameter T.

The function template has three parameters - the value searched for of type T, a pointer to the first array element, and the number of array elements.

The function template returns the index of the first element in the array that corresponds to the searched for value, or -1 if the value cannot be found in the array.

Implement the function template and verify it in the main function
*/

#include <iostream>
using namespace std;

template <class T>
long interpolSearch(const T& target, T* p, int len){
  int index, start = 0, end = len - 1;
  double temp;
  //empty or not in range
  if( end < 0 || target > p[end] || target < p[start] )         
    return -1;
  while( start <= end ){ //in array
    if(target > p[end] || target < p[start] ) 
      return -1;   //not in range       
    //Interpolation Search alogorithm
    temp  = (double)(target - p[start])/ (p[end]-p[start]);
    temp  = temp * (end - start) + 0.5;
    index = start + (int)temp;
    if( p[index] == target )           
      return index;
    if( p[index] > target)
      end = index - 1;
    else start = index+1;
  }
  return -1;
}

int main(void){
  double nums[] = {1.5, 3.6, 4.5, 5.6, 6.6, 6.9, 7.8, 8.9};
  int nums1[] = {4, 5, 6, 7,8 ,9, 11, 23};
  char c[] = {'a', 'd', 'f', 'h', 'j', 'l', 'n', 'p', 's', 'z'};
  int result, result1;
  int len = sizeof(nums)/sizeof(nums[0]);
  int len1 = sizeof(nums1)/sizeof(nums1[0]);
  int lenc = sizeof(c)/sizeof(c[0]);
  result = interpolSearch(7.8, nums, len);
  result1 = interpolSearch(5, nums1, len1);
  double target;
  int target1;
  char ct;

  //test for double array
  cout << "Please enter for the value you want to search for in double array: "<<endl;
  cin >> target;
  result = interpolSearch(target, nums, len);
  if( result != -1)
    cout << "The values found at position " << result << endl;
  else
    cout << "Value not found!" << endl;

  //Testing for integer array
  cout << "Please enter for the value you want to search for in integer array: "<<endl;
  cin >> target1;
  result = interpolSearch(target1, nums1, len1);
  if( result != -1)
    cout << "The values found at position " << result << endl;
  else
    cout << "Value not found!" << endl;

  //Testing for char array
  cout << "Please enter for the value you want to search for in char array: "<< endl;
  cin >> ct;
  result = interpolSearch(ct, c, lenc);
  if( result != -1)
    cout << "The values found at position " << result << endl;
  else
    cout << "Value not found!" << endl;
  
  return 0;
}
