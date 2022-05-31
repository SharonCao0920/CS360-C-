#include <iostream>
#include <iomanip>
#include <vector>

using std::cout; using std::endl;
using std::vector; using std::fixed;
using std::right; using std::setw;

int main() {
    vector<int> d_vec = {1066, 1492, 512, 1, -23};

    for (auto &i : d_vec) {
        cout << right
             << setw(10)
             << fixed
             << i << endl;
    }
    cout << endl;

  float answer;
  answer = (float)( d_vec[0] + d_vec[1]) / ( d_vec[2] + d_vec[3] + d_vec[4]);

  cout.precision(4);
  cout << "The answer is: " << answer << endl;

    return 0;
}