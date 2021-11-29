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

void ChocAnDataCenter::append(Service *new_service){
    provided_service_directory->append(new_service);
}

void ChocAnDataCenter::print_provided_list(){
    provided_service_directory->print_list();
}