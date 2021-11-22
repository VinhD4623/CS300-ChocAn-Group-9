#include "define.h"


///////////////////////////////////////////////////
// Junfei SUn
// Address, Member, Provider, Service Class
// This is not the final verson of prog
// If theese classes need extra functions I will add them 
// When testing, you can add any code to test
///////////////////////////////////////////////////
class Address
{
    public:
        char * Street;
        char * City;
        char * State;
        int ZIP;

        Address();
        Address(const char * _Street, const char * _City, const char * _State, int _ZIP);
        ~Address();
};

// For Status, true means membership is valid.
class Member
{
    public:
        char * Name;
        int ID;
        Address address;
        bool Status;
        Member();
        Member(const char * _Name, int _ID, const Address & A, bool _Status);
        ~Member();
};

class Provider
{
    public:
        char * Name;
        int ID;
        Address address;
        int TotalMember;
        double TotalFee;
        Provider();
        Provider(const char * _Name, int _ID, Address & A, int _TotalMember, double _TotalFee);
        ~Provider();
};

class Service
{
    public:
        char * Name;
        int ServiceCode;
        // MMDDYYYY
        int Date[8];
        // MMDDYYYYHHMMSS
        int DateTime[14];
        Provider * provider;
        Member * member;
        double Fee;

        Service();
        Service(const char * _Name, int _ServiceCode, int _Date[8], int _DateTime[14], Provider * p, Member * m, double _Fee);
        ~Service();
};
