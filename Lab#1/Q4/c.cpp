#include <iostream>
#include <iomanip>
#include <vector>

using std::cout; using std::endl;
using std::vector; using std::fixed;
using std::right; using std::setw;

int main() {
  vector<double> d_vec = {23.62, 46.0, 43.4443, 100.1, 98.98};

  for (auto &i : d_vec) {
    cout.precision(2);
    cout << right
         << setw(10)
         << fixed
             << i << endl;
    }
    cout << endl;

  float sum = 0;
  
  for (auto &i : d_vec) {
    sum += i;
  }

    cout << "The sum is: " << sum << endl;

  
    return 0;
}
