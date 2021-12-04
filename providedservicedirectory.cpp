#include "providedservicedirectory.h"
#include "info.h"
#include <iostream>
#include <fstream>

/****************************
 * psd_node Struct
*****************************/
psd_node::psd_node(): next(NULL)
{}

psd_node::psd_node(Service * new_service): next(NULL){
    this->service = new_service;
}

psd_node::~psd_node()
{
    //if(service) delete service;
}


/*****************************
 * Provided Services Class
******************************/
ProvidedServiceDirectory::ProvidedServiceDirectory(): head (NULL)
{}

psd_node * ProvidedServiceDirectory::copy_list(psd_node *original){
    
    psd_node *current = original;
    
    psd_node *copy = new psd_node();
    copy->service = new Service(*current->service);
    copy->next = NULL;

    psd_node *const head = copy;

    while(current != NULL){
        copy = copy->next = new psd_node;
        copy->service = new Service(*current->service);
        copy->next = NULL;
        current = current->next;
    }
    
    return head;
}

string ProvidedServiceDirectory::get_name(psd_node *&current, int current_id){
    if(current == NULL) return NULL;

    if(current->service->member->ID == current_id){
        return current->service->member->Name;
    }
    return get_name(current->next, current_id);
}

string ProvidedServiceDirectory::get_dateTime(psd_node *&current, int current_id){
    if(current == NULL) return NULL;

    if(current->service->member->ID == current_id){
        return current->service->dateTime;
    }
    return get_dateTime(current->next, current_id);
}

void ProvidedServiceDirectory::create_member_reports(int current_id){
    if(this->head == NULL) return;

    string name = this->get_name(this->head, current_id);
    string dateTime = this->get_dateTime(this->head, current_id);

    string filename = "memberReports/" + name + " " + dateTime;

    ofstream outfile(filename);
    
    psd_node * current = this->head;

    while(current != NULL){
        if(current->service->member->ID == current_id){
            ifstream pFile(filename);
            if(pFile.peek() == std::ifstream::traits_type::eof()){
                outfile << "Member Name: " << current->service->member->Name << endl
                << "Member ID: " << current->service->member->ID << endl
                << current->service->member->address << endl;
            }
            pFile.close();
            outfile << "\n    Date Provided: " << current->service->date << endl
            << "    Provider Name: " << current->service->provider->Name << endl
            << "    Service Code: " << current->service->service_code << endl;
        }
        current = current->next;
    }
    outfile.close();
}

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
    if(head->service) delete head->service;
    delete head;
    return clear(temp);
}

//Append the services to the report
void ProvidedServiceDirectory::writeToFile(string filename){

}

int * ProvidedServiceDirectory::list_all_IDs(int * all_IDs){
    if(this->head == NULL){
        cout << "\nThe list is empty" << endl;
    }
    
    int index = 0;
    index = list_all_IDs(this->head, all_IDs, index);
    
    return all_IDs;
}

int ProvidedServiceDirectory::list_all_IDs(psd_node *&current, int all_IDs[100], int index){
    if(current == NULL) return index;

    if(index == 0){
        all_IDs[index] = current->service->member->ID;
        return list_all_IDs(current->next, all_IDs, ++index);
    }

    for(int i=0; i<index; i++){
        if(all_IDs[i] == current->service->member->ID){
            return list_all_IDs(current->next, all_IDs, index);
        }
    }

    all_IDs[index] = current->service->member->ID;
    
    return list_all_IDs(current->next, all_IDs, ++index);

}