# include <iostream>
using namespace std;
template <class Type>
bool isEqualTo(Type a ,Type b)
{
    if(a==b)
        return true;
    return false;
}

int main ()
{
    int a=1,b=2,f=2;
    double c=3.3,d=4.7,e=4.7;
    cout<<"a=1,b=2: "<<isEqualTo(a,b)<<endl;
    cout<<"b=2,f=2: "<<isEqualTo(b,f)<<endl;
    cout<<"c=3.3,d=4.7: "<<isEqualTo(c,d)<<endl;
    cout<<"d=4.7,e=4.4: "<<isEqualTo(d,e)<<endl;

    system("pause");
    return 0;
}