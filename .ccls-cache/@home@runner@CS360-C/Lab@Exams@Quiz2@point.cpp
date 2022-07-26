#include <iomanip>
#include <iostream>
using namespace std;

class PointType {
public:
  // default constructor
  PointType() {
    ptx = 0;
    pty = 0;
  }

  // constructor with parameter value
  PointType(double x, double y) { setPoint(x, y); }

  // setter
  void setPoint(double x, double y) {
    ptx = x;
    pty = y;
  }

  // print function
  void print() { cout << "(" << ptx << "," << pty << ")" << endl; }
  // getters
  double getX() { return ptx; }
  double getY() { return pty; }

private:
  double ptx, pty;
};
