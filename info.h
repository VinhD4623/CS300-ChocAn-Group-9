#include "define.h"
#include "util.h"
#include <iomanip>
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
        Address(const Address & source);
        ~Address();

        void copy_address(const char * _Street, const char * _City, const char * _State, int _ZIP);
        int read_address();
        int edit_address();
        void display();
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
        Member(const Member &);
        ~Member();

        void copy_member(const char * _Name,int _ID, const Address & A, bool _Status);
        int read_member();
        int edit_member();
        void display();
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
        Provider(const Provider &);
        ~Provider();

        void copy_provider(const char * , int _ID, const Address &, int , double );
        int read_provider();
        int edit_provider();
        void display();
        int compare(char *);
        char return_name();

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
        Service(const char * _Name, int _ServiceCode, int _Date[8], int _DateTime[14], const Provider * p, const Member * m, double _Fee);
        ~Service();
};
