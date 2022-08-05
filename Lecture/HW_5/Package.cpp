#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//base class Package
class Package {
    private:
        //For sender's info
        string senderName;
        string senderAddress;
        string senderCity;
        string senderState;
        string senderZIPcode;
        //For sender's info
        string receiverName;
        string receiverAddress;
        string receiverCity;
        string receiverState;
        string receiverZIPcode;
        //data members weight and costPerOunce
        double weight;
        double costPerOunce;

    public:
        //parameterized constructor to assign values to the data member of the class Package
        Package(string s_n, string s_addr, string s_cy,string s_st, string s_ZIP, string r_n, 
        string r_addr,string r_cy, string r_st, string r_ZIP, double w,double cost) {
            //SENDER
            senderName = s_n;
            senderAddress = s_addr;
            senderCity = s_cy;
            senderState = s_st;
            senderZIPcode = s_ZIP;
            //RECEIVER
            receiverName = r_n;
            receiverAddress = r_addr;
            receiverCity = r_cy;
            receiverState = r_st;
            receiverZIPcode = r_ZIP;
            //validation weight and cost
            if (w > 0.0 && cost > 0.0) {
                weight = w;
                costPerOunce = cost;
            } else {
                weight = 0.0;
                costPerOunce = 0.0;
            }
        }

        //member functions to get the value stored in data member of the class
        string getsendereceiverName(){ return senderName; }
        string getsendereceiverAddress(){return senderAddress; }
        string getSendCity(){ return senderCity; }
        string getsendereceiverState(){ return senderState; }
        string getsender_ZIP(){return senderZIPcode; }
        string getrecipient_name(){ return receiverName; }
        string getrecipient_address(){ return receiverAddress; }
        string getrecipient_city(){ return receiverCity; }
        string getrecipient_state(){ return receiverState; }
        string getrecipient_ZIP(){ return receiverZIPcode; }
        double getweight(){ return weight; }
        double getcostPerOunce(){ return costPerOunce; }
        //member function to calulate the cost for the package
        double calculateCost(){return weight * costPerOunce;}
};

//derived class
class TwoDayPackage: public Package {
    private:
        double flat_fee;

    public:
        //derived class constructor which calls the base constructor with some parameters
        TwoDayPackage(string s_n, string s_addr, string s_cy, string s_st, string s_ZIP, 
        string r_n, string r_addr, string r_cy, string r_st, string r_ZIP, double w, double cost, 
        double f_fee): Package(s_n, s_addr, s_cy, s_st, s_ZIP, r_n,r_addr, r_cy, r_st, r_ZIP, w, cost) {
            flat_fee = f_fee; //assign value for derived class variable
        }
        double calculateCost(){
            return Package::calculateCost() + flat_fee;
        }
};

//derived class OvernightPackage definition from base class Package
class OvernightPackage: public Package {
    private:
        double additional_fee;
    public:
        //parameterized constructor of the derived class which in turn calls the base class constructor with some parameters
        OvernightPackage(string s_n, string s_addr, string s_cy,string s_st, string s_ZIP, 
        string r_n, string r_addr,string r_cy, string r_st, string r_ZIP, double w, double cost, 
        double addl_fee): Package(s_n, s_addr, s_cy, s_st, s_ZIP, r_n,r_addr, r_cy, r_st, r_ZIP, w, cost) {
            additional_fee = addl_fee; //assign addintional fee value
        }
        //redefining the member function of the base class
        double calculateCost(){
            return (getcostPerOunce() + additional_fee) * getweight();
        }
};

int main(void) {
    //delaring string variables for getting user input
    string sname, saddr, scity, sstate, szip, rname, raddr, rcity, rstate, rzip;
    double w;
    cout << "What is your name? " << endl;
    getline(cin, sname);
    cout << "Please enter your information: " << endl;
    cout << "\tAddress: ";
    getline(cin, saddr);
    cout << "\tCity : ";
    getline(cin, scity);
    cout << "\tState : ";
    getline(cin, sstate);
    cout << "\tZIP code : ";
    getline(cin, szip);
    cout << "\tPackage weight : ";
    cin >> w;
    getchar();
    cout << "Who are you sending to? " << endl;
    getline(cin, rname);
    cout << "Please enter " << rname << " information: " << endl;
    cout << "\tAddress : ";
    getline(cin, raddr);
    cout << "\tCity : ";
    getline(cin, rcity);
    cout << "\tState : ";
    getline(cin, rstate);
    cout << "\tZIP code : ";
    getline(cin, rzip);
    
    TwoDayPackage twoDayPackage = TwoDayPackage(sname, saddr, scity, sstate, szip, rname, raddr, rcity, rstate, rzip, w, 1.5, 1.10);
   
    OvernightPackage overNightPackage = OvernightPackage(sname, saddr, scity, sstate, szip, rname, raddr, rcity, rstate, rzip, w, 1.5, 2.20);

    cout << fixed << setprecision(2);
    cout << "-----------------------------------------------------" << endl;
    cout << "Overnight Delivery" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Sender: " << overNightPackage.getsendereceiverName() << endl;
    cout << "Address: " << overNightPackage.getsendereceiverAddress() << endl;
    cout << "\t" << overNightPackage.getSendCity() << ", " << 
    overNightPackage.getsendereceiverState() << " " << overNightPackage.getsender_ZIP() << endl;
    cout << endl;
    cout << "Recipient: " << overNightPackage.getrecipient_name() << endl;
    cout << "Address: " << overNightPackage.getsendereceiverAddress() << endl;
    cout << "\t" << overNightPackage.getrecipient_city() << ", " <<
    overNightPackage.getrecipient_state() << " " << overNightPackage.getrecipient_ZIP() << endl;
    cout << endl;
    cout << "Cost $ " << overNightPackage.calculateCost() << endl;

    cout << endl;
    cout << fixed << setprecision(2);
    cout << "------------------------------------------------------" << endl;
    cout << "2 Day Delivery" << endl;;
    cout << "------------------------------------------------------" << endl;
    cout << "Sender: " << twoDayPackage.getsendereceiverName() << endl;
    cout << "Address: " << twoDayPackage.getsendereceiverAddress() << endl;
    cout << "\t" << twoDayPackage.getSendCity() << ", " << 
    twoDayPackage.getsendereceiverState() << " " << twoDayPackage.getsender_ZIP() << endl;
    cout << endl;
    cout << "Recipient: " << twoDayPackage.getrecipient_name() << endl;
    cout << "Address: " << twoDayPackage.getsendereceiverAddress() << endl;
    cout << "\t" << twoDayPackage.getrecipient_city() << ", " <<
    twoDayPackage.getrecipient_state() << " " << twoDayPackage.getrecipient_ZIP() << endl;
    cout << endl;
    cout << "Cost $ " << twoDayPackage.calculateCost() << endl;

    return 0;
}