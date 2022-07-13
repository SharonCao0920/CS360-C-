/*
3.Imagine a publishing company that markets both book and audiocassette versions of its works. Create a class publication that stores the title (a string) and price (type float) of a publication. From this class derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float). Each of these three classes should have a getdata() function to get its data from the user at the keyboard, and a putdata() function to display its data.

Write a main() program to test the book and tape classes by creating instances of them, asking the user to fill in data with getdata(), and then displaying the data with putdata().
*/

#include <iostream>
#include <string>

using namespace std;

class publication{
  private:
    string title;
    float price;
  public:
    void getdata(){
    string t;
    float p;
    cout << "\nEnter title of publication: ";
    cin >> t;
    cout << "Enter price of publication: ";
    cin >> p;
    title = t;
    price = p;
  }
  
  void putdata(){
    cout << "\nPublication title: " << title << endl;
    cout << "Publication price: " << price << endl;
  }
};

class book : public publication{
  private:
    int pagecount;
  public:
    void getdata(){
      publication::getdata();
      cout << "Enter Book Page Count: ";
      cin >> pagecount;
    }

    void putdata(){
      publication::putdata();
      cout << "Book page count: " << pagecount << endl;
    }
};

class tape : public publication{
  private:
    float ptime;
  public:
    void getdata(){
      publication::getdata();
      cout << "Enter tap's playing time: ";
      cin >> ptime;
    }

    void putdata(){
      publication::putdata();
      cout << "Tap's playing time: " << ptime << endl;
    }
};

int main(void){
  book b;
  tape t;
  b.getdata();
  t.getdata();
  b.putdata();
  t.putdata();
  return 0;
}