#ifndef PROVIDERDIRECTORY_H
#define PROVIDERDIRECTORY_H

#include <iostream>
#include <list>
#include <fstream>
#include "info.h"
#include <string>
#include "providedservicedirectory.h"

using namespace std;



struct pnode
{
    pnode();
    ~pnode();
    Provider provider;              
    psd_node * head;    //List of provider services that are offered by a provider
    pnode * next;
};

class ProviderDirectory
{
    public: 
        ProviderDirectory();
        ~ProviderDirectory();

        //Directory list manipulations
        int addProvider();
        int removeProvider();
        int clear();
        int editProvider();
        int printList();
        int searchProvider();
        
        //Provider Directory file read/write
        int writeToFile();
        int loadDirectory();

        int createReport(); 

        //Provider Services
        int addService();
        int removeService();
        int findService();
        int printService();
        int PrintAllService();

    private:
        pnode * head;

};

#endif