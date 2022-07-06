#include <iostream> 

using namespace std;
using std::string;

class MusicIns{
  public:
    void string(void);
    void wind(void);
    void perc(void);
    void get(void);
    void show(void);
};
//string instruments
void MusicIns :: string(void){
  std::string arr[5] = {"Veena", "guitar", "sitar", "sarod", "mandol"};
  cout << "The value of string: " << endl;
  for (int i=0; i<5; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
//wind instruments
void MusicIns :: wind(void){
  std::string arr[5] = {"Flute", "clarinet", "saxophone", "nadaswaram", "piccolo"};
  cout << "The value of wind: " << endl;
  for (int i=0; i<5; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
//perc instruments
void MusicIns :: perc(void){
  std::string arr[5] = {"Table", "mridangam", "bongos", "drums", "tambour"};
  cout << "THe value of perc: " << endl;
  for (int i=0; i<5; i++){
  cout << arr[i] << " ";
  }
  cout << endl;
}

void MusicIns :: get(void){
  string();
  wind();
  perc();
}

int main(void){
  MusicIns obj;
  obj.get();

  return 0;
  
}