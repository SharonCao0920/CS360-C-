//myClass.h
#ifndef myClass_h
#define myClass_h

#include <iostream>
//#pragma once //get warning
class myClass {
  public:
    void Func(void);
    int getNumber(void);
  private:
    const int number = 5 ;
};

#endif