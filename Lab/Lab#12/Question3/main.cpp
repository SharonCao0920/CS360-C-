#include"Array.cpp"

int main(void){
    Array<int> intArray(5);
    cout<<"Enter elements in integer array\n";
    cin>>intArray;

    cout<<"\nYour Array\n";
    cout<<intArray;

    Array<string> strArray(5);
    cout<<"\n\nEnter elements in string array\n";
    cin>>strArray;

    cout<<"\nYour Array\n";
    cout<<strArray;
    return 0;
}