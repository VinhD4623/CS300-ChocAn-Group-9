#include "memberdirectory.h"

using namespace std;



/****************************
 * Mnode Struct
*****************************/
mnode::mnode(): next(NULL)
{}

mnode::~mnode()
{
    next = NULL;
}



/*****************************
 * Member Directory Class
******************************/
MemberDirectory::MemberDirectory(): head (NULL)
{}


MemberDirectory::~MemberDirectory()
{
    //clear();
    head = NULL;
}



//Creates and adds in a new provider in the system
//Takes in user input to fill in the member's information before inserting
int MemberDirectory::addMember()
{
    mnode * obj = new mnode();
    obj->member.read_member();
    if(!head){
        head = obj;
        head->next = NULL;
        return 1;
    }
    return addMember(head, obj);
}



//Helper function to insert new m3mb34 node in alphabetical order
int MemberDirectory::addMember(mnode *& head, mnode * obj)
{
    if(!head){
        head = obj;
        head->next = NULL;
        return 1;
    }
    if(head->member.return_name() > obj->member.return_name()){
        mnode * hold = head;
        head = obj;
        head->next = hold;
        return 1;
    }
    return addMember(head->next, obj);
}



//Ask user to input a member's name to search and remove from the directory
int MemberDirectory::removeMember()
{
    if(!head) return 0;

    char name[30];
    read_string("Name of member to be removed: ", name, 30);

    return removeMember(head, name);
}



//Helper function to search through the list for a matching member name
int MemberDirectory::removeMember(mnode *& head, char * name)
{
    if(!head) return 0;

    if(head->member.compare(name)){
        mnode * temp = head; 
        head = head->next;
        delete temp;
        temp = NULL;
        return 1;
    }
    return removeMember(head->next, name);
}

