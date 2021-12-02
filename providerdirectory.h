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
    ProvidedServiceDirectory serviceList;           
    //psd_node * service_head;    //List of provider services that are offered by a provider
    pnode * next;

    int addService(psd_node *);
    int removeService(psd_node *);
    int printAllService(psd_node *);
    int editService(psd_node *);

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

        int validate(const int);
        
        //Provider Directory file read/write
        int writeToFile();      //Saves all the providers information to file
        int loadDirectory();    //Loads all the providers into list
        int createReport();     //Create a report per provider into file 

        int addService(Service *&);




    private:
        pnode * head;
        
        int addProvider(pnode *&, pnode *);
        int removeProvider(pnode *&, char * name);
        int clear(pnode *& head);
        int editProvider(pnode *, char * name);
        int printList(pnode * );
        int searchProvider(pnode *, string search);

        int validate(pnode *, const int);
        int createReport(pnode *);

        int addService(pnode *, string name, Service *&);

};

#endif