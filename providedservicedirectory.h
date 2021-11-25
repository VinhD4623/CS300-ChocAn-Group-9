#ifndef PROVIDERSERVICEDIRECTORY
#define PROVIDERSERVICEDIRECTORY

#include "info.h"

struct psd_node
{
    psd_node();
    ~psd_node();
    Service service;
    psd_node * next;
};

class ProvidedServiceDirectory{
    public:

        int clear();
        int clear(psd_node *&);

        ProvidedServiceDirectory();
        ~ProvidedServiceDirectory();

    private:
        psd_node *head;
};

#endif