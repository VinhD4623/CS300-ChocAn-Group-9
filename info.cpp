#include "info.h"

// Junfei Sun
///////////////////////////////
//Address Class
///////////////////////////////
Address::Address(){}
Address::Address(const char * _Street, const char * _City, const char * _State, int _ZIP)
{
    Street = new char[strlen(_Street) + 1];
    strcpy(Street,_Street);
    City = new char[strlen(_City) + 1];
    strcpy(City, _City);
    State = new char[strlen(_State) + 1];
    strcpy(State,_State);

    ZIP = _ZIP;
}

Address::~Address()
{
    if(Street) delete [] Street;
    if(City) delete [] City;
    if(State) delete [] State;
}
///////////////////////////////
// Member Class
///////////////////////////////
Member::Member(){}
Member::Member(const char * _Name, int _ID, const Address & A, bool _Status)
{
    Name = new char[strlen(_Name) + 1];
    strcpy(Name,_Name);   
    ID = _ID;

    address.Street = new char[strlen(A.Street) + 1];
    strcpy(address.Street,A.Street);
    address.City = new char[strlen(A.City) + 1];
    strcpy(address.City, A.City);
    address.State = new char[strlen(A.State) + 1];
    strcpy(address.State, A.State);
    address.ZIP = A.ZIP;

    Status = _Status;
}
Member::~Member()
{
    if(Name) delete [] Name;
}
///////////////////////////////
//Provider Class
///////////////////////////////
Provider::Provider(){}
Provider::Provider(const char * _Name, int _ID, const Address & A, int _TotalMember, double _TotalFee)
{
    Name = new char[strlen(_Name) + 1];
    strcpy(Name,_Name);
    ID = _ID; 

    address.Street = new char[strlen(A.Street) + 1];
    strcpy(address.Street,A.Street);
    address.City = new char[strlen(A.City) + 1];
    strcpy(address.City, A.City);
    address.State = new char[strlen(A.State) + 1];
    strcpy(address.State, A.State);
    address.ZIP = A.ZIP;

    TotalMember = _TotalMember;
    TotalFee = _TotalFee;
}
Provider::~Provider()
{
    if(Name) delete [] Name;
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

    provider = p;
    member = m;
    Fee = _Fee;
}
Service::~Service()
{
    if(Name) delete [] Name;
    if(provider) delete provider;
    if(member) delete member;
}



