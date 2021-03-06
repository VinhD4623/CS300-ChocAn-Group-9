#ifndef INFO_H
#define INFO_H

#include "define.h"
#include "util.h"
#include <iomanip>
#include <cstring>
#include <string>
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
        string Street;
        string City;
        string State;
        int ZIP;

        Address();
        Address(const Address & source);
        Address(const string _Street, const string _City, const string _State, int _ZIP);
        ~Address();

        void copy_address(const string _Street, const string _City, const string _State, int _ZIP);
        int read_address();
        int edit_address();
        void display();
        friend ostream& operator<<(ostream& outFile, const Address& address);
};

// For Status, true means membership is valid.
class Member
{
    public:
        string Name;
        int ID;
        Address address;
        bool Status;

        Member();
        Member(const Member &);
        Member(const string _Name, int _ID, const Address & _address, bool _Status);
        ~Member();

        void copy_member(const string _Name, int _ID, const Address & _address, bool _Status);
        int read_member();
        int edit_member();
        void display();
        int compare(string _Name);
        char return_name();
};

class Provider
{
    public:
        string Name;
        int ID;
        Address address;
        int TotalMember;
        double TotalFee;

        Provider();
        Provider(const Provider &);
        Provider(const string _Name, int _ID, const Address & _address, int _TotalMember, double _TotalFee);
        ~Provider();

        void copy_provider(const string , int _ID, const Address &, int , double );
        int read_provider();
        int edit_provider();
        void display();
        int compare(string _Name);
        char return_name();
};

class Service
{
    public:
        int service_code;
        // MM-DD-YYYY
        char date[11];
        // MM-DD-YYYY HH-MM-SS
        string dateTime;
        Provider * provider;
        Member * member;
        char comments[100];

        void print();

        Service();
        Service(int _ServiceCode, char _Date[11], string _DateTime, Provider * p, Member * m, char _Comments[100]);
        Service(const Service *);
        ~Service();
};

#endif
