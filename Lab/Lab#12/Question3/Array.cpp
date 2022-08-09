#include "Array.h"
template<typename T>
Array<T>::Array(int arraySize){
    size = arraySize;
    arr = new T[arraySize];
}

template<typename T>
Array<T>::Array(const Array &arrayTocopy){
    size = arrayTocopy.capacity;
    arr = new T[size];

    for(int i=0;i<size;i++){
        arr[i] = arrayTocopy.arr[i];
    }
}

template<typename T>
Array<T>::~Array(){
    size=0;
    delete[] arr;
}

template<typename T>
    int Array<T>::getSize(){
    return size;
}

template<typename T>
const Array<T>& Array<T>::operator=(const Array& right){
    delete[] arr;
    size=right.size;
    arr = new T[size];

    for(int i=0;i<size;i++){
        arr[i] = right.arr[i];
    }
    return *this;
}

template<typename T>
bool Array<T>::operator==(const Array& right)const{
    if(size !=right.size) return false;

    for(int i=0;i<size;i++){
        if(arr[i] != right.arr[i]) return false;
    }
    return true;
}

template<typename T>
int& Array<T>::operator[](int subscript){
    if(subscript<0 || subscript>=size)
        throw("subscript out of range\n");
    return arr[subscript];
}

template<typename T>
istream& operator>>(istream& input, Array<T>&a){
    for(int i=0;i<a.size;i++){
        input>>a.arr[i];
    }
    return input;
}

template<typename T>
ostream& operator<<(ostream& output , const Array<T>& a){
    for(int i=0;i<a.size;i++){
        output<<a.arr[i]<<"\n";
    }
    return output;
}