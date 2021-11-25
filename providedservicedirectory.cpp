#include "providedservicedirectory.h"


/****************************
 * psd_node Struct
*****************************/
psd_node::psd_node(): next(NULL)
{}

psd_node::~psd_node()
{
    next = NULL;
}


/*****************************
 * Provided Services Class
******************************/
ProvidedServiceDirectory::ProvidedServiceDirectory(): head (NULL)
{}


ProvidedServiceDirectory::~ProvidedServiceDirectory()
{
    clear();
    head = NULL;
}

int ProvidedServiceDirectory::clear(){
    if(!head) return 0;
    return clear(head);
}

int ProvidedServiceDirectory::clear(psd_node *&head){
 if(!head) return 0;
    psd_node * hold = head;
    head = head->next;
    hold->next = NULL;
    delete hold;
    return 1 + clear(head);
}