#ifndef MEMBERDIRECTORY_H
#define MEMBERDIRECTORY_H

#include <iostream>
#include <list>
#include <fstream>
#include "info.h"
#include <string>
#include "providedservicedirectory.h"

using namespace std;



struct mnode
{
    mnode();
    ~mnode();
    Member member;              
    psd_node * head;    //List of services that member recieved
    mnode * next;
};

class MemberDirectory
{
    public: 
        MemberDirectory();
        ~MemberDirectory();

        //Directory list manipulations
        int addMember();
        int removeMember();
        int clear();
        int editMember();
        int printList();
        int searchMember();

        int validate(const int);
        
        //Provider Directory file read/write
        int writeToFile();      //Saves all the members' information to file
        int loadDirectory();    //Loads all the members's information into list
	int createReport();     //Create a report per provider into file

    private:
 	mnode * head;

	int addMember(mnode *&, mnode *);
        int removeMember(mnode *&, char * name);
	int clear(mnode *& head);
        int editMember(mnode *, char * name);
        int printList(mnode * );
        int searchMember(mnode *, string search);

        int validate(mnode *, const int);
        int createReport(mnode *);
};

#endif
