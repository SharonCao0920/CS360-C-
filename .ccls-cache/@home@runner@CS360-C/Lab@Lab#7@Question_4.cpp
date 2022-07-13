/*
4.Start with the publication, book, and tape classes of question 3. Add a base class sales that holds an array of three floats so that it can record the dollar sales of a particular publication for the last three months. Include a getdata() function to get three sales amounts from the user, and a putdata() function to display the sales figures. Alter the book and tape classes so they are derived from both publication and sales. An object of class book or tape should input and output sales data along with its other data. Write a main() function to create a book object and a tape object and exercise their input/output capabilities.
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
    cout << "Enter title of publication: ";
    cin >> t;
    cout << "Enter price of publication: ";
    cin >> p;
    title = t;
    price = p;
  }
  
  void putdata(){
    cout << "Publication title: " << title << endl;
    cout << "Publication price: " << price << endl;
  }
};

class sales{
  private:
    float s1, s2, s3;
  
  public:
    void getdata(){
      cout << "Enter month 1 sale: $";
      cin >> s1;
      cout << "Enter month 2 sale: $";
      cin >> s2;
      cout << "Enter month 3 sale: $";
      cin >> s3;
    }
  
   void putdata(){
    cout << "Month 1 sale: $" << s1 << endl;
    cout << "Month 2 sale: $" << s2 << endl;
    cout << "Month 3 sale: $" << s3 << endl;
  }
};

class book :public publication, public sales{
  private:
    int pagecount;
  public:
    void getdata(){
      publication::getdata();
      //sales::getdata();
      cout << "Enter Book Page Count: ";
      cin >> pagecount;
    }

    void putdata(){
      publication::putdata();
      //sales::putdata();
      cout << "Book page count: " << pagecount << endl;
    }
};

class tape : public publication, public sales{
  private:
    float ptime;
  public:
    void getdata(){
      publication::getdata();
      //sales::getdata();
      cout << "Enter tap's playing time: ";
      cin >> ptime;
    }

    void putdata(){
      publication::putdata();
      //sales::putdata();
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