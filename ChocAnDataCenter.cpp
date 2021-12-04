#include "ChocAnDataCenter.h"
#include "providerdirectory.h"
#include "providedservicedirectory.h"

ChocAnDataCenter::ChocAnDataCenter(){
    this->provider_directory = new ProviderDirectory();
    this->provided_service_directory = new ProvidedServiceDirectory();
}

ChocAnDataCenter::~ChocAnDataCenter(){

    delete this->provider_directory;
    delete this->provided_service_directory;
}

void ChocAnDataCenter::createMemberReports(){
    //provided_service_directory->print_list();

    int all_IDs[100];
    this->get_IDs(all_IDs);

    int i = 0;
    while(all_IDs[i] != 0){
        provided_service_directory->create_member_reports(all_IDs[i]);
        ++i;
    }
}

void ChocAnDataCenter::get_IDs(int all_IDs[]){
    for(int i=0; i<100; i++){
        all_IDs[i] = 0;
    }
    provided_service_directory->list_all_IDs(all_IDs);
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