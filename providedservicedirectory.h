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

        void create_member_reports();

        void writeToFile(string filename);

        ProvidedServiceDirectory();
        ~ProvidedServiceDirectory();

    private:
        psd_node *head;
};

#endif