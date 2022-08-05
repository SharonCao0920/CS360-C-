#include<iostream>
using namespace std;

int bill= 0;

class Product{
    private:
        long barcode;
        string name;
    public:
        Product(){
            barcode = 0;
            name = "";
        }
        Product(long b, string s){
            barcode = b;
            name = s;
        }
        void setBarcode(long b) {
            barcode = b;
        }
        long getBarcode(){
            return barcode;
        }
        void setName(string s){
            name = s;
        }
        string getName(){
            return name;
        }
        virtual void scanner(){
            cout<<"Enter barcode, ProductName : ";
            cin>>barcode>>name;
        }
        virtual void printer(){
            cout<<"\nBarcode : "<<barcode<<"\nName : "<<name<<endl;
        }
};

class PrepackedFood : public Product{
        double unitPrice;
    public:
        PrepackedFood(){
            unitPrice = 0;
        }
        PrepackedFood(long b, string n, double up) : Product(b, n){
            unitPrice = up;
        }
        void setUnitPrice(double up){
            unitPrice = up;
        }
        double getUnitPrice(){
            return unitPrice;
        }
        void scanner(){
            int b;
            string n;
            double up;
            cout<<"\nBarcode : ";     cin>>b;
            cout<<"Name : ";          cin>>n;
            cout<<"Price per piece : ";cin>>up;
                
            setBarcode(b);
            setName(n);
            setUnitPrice(up);
            bill += up;
        }
        void printer(){
            cout<<"\nBarcode : "<<getBarcode()<<"\nName : "<<getName()<<"\nPrice per piece : "<<unitPrice<<endl;
        }  
};

class FreshFood : public Product{
        double weight;
        double pricePerKilo;
    public: 
        FreshFood(){
            weight = 0;
            pricePerKilo = 0; 
        }
        FreshFood(long b, string n, double w, double p) : Product(b, n){
            weight = w;
            pricePerKilo = p;
        }
        
        void setWeight(double w){
            weight = w;
        }
        void setPricePerKilo(double p){
            pricePerKilo = p;
        }
        double getWeight(){
            return weight;
        }
        double getPricePerKilo(){
            return pricePerKilo;
        }
        
        void scanner(){
            int b;
            string n;
            double w;
            double p;
            cout<<"\nBarcode : ";     cin>>b;
            cout<<"Name : ";          cin>>n;
            cout<<"Weight(lbs) : ";cin>>w;
            cout<<"Price/lbs : "; cin>>p;
                
            setBarcode(b);
            setName(n);
            setWeight(w);
            setPricePerKilo(p);
                
            bill += (w*p);
        }
        void printer(){
            cout<<"\nBarcode : "<<getBarcode() << "\nName : "
            << getName()<<"\nWeight(lbs) : " << weight << "\nPrice/lbs : "
            << pricePerKilo << "\nTotal : "<< weight*pricePerKilo <<endl;
        }       
};

void show(){
    cout<<"\nWhat is the next article? \n0 = NO more article \n1 = Fresh food \n2 = Prepacked article \n?";
}

void record(){
    Product *ptr[100];
    int n, count = 0;
    show();
        
    FreshFood f[100];
    PrepackedFood p[100];
    int i = 0, j = 0;
                
    cin>>n;
    while(n != 0){
        switch(n){
            case 1 : {
                f[i].scanner();
                ptr[count++] = &f[i];
                i++;
                break;
            }
            case 2 : {
                p[j].scanner();
                ptr[count++] = &p[j];
                j++;
                break;
            }
            default :
                cout<<"Please enter a valid choice!"<<endl;
        }
                show();
                cin>>n;
    }

    double total;
        
    for(int i = 0; i < count; i++){
        cout<<"---------------------"<<endl;
        ptr[i]->printer();   
    }
        
    cout<<"---------------------"<<endl;
    cout<<"Total Price : "<<bill<<endl;
}

int main(void){
    cout<<"\nHere is checkout desk"<<endl;
    char c;
    while(true){
        cin.sync();
        cout<<"\nAnother customer (y/n)?";
        cin>>c;
        if(c == 'y' || c =='Y')
            record();
        else 
            break;
    }
    return 0;
}