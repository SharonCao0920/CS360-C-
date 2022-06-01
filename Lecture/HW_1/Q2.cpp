#include <iostream>

using namespace std;

class Matrix //class matrix

{
  private: //private variables
  int row, col;
  double *m[10];
  public:
  
  Matrix(int r , int c) //constructor for row col and matrix initialization
  {
    row=r;
    col=c;
    for(int i=0;i<row;i++)
    m[i]= new double[col];
  }
  /* Matrix(Matrix const &ma);*/
  
  friend ostream & operator << (ostream &out, const Matrix &c); //output stream function
  friend istream & operator >> (istream &in, Matrix &c); //input stream function
  void operator=(Matrix &x); //operator overloding functions =
  void operator+=(Matrix &x); //operator overloding functions +=
  void operator-=(Matrix &x); //operator overloding functions -=
  void operator--(); //operator overloding functions --
  void operator++(); //operator overloding functions ++
};

void Matrix :: operator=(Matrix &x) //operator overloding functions = defination
{
  for(int i=0;i<x.row;i++)
  for(int j=0;j<x.col;j++)
  m[i][j]=x.m[i][j];
}

void Matrix :: operator++() //operator overloding functions ++ defination
{
  for(int i=0;i<row;i++)
  for(int j=0;j<col;j++)
  m[i][j]++;
}

void Matrix :: operator--()//operator overloding functions -- defination
{
  for(int i=0;i<row;i++)
  for(int j=0;j<col;j++)
  m[i][j]--;
}
//operator overloding functions += defination
void Matrix ::operator+=(Matrix &x) 
{
  for(int i=0;i<x.row;i++)
  for(int j=0;j<x.col;j++)
  m[i][j]+=x.m[i][j];
}
//operator overloding functions -= defination
void Matrix ::operator-=(Matrix &x) 
{
  for(int i=0;i<x.row;i++)
  for(int j=0;j<x.col;j++)
  m[i][j]-=x.m[i][j];
}

/*Matrix::Matrix(Matrix const &ma)
{
  row=ma.row:
  col=ma.col;
  for(int i=0;i<row;i++)
  for(int j=0;j<col;j++)
  m[i][j]=ma.m[i][j];
} */

//operator overloding functions << defination
ostream & operator << (ostream &out, const Matrix &c) 
{
  for(int i=0;i<c.row;i++)
  {
    for(int j=0;j<c.col;j++)
    {
      out << c.m[i][j];
      cout<<" ";
    }
    cout<<endl;
  }
  return out;
}

istream & operator >> (istream &in, Matrix &c)//operator overloding functions >> defination

{
  cout << "Matrix elements: \n";
  for(int i=0;i<c.row;i++)
  for(int j=0;j<c.col;j++)
  in >> c.m[i][j];
  return in;
}

int main() //main program

{
  int n;
  cout << "Enter row/column size you want for square matrix: "<< endl;
  cin >> n;
  Matrix A(n,n),B(n,n),C(A),D(A),E(B),F(B); //object declaration and call copy constructor
  cout << "Enter for matrix A: " << endl;
  cin >> A; //take input through ifstream
  cout << "Enter for matrix B: " << endl;
  cin >> B; //take input through ifstream
  cout << "Given Matrix A is: "<<endl;
  cout << A; //display output through ofstream
  cout << "Given Matrix A is: "<<endl;
  cout << B; //display output through ofstream

  C=A;
  D=A;
  E=B;
  F=B;
  //cout<<"copy object is "<<endl;
  //cout<<C;
  C+=E; //+= operator loading
  cout<<"after apply += matrix is "<<endl;
  cout<<C;
  cout<<"After apply -= matrix is "<<endl;
  F-=D; //-= operator loading
  cout<<F;
  ++D; //++ operator loading
  cout<<"after applying ++ operator"<<endl;
  cout<<D;
  --F; //-- operator loading
  cout<<"after applying -- operator"<<endl;
  cout<<F;
  
  return 0;

}