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
        int writeToFile();
        int loadDirectory();


    private:
 	mnode * head;

	int addMember(mnode *&, mnode *);
        int removeMember(mnode *&, char * name);
};

#endif
