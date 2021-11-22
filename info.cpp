#include "info.h"

int MAXCHAR = 101;
using namespace std;
// Junfei Sun
///////////////////////////////
//Address Class
///////////////////////////////
//Constructor
Address::Address()
{
    Street = NULL;
    City = NULL;
    State = NULL;
}


//Copy constuctor
Address::Address(const Address & source)
{
    copy_address(source.Street, source.City, source.State, source.ZIP);
}


//Destructor
Address::~Address()
{
    if(Street) delete [] Street;
    if(City) delete [] City;
    if(State) delete [] State;
}


//Copy the contents of another address
void Address::copy_address(const char * _Street, const char * _City, const char * _State, int _ZIP)
{   
    if(Street){
        delete [] Street;
        Street = NULL;
    }
    Street = new char[strlen(_Street) + 1];
    strcpy(Street,_Street);

    if(City){
        delete [] City;
        City = NULL;
    }
    City = new char[strlen(_City) + 1];
    strcpy(City, _City);
    if(State){
        delete [] State;
        State = NULL;
    }
    State = new char[strlen(_State) + 1];
    strcpy(State,_State);

    ZIP = _ZIP;
}


//Read in the fields for an address
int Address::read_address()
{
   char new_Street[MAXCHAR];
   char new_City[MAXCHAR];
   char new_State[MAXCHAR];
   int new_zip = 0;

    read_string("Street: ", new_Street, MAXCHAR);
    read_string("City: ", new_City, MAXCHAR);
    read_string("State: ", new_State, MAXCHAR);
    new_zip = read_int("Zip: ");

    copy_address(new_Street, new_City, new_State, new_zip);
    return 0;
}


//Allow the user to select address fields to edit
int Address::edit_address()
{
    char choice;
    do{
        cout << "A: Street \nB: City \nC: State \nD: ZIP \nQ: Quit\n";
        choice = read_cmd();
        if(choice == 'A'){
            char new_Street[MAXCHAR];
            read_string("Street: ", new_Street, MAXCHAR);
            if(Street){
                delete [] Street;
                Street = NULL;
            }
            Street = new char[strlen(new_Street)];
            strcpy(Street, new_Street);
        }
        else if(choice == 'B'){
            char new_City[MAXCHAR];
            read_string("City: ", new_City, MAXCHAR);
            if(City){
                delete [] City;
                City = NULL;
            }
            City = new char[strlen(new_City)];
            strcpy(City, new_City);
        }
        else if(choice == 'C'){
            char new_State[MAXCHAR];
            read_string("State: ", new_State, MAXCHAR);
            if(State){
                delete [] State;
                State = NULL;
            }
            State = new char[strlen(new_State)];
            strcpy(State, new_State);
        }
        else if(choice == 'D'){
            ZIP = read_int("Zip: ");
        }
    }while(choice != 'Q');
    return 0;
}


//Display the address contents
void Address::display()
{
    cout << "Street: " << Street << "\n"
        << "City: " << City << "\n"
        << "State: " << State << "\n"
        << "ZIP: " << ZIP << "\n";
}










///////////////////////////////
// Member Class
///////////////////////////////

//Constructor
Member::Member()
{
    Name = NULL;
    ID = 0;
    Status = NULL;
}


//Copy constructor
Member::Member(const Member & source)
{
    copy_member(source.Name, source.ID, source.address, source.Status);
}


//Destructor
Member::~Member()
{
    if(Name) delete [] Name;
}


//Copy the passed in arguments to fill current Member fields
void Member::copy_member(const char * _Name, int _ID, const Address & A, bool _Status)
{
    Name = new char[strlen(_Name) + 1];
    strcpy(Name,_Name);   
    ID = _ID;
    address.copy_address(A.Street, A.City, A.State, A.ZIP);
    Status = _Status;
}



//Reads in the information from user to fill in the Member fields
int Member::read_member()
{
    char new_Name[MAXCHAR];
    if(Name){
        delete [] Name;
        Name = NULL;
    }
    read_string("Name: ", new_Name, MAXCHAR);
    Name = new char[strlen(new_Name) + 1];
    strcpy(Name, new_Name);

    ID = read_int("ID: ");
    address.read_address();
    Status = read_bool("Active? (y/n): ");
    return 0;
}



/*
Prompts the user which Member fields they would like to edit
Loops and ask which Member field they would like to change until user selects Q to exit the menu
*/
int Member::edit_member()
{
    char choice;

    do{
        cout << "A: Name\n" << "B: ID\n" << "C: Address\n" << "D: Active Status\n" << "Q: Quit\n";
        choice = read_cmd();
        if(choice == 'A'){
            char new_Name[MAXCHAR];
            read_string("Name: ", Name, MAXCHAR);
            if(Name){
                delete [] Name;
                Name = NULL;
            }
            Name = new char[strlen(new_Name) + 1];
            strcpy(Name, new_Name);
        }
        else if(choice == 'B'){
            ID = read_int("ID: ");
        }
        else if(choice == 'C'){
            address.edit_address();
        }else if(choice == 'D'){
            Status = read_bool("Active? (y/n): ");
        }

    }while(choice != 'Q');
    return 0;
}


//Display the Member's contents
void Member::display()
{
    cout << "Name: " << Name << endl
        << "ID: " << ID << endl;
    address.display();
    cout << "Active: ";
    if(Status == 1)
        cout << "Yes\n";
    else
        cout << "No\n";
}




///////////////////////////////
//Provider Class
///////////////////////////////
Provider::Provider()
{
    Name = NULL;
}

Provider::Provider(const Provider & source)
{
    copy_provider(source.Name, source.ID, source.address, source.TotalMember, source.TotalFee);
}

Provider::~Provider()
{
    if(Name) delete [] Name;
}

void Provider::copy_provider(const char * _Name, int _ID, const Address & A, int _TotalMember, double _TotalFee)
{
    if(Name){
        delete [] Name;
        Name = NULL;
    }
    Name = new char[strlen(_Name) + 1];
    strcpy(Name,_Name);
    ID = _ID; 
    address.copy_address(A.Street, A.City, A.State, A.ZIP);
    TotalMember = _TotalMember;
    TotalFee = _TotalFee;
}


int Provider::read_provider()
{
    char new_Name[MAXCHAR];
    if(Name){
        delete [] Name;
        Name = NULL;
    }
    read_string("Name: ", new_Name, MAXCHAR);
    Name = new char[strlen(new_Name) + 1];
    strcpy(Name, new_Name);

    ID = read_int("ID: ");
    address.read_address();
    TotalMember = read_int("Total number of members: ");
    TotalFee = read_double("Total fee: ");
    
    return 0;
}


int Provider::edit_provider()
{
    char choice;

    do{
        cout << "A: Name\n" << "B: ID\n" << "C: Address\n" 
            << "D: Active Status\n" << "E: Total number of members\n"
            << "F: Total fee: \n" << "Q: Quit\n";
        choice = read_cmd();
        if(choice == 'A'){
            char new_Name[MAXCHAR];
            read_string("Name: ", Name, MAXCHAR);
            if(Name){
                delete [] Name;
                Name = NULL;
            }
            Name = new char[strlen(new_Name) + 1];
            strcpy(Name, new_Name);
        }
        else if(choice == 'B'){
            ID = read_int("ID: ");
        }
        else if(choice == 'C'){
            address.edit_address();
        }else if(choice == 'D'){
            TotalMember = read_int("Total number of members: ");

        }
        else if(choice == 'E'){
            TotalFee = read_double("Total fee: $");
        }

    }while(choice != 'Q');
    
    return 0;
}

void Provider::display()
{
    cout << "Name: " << Name << endl
        << "ID: " << ID << endl;
    address.display();
    cout << "Total number of client members: " << TotalMember << endl 
        << "Total fee: $" << fixed << setprecision(2) << TotalFee << endl;
}


int Provider::compare(char * name)
{
    if(!strcasecmp(Name, name))
        return 1;
    else
        return 0;
}

char Provider::return_name()
{
    return tolower(Name[0]);
}




///////////////////////////////
//Service Class
///////////////////////////////

Service::Service(){}
Service::Service(const char * _Name, int _ServiceCode, int _Date[8], int _DateTime[14], const Provider * p, const Member * m, double _Fee)
{
    Name = new char[strlen(_Name) + 1];
    strcpy(Name, _Name);
    ServiceCode = _ServiceCode;

    for(int i = 0; i < 8; ++i)
        Date[i] = _Date[i];
    for(int j = 0; j < 14; ++j)
        DateTime[j] = _DateTime[j];

    provider = new Provider(*p);
    member = new Member(*m);
    Fee = _Fee;
}
Service::~Service()
{
    if(Name) delete [] Name;
    if(provider) delete provider;
    if(member) delete member;
}



