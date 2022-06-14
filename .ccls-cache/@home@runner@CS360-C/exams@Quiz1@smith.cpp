/*
a.Create a class, named Smith, including 
i.Public member: int  name
ii.Protected member: int m_home
iii.Private member: int m_wife
iv.Public methods: constructor to initialize name to 1, m_home to 2 and m_wift to 3, and by-default destructor
*/
#include <iostream>

using namespace std;

class Smith{
public:
  int name;
protected:
  int m_home;
private:
  int m_wife;

public:
  //Smith();
  Smith(){
    name=1;
    m_home=2;
    m_wife=3;
  }
  
  int getMHome() const{
    return this->m_home;
  }
  int getMWife() const{
    return this->m_wife;
  }
  ~Smith(){}
};

/*
b.Generate a class, named Son_Smith, inherited from Smith including 
i.Private member: int  flag
ii.Public method: constructor to initialize flag to 4
*/
class Son_Smith : public Smith {
private:
  int flag;
public:
  Son_Smith(){
    flag=4;
  }
};

/*
c. Declare a friend class of Smith, named Friend_Smith including
i. Public method: void help(const  Smith& sm) to print sm.name, sm.m_home and sm.m_wift
*/
class Friend_Smith{
public:
  void help(const Smith& sm){
    cout << "In Friend_Smith: " << endl;
    cout << "Name is: " << sm.name << endl;
    cout << "Home is: " << sm.getMHome() << endl;
    cout << "Wife is: " << sm.getMWife() << endl;
  }
  friend class Smith;
};

/*
d.Create a class, named Son_friend_Smith, inherited from Friend_Smith
i.Public method: void help(const  Smith& uncle_smith) to print uncle_smith.name, uncle_smith.m_home, uncle_smith.m_wift and call the function help in Friend_Smith passing uncle_smith as its argument 
*/
class Son_friend_Smith : public Friend_Smith{
public:
  void help(const  Smith& uncle_smith){
    cout << "Name is: " << uncle_smith.name << endl;
    cout << "Home is: " << uncle_smith.getMHome() << endl;
    cout << "Wife is: " << uncle_smith.getMWife() << endl;
    help(uncle_smith);
  }
};

/*
e.In main function, verify all help functions in the classes, Friend_Smith, Son_friend_Smith and help in Friend_Smith with Son_Smith object argument 
*/
int main (void){
  Smith s;
  Son_Smith ss;
  //verify help in Friend_Smith
  Friend_Smith f;
  f.help(s);
  
  //verify help in Son_friend_Smith
  Son_friend_Smith sf;
  sf.help(s);
  
  // help in Friend_Smith with Son_Smith object argument
  f.help(ss);
  return 0;
}
