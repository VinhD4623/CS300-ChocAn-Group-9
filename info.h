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
        char * Street;
        char * City;
        char * State;
        int ZIP;

        Address();
        Address(const Address & source);
        Address(const char * _Street, const char * _City, const char * _State, int _ZIP);
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
        Member(const char * _Name,int _ID, const Address & A, bool _Status);
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
        Provider(const char * , int _ID, const Address &, int , double );
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
        int service_code;
        // MM-DD-YYYY
        char date[11];
        // MM-DD-YYYY HH-MM-SS
        string dateTime;
        Provider * provider;
        Member * member;
        char comments[100];

        Service();
        Service(int _ServiceCode, char _Date[11], string _DateTime, Provider * p, Member * m, char _Comments[100]);
        ~Service();
};

#endif