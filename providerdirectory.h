#ifndef PROVIDERDIRECTORY_H
#define PROVIDERDIRECTORY_H

#include <iostream>
#include <list>
#include <fstream>
#include "info.h"

using namespace std;



struct pnode
{
    pnode();
    ~pnode();
    Provider provider;
    pnode * next;
};

class ProviderDirectory
{
    public: 
        ProviderDirectory();
        ~ProviderDirectory();
        int addProvider();
        int removeProvider();
        int clear();
        int editProvider();
        int printList();
        int writeToFile();

        int searchProvider();
        int loadDirectory();

        //Provider Services
        int addService();
        int removeService();
        int findService();
        int printService();
        int PrintAllService();

    private:
        pnode * head;

        int addProvider(pnode *&, pnode *);
        int removeProvider(pnode *&, char * name);
        int clear(pnode *& head);
        int editProvider(char * name);
        int printList(pnode * );
};

#endif