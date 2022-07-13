#ifndef __IntegerSet_H_
#define __IntegerSet_H_

class IntegerSet {
  public:
    IntegerSet();
    IntegerSet(int [], int);
    IntegerSet unionOfSets(const IntegerSet&);
    IntegerSet intersectionOfSets(const IntegerSet&);
    bool isEqualTo(const IntegerSet&);
    void emptySet();
    void inputSet();
    void insertElement(int);
    void deleteElement(int);
    void printSet() const;
  
  private:
    int set [101];
    int validEntry(int x) const{
      return (x >= 0 && x <= 100);
    }
};

#endif