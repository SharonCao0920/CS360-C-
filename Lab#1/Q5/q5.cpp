#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
  string s1 = "Good Morning";
  string s2 = "Sarah";
  string s3 = "Sunshine!";
  
  int size = 20;
  int len1, len2, len3;
  len1 = s1.length();
  len2 = s2.length();
  len3 = s3.length();
  //cout << "String length is: " << length << endl;

  //print first string
  cout << right << setw(size - ((size-len1)/2)) << s1 << endl;
  cout << endl;
  
  //print second string
  cout << right << setw(size - ((size-len2)/2)) << s2 << endl;
  cout << endl;
  
  //print third string
  cout << right << setw(size - ((size-len3)/2)) << s3 << endl;
  cout << endl;
  
    return 0;
}