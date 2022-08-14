#include<iostream>
#include <fstream>
#include <cstdlib>
#define MAX 500 // for 500 address maximum
using namespace std;
//Class addressType definition
class addressType
{
    private:
        //Data member to store street
        string streetAddress;
        //Data member to store city
        string city;
        //Data member to store state
        string state;
        //Data member to store pin
        string zipcode;
    public:
        //Member function to print address
        void print()
        {
        cout<<"\n ----- ADDRESS ----- \n";
        cout<<" Street: "<<streetAddress;
        cout<<"\t City: "<<city;
        cout<<"\t State: "<<state;
        cout<<"\t Zipcode: "<<zipcode;
        }//End of function

        //Default constructor
        addressType()
        {
            streetAddress = city = state = zipcode = "";
        }//End of constructor

        //Parameterized constructor
        addressType(string sa, string c, string st, string z)
        {
            streetAddress = sa;
            city = c;
            state = st;
            zipcode = z;
        }//End of constructor

        //Getter and setter methods
        void setStreetAddress(string sa)
        {
            streetAddress = sa;
        }//End of function
        string getStreetAddress()
        {
            return streetAddress;
        }//End of function
        void setCity(string c)
        {
            city = c;
        }//End of function
        string getCity()
        {
            return city;
        }//End of function

        void setState(string sa)
        {
            state = sa;
        }//End of function
        string getState()
        {
            return state;
        }//End of function
        void setZipcode(string z)
        {
            zipcode = z;
        }//End of function
        string getZipcode()
        {
            return zipcode;
        }//End of function
};//End of class

//Class dateType definition
class dateType
{
    private:
        //Data member to store date, month, and year
        int date, month, year;
    public:
        //Function to print date of birth
        void print()
        {
            cout<<"\n Date of Birth: "<<date<<":"<<month<<":"<<year;
        }//End of function

        //Default constructor
        dateType()
        {
            date = month = year = 0;
        }//End of constructor

        //Parameterized constructor
        dateType(int d, int m, int y)
        {
            date = d;
            month = m;
            year = y;
        }//End of constructor

        //Getter and setter methods
        void setDate(int d)
        {
            date = d;
        }//End of function
        int getDate()
        {
            return date;
        }//End of function
        void setMonth(int m)
        {
            month = m;
        }//End of function
        int getMonth()
        {
            return month;
        }//End of function
        void setYear(int y)
        {
            year = y;
        }//End of function
        int getYear()
        {
            return year;
        }//End of function
        bool isLeapYear(){
            return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        }
};//End of class

//Class personType definition
class personType
{
    public:
        //Parameterized constructor
        personType(string first = " ", string last = " ")
        {
            firstName = first;
            lastName = last;
        }//End of constructor

        //Function to print person name
        void print() const
        {
            cout<<"\n First Name: "<<firstName<<"\t Last Name: "<<lastName;
        }//End of function

        //Getter and setter methods
        void setName(string first, string last)
        {
            firstName = first;
            lastName = last;
        }//End of function
        string getFirstName( ) const
        {
            return firstName;
        }//End of function
        string getLastName( ) const
        {
            return lastName;
        }//End of function

    private:
        //Data member to store first name and last name
        string firstName;
        string lastName;
};//End of class

//Class extPersonType derived from personType
class extPersonType : public personType
{
    private:
        //Data member to store phone number and person status
        string phoneNumber;
        string personStatus;
    public:
        //Delegation mechanism
        //Declares an object of addressType class and dateType class
        addressType address;
        dateType dateOfBirth;

        //Function to print data
        void print() const
        {
            cout<<"\n Phone Number: "<<phoneNumber;
            cout<<"\n Person Type: "<<personStatus;
        }//End of function
        extPersonType()
        { }
        //Parameterized constructor
        extPersonType(addressType a, dateType d, string ph, string ps, string fi, string la):personType(fi, la)
        {
            address = a;
            dateOfBirth = d;
            phoneNumber = ph;
            personStatus = ps;
        }//End of constructor

        //Getter and setter methods
        void setPhoneNumber(string p)
        {
            phoneNumber = p;
        }//End of function
        string getPhoneNumber()
        {
            return phoneNumber;
        }//End of function
        void setPersonStatus(string p)
        {
            personStatus = p;
        }//End of function
        string getPersonStatus()
        {
            return personStatus;
        }//End of function
};//End of function

//Class addressBookType definition
class addressBookType
{
    private:
        //Declares an array of objects of extPersonType class of size MAX
        extPersonType ept[MAX];
        //To store number of records
        int numberOfRecord;
    public:

        //Function to return number of records
        int getNumberOfRecord()
        {
            return numberOfRecord;
        }//End of function

        //Prototype of the functions
        void readFile(string);
        void displayFile();
        void sortLastName();
        void searchLastName(string, int);
        void getAddressByMonth(int);
        void duplicateType(string);
        void saveData();
};//End of class

//Function to display duplicate person status
void addressBookType::duplicateType(string type)
{
    //Loop variable
    int x;
    //Loops till number of records
    for(x = 0; x < getNumberOfRecord(); x++)
    {
        //Checks if current person status is equal to the person status given as parameter then display the person information
        if(ept[x].getPersonStatus().compare(type) == 0)
        {
            cout<<"\n\n\t\t\t ******************* Person Information ****************";
            ept[x].personType::print();
            ept[x].address.print();
            ept[x].dateOfBirth.print();
            ept[x].print();
        }//End of if condition
    }//End of for loop
}//End of function

//Function to display the person whose month of the date of birth matches
void addressBookType::getAddressByMonth(int monthNumber)
{
    int x;

    //Loops till number of records
    for(x = 0; x < getNumberOfRecord(); x++)
    {
        //Checks if the current month is equal to previous month then display the person information
        if(ept[x].dateOfBirth.getMonth() == monthNumber)
        {
            cout<<"\n\n\t\t\t ******************* Person Information ****************";
            ept[x].personType::print();
            ept[x].address.print();
            ept[x].dateOfBirth.print();
            ept[x].print();
        }//End of if
    }//End of for
}//End of function

//Function to search a person last name and display person information
void addressBookType::searchLastName(string name, int no)
{
    int x;
    int flag = 0;
    //Loops till number of records
    for(x = 0; x < getNumberOfRecord(); x++)
    {
        //Checks if the current person last name is equal to person name in the parameter
        if(ept[x].personType::getLastName() == name)
        {
            //Check if no is 2 then display complete person information
            if(no == 2)
            {
                cout<<"\n\n\t\t\t ******************* Person Information ****************";
                ept[x].personType::print();
                ept[x].address.print();
                ept[x].dateOfBirth.print();
                ept[x].print();
            }//End of inner if
            //If no is 3 display only address phone number and date of birth
            else
            {
                cout<<"\n\n\t\t\t ******************* Person address phone number and date of birth ****************";
                ept[x].address.print();
                ept[x].dateOfBirth.print();
                ept[x].print();
            }//End of else
            flag = 1;
        }//End of if
    }//End of for
    //Checks if flag value is not one person name not found
    if(flag != 1)
    cout<<"\n Record for "<<name<<" not found.";
}//End of function

//Function to read data from file and store in the class respective data member
void addressBookType::readFile(string fileName)
{
    int co = 0;
    string f, l;
    int d;

    //Creates an object of ifstream
    ifstream rFile;

    //Opens the file Address.txt for reading
    rFile.open(fileName.c_str());


    // Checks if the file unable to open for reading display's error message and stop
    if(!rFile)
    {
        cout<<"\n ERROR: Unable to open the file "<<fileName<<" for reading.";
        exit(0);
    }// End of if condition

    //Loops till end of file
    while(!rFile.eof())
    {
        // Checks if current record counter co is equals to maximum record then display
        // error message and come out of the loop
        if(co == MAX)
        {
            cout<<"\n Reached maximum limit. Cannot add more records.";
            break;
        }// End of while loop

        // Read first and last name
        rFile>>f;
        rFile>>l;
        ept[co].setName(f, l);
        // Reads date of birth
        rFile>>d;
        ept[co].dateOfBirth.setDate(d);
        rFile>>d;
        ept[co].dateOfBirth.setMonth(d);
        rFile>>d;
        ept[co].dateOfBirth.setYear(d);
        rFile.ignore();
        // Reads address
        getline(rFile, l);
        ept[co].address.setStreetAddress(l);
        // Reads city
        getline(rFile, l);
        ept[co].address.setCity(l);
        // Reads state
        getline(rFile, l);
        ept[co].address.setState(l);
        // Reads zip code
        rFile>>l;
        ept[co].address.setZipcode(l);
        // Reads phone number
        rFile>>l;
        ept[co].setPhoneNumber(l);
        // Reads person status
        rFile>>l;
        ept[co].setPersonStatus(l);
        //Increase the counter by one
        co++;
    }//End of while
    //Close file
    rFile.close();
    //Assigns the counter value to the number of records
    numberOfRecord = co;
}//End of function

//Function to write data to file
void addressBookType::saveData()
{
    int co = 0;
    //Creates an object of ofstream
    ofstream wFile;
    //Opens the file AddressNew.txt for writing
    wFile.open("AddressNew.txt");

    //Loops till end of the record
    for(int co = 0; co < numberOfRecord; co++)
    {
        // Writes data to file
        wFile<<ept[co].getFirstName()<<" "<<ept[co].getLastName()<<endl;
        wFile<<ept[co].dateOfBirth.getDate()<<" "<<ept[co].dateOfBirth.getMonth()<<" "
        <<ept[co].dateOfBirth.getYear()<<endl;
        wFile<<ept[co].address.getStreetAddress()<<endl;
        wFile<<ept[co].address.getCity()<<endl;
        wFile<<ept[co].address.getState()<<endl;
        wFile<<ept[co].address.getZipcode()<<endl;
        wFile<<ept[co].getPhoneNumber()<<endl;
        // Checks if it is last record then do not write new line character after it
        if(co == numberOfRecord - 1)
            wFile<<ept[co].getPersonStatus();
        // Otherwise it is not last record write new line character after it
        else
            wFile<<ept[co].getPersonStatus()<<endl;
    }//End of while
    cout<<"\n\n File Saved Successfully.";
    //Close file
    wFile.close();
}//End of function

//Function to display person information
void addressBookType::displayFile()
{
    //Loops till end of the record
    for(int x = 0; x < numberOfRecord; x++)
    {
        cout<<"\n\n\t\t\t ******************* Person "<<(x + 1)<<" Information ****************";
        ept[x].personType::print();
        ept[x].address.print();
        ept[x].dateOfBirth.print();
        ept[x].print();
    }//End of for
}//End of function

//Function to sort the person information based on last name
void addressBookType::sortLastName()
{
    int x, y;
    //Creates an temporary object
    extPersonType temp;
    //Loops till end of the record
    for(x = 0; x < getNumberOfRecord(); x++)
    {
        //Loops till end of the record minus one and x value
        for(y = 0; y < getNumberOfRecord() - x - 1; y++)
        {
            //Checks if the current person last name is greater than next person last name
            if(ept[y].personType::getLastName() > ept[y + 1].personType::getLastName())
            {
                //Swapping process
                temp = ept[y];
                ept[y] = ept[y + 1];
                ept[y + 1] = temp;
            }//End of if
        }//End of inner for
    }//End of outer for
}//End of function

//Displays menu, accepts user choice and return it
int menu()
{
    int choice;
    //Displays menu
    cout<<"\n\n ********************* Address Book Menu *********************";
    cout<<"\n\t 1. Sort the address book by last name. ";
    cout<<"\n\t 2. Search for a person by last name. ";
    cout<<"\n\t 3. Print the address phone number and date of birth of a given person (if exist). ";
    cout<<"\n\t 4. Print names of people whose birthdays are in a given month. ";
    cout<<"\n\t 5. Depending on request, print all family members, friends or business associates. ";
    cout<<"\n\t 6. Save data.";
    cout<<"\n\t 7. Exit.";
    //Accept user choice
    cout<<"\n\t\t What is your choice? ";
    cin>>choice;
    //Return user choice
    return choice;
}//End of function

//Main function definition
int main(void)
{
    int choice;
    int month;
    string data;
    string fileName;
    //Creates an object of addressBookType class
    addressBookType ad;
    cout<<"\n Enter the filename: ";
    cin>>fileName;
    //Read the file contents
    ad.readFile(fileName);

    //Loops till user choice is not 6
    do
    {
        //Displays menu and stores the user choice
        choice = menu();
    switch(choice)
    {
        case 1:
        ad.sortLastName();
        ad.displayFile();
        break;
        case 2:
        cout<<"\n Enter the last name to search record: ";
        cin>>data;
        ad.searchLastName(data, 2);
        break;
        case 3:
        cout<<"\n Enter the last name to print address phone number and date of birth: ";
        cin>>data;
        ad.searchLastName(data, 3);
        break;
        case 4:
        cout<<"\n Enter the month number print address phone number and date of birth: ";
        cin>>month;
        ad.getAddressByMonth(month);
        break;
        case 5:
        cout<<"\n Enter the person type (Family / Friends / Business): ";
        cin>>data;
        ad.duplicateType(data);
        break;
        case 6:
        ad.saveData();
        break;
        case 7:
        cout<<"\n\t\t Thanks for using My Address Book.";
        exit(0);
        default:
        cout<<"\n Invalid choice!";
    }//End of switch - case
    }while(1);//End of do - while
}//End of main function