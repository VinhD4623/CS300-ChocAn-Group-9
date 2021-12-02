#ifndef CHOCANDATACENTER_H
#define CHOCANDATACENTER_H

#include "providerdirectory.h"
#include "providedservicedirectory.h"

class ChocAnDataCenter{
    public:
        void append(Service *);
        void print_provided_list();
        
        void addProvider();
        void removeProvider();
        void editProvider();
        void searchProvider();
        void saveProviderDirectory();
        void loadProviderDirectory();
        void createProviderReport();
        void addService(Service *&);

        ChocAnDataCenter();
        ~ChocAnDataCenter();

    private:
        //MemberDirectory member_directory;
        ProviderDirectory *provider_directory;
        ProvidedServiceDirectory *provided_service_directory;

};

#endif