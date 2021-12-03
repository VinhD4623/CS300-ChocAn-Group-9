#include "providedservicedirectory.h"
#include "info.h"

/****************************
 * psd_node Struct
*****************************/
psd_node::psd_node(): next(NULL)
{}

psd_node::psd_node(Service *new_service): next(NULL)
{
    this->service = new_service;
}

psd_node::~psd_node()
{
    if(service) delete service;
}


/*****************************
 * Provided Services Class
******************************/
ProvidedServiceDirectory::ProvidedServiceDirectory(): head (NULL)
{}

void ProvidedServiceDirectory::append(Service *new_service){
    
    psd_node * temp = new psd_node(new_service);

    if(this->head == NULL){
        this->head = temp;
        return;
    }

    append(this->head, temp);
}

psd_node * ProvidedServiceDirectory::append(psd_node *& current, psd_node *& new_node){
    if(current == NULL){
        current = new_node;
        return current;
    }

    current->next = append(current->next, new_node);

    return current;
}

void ProvidedServiceDirectory::print_list(){
    if(this->head == NULL){
        cout << "\nThe Provided Services list is empty\n" << endl;
    }

    print_list(this->head);
}

void ProvidedServiceDirectory::print_list(psd_node *& current){
    if(current == NULL){
        return;
    }

    current->service->print();

    print_list(current->next);
}

ProvidedServiceDirectory::~ProvidedServiceDirectory()
{
    clear();
    head = NULL;
}

int ProvidedServiceDirectory::clear(){
    if(this->head == NULL){
        return 1;
    }
    return clear(this->head);
}

int ProvidedServiceDirectory::clear(psd_node *&head){

    if(head == NULL){
        return 1;
    }
    psd_node * temp = head->next;
    delete head;
    return clear(temp);
}

//Append the services to the report
void ProvidedServiceDirectory::writeToFile(string filename){

}

