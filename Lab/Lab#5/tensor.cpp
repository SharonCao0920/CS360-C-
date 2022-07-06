#include<iostream>
#include <vector>

using namespace std;
 
class Tensor{
  public:
    void vectorSort(vector<int> v){
      int temp;  
      for (int i=0; i< v.size()-1; i++){
          for (int j=0; j<v.size()-i-1; j++){
            if (v[j] > v[j+1]){
              temp = v[j];
              v[j] = v[j+1];
              v[j+1] = temp;
            }
          }
        }

      cout << "Reversed vector is: "<< endl;
      for (int i : v)
        cout << i << " ";
      cout << endl;
    }
};

int main(){
  vector<int> v = {6,3,8,9,1,0,2,4,7,5};
  cout << "Current vector is: "<< endl;
  for (int i : v)
          cout << i << " ";
  cout << endl;
  Tensor t;
  t.vectorSort(v);
  return 0;
}