#ifndef HUGEINT_H4
#define HUGEINT_H56
#include <iostream>
using std::ostream;

class HugeInt{
  friend ostream &operator<<( ostream &, const HugeInt & );
  public:
    HugeInt( long = 0 ); 
    HugeInt( const char * ); 
    HugeInt operator+( const HugeInt & )const;
    HugeInt operator+(int) const;
    HugeInt operator+( const char * ) const;
    bool operator==( const HugeInt & )const;
    bool operator!=( const HugeInt & )const;
    bool operator<( const HugeInt & ) const;
    bool operator<=( const HugeInt & )const;
    bool operator>( const HugeInt & ) const;
    bool operator>=( const HugeInt & ) const;
    HugeInt operator-( const HugeInt & )const;
    HugeInt operator*( const HugeInt & )const;
    HugeInt operator/( const HugeInt & )const;
    int getLength() const;
  private:
    short integer[ 30 ];
};

#endif
