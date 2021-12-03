#ifndef CHOCANDATACENTER_H
#define CHOCANDATACENTER_H

#include "providerdirectory.h"
#include "providedservicedirectory.h"
#include "memberdirectory.h"

class ChocAnDataCenter{
    public:
        void append(Service *);
        void print_provided_list();
        
        void addProvider();
        void removeProvider();
        void editProvider();
        void searchProvider();
        void printProviderDirectory();
        void saveProviderDirectory();
        void loadProviderDirectory();
        void createProviderReport();
        void addService(Service *&);
        void print_provider_list();
        void createMemberReports();

        ChocAnDataCenter();
        ~ChocAnDataCenter();

    private:
        MemberDirectory * member_directory;
        ProviderDirectory *provider_directory;
        ProvidedServiceDirectory *provided_service_directory;

};

#endif