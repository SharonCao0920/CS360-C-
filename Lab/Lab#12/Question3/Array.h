// Array.h
// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
using namespace std;
template<typename T>
class Array;

template<typename T>
istream& operator>> (istream& input, Array<T>&a);

template<typename T>
ostream& operator<<(ostream& output , const Array<T>& a);

template<typename T>

class Array{
    friend istream& operator>> <T>(istream& input, Array<T>&a);
    friend ostream& operator<< <T>(ostream& output , const Array<T>& a);

    public:
        Array(int arraySize);
        Array(const Array &arrayTocopy);
        ~Array();
        int getSize();
        const Array& operator=(const Array& right);
        bool operator==(const Array& right)const;
        int& operator[](int subscript);
        
    private:
        T *arr;
        int size;
};

#endif