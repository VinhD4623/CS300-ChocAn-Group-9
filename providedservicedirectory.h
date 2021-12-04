#ifndef PROVIDERSERVICEDIRECTORY
#define PROVIDERSERVICEDIRECTORY

#include "info.h"

struct psd_node
{
    psd_node();
    psd_node(Service *);
    ~psd_node();
    Service * service;
    psd_node * next;
};

class ProvidedServiceDirectory{
    public:

        int clear();
        int clear(psd_node *&);
        void append(Service *new_service);
        psd_node * append(psd_node *&, psd_node *&);
        void print_list();
        void print_list(psd_node *&);

        void create_member_reports(int);
        psd_node * copy_list(psd_node *);
        psd_node * search_list(psd_node *);
        int * list_all_IDs(int *);
        int list_all_IDs(psd_node *&, int *, int);

        void writeToFile(string);

        ProvidedServiceDirectory();
        ~ProvidedServiceDirectory();

  
        psd_node *head;
};

#endif