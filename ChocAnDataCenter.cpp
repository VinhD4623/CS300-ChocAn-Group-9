#include "ChocAnDataCenter.h"
#include "providerdirectory.h"
#include "providedservicedirectory.h"

ChocAnDataCenter::ChocAnDataCenter(){
    this->provider_directory = new ProviderDirectory();
    this->provided_service_directory = new ProvidedServiceDirectory();
}

ChocAnDataCenter::~ChocAnDataCenter(){

    if(provider_directory) delete provider_directory;
    if(provided_service_directory) delete provided_service_directory;
}

void ChocAnDataCenter::createMemberReports(){
    cout << "\nThe original list is: " << endl;
    provided_service_directory->print_list();
/*
    ProvidedServiceDirectory *copy = new ProvidedServiceDirectory();
    copy->head = copy->copy_list(this->provided_service_directory->head);
    
    cout << "\nThe copied list is: " << endl;
    copy->print_list();
    //create a provided service directory for the first member in the list
    //ProvidedServiceDirectory *current_member = new ProvidedServiceDirectory();
*/
/*
    ProvidedServiceDirectory *current_member = new ProvidedServiceDirectory();
    current_member->head = current_member->search_list(copy->head);
    cout << "The search for a member found these services: " << endl;
    current_member->print_list();
    cout << "DONEDONEONDEOND" << endl;
*/
    provided_service_directory->create_member_reports();
}

void ChocAnDataCenter::append(Service *new_service){
    provided_service_directory->append(new_service);
}

void ChocAnDataCenter::print_provided_list(){
    provided_service_directory->print_list();
}

void ChocAnDataCenter::addProvider(){
    provider_directory->addProvider();
}

void ChocAnDataCenter::searchProvider(){
    provider_directory->searchProvider();
}

void ChocAnDataCenter::printProviderDirectory(){
    provider_directory->printList();
}

void ChocAnDataCenter::removeProvider(){
    provider_directory->removeProvider();
}

void ChocAnDataCenter::editProvider(){
    provider_directory->editProvider();
}

void ChocAnDataCenter::saveProviderDirectory(){
    provider_directory->writeToFile();
}

void ChocAnDataCenter::loadProviderDirectory(){
    provider_directory->loadDirectory();
}

void ChocAnDataCenter::createProviderReport(){
    provider_directory->createReport();

}

void ChocAnDataCenter::addService(Service *& new_service){
    provider_directory->addService(new_service);
}

void ChocAnDataCenter::print_provider_list(){
    provider_directory->printList();
}