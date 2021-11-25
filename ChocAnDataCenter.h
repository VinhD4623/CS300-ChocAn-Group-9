#ifndef CHOCANDATACENTER_H
#define CHOCANDATACENTER_H

#include "providerdirectory.h"
#include "providedservicedirectory.h"

class ChocAnDataCenter{
    public:

        ChocAnDataCenter();
        ~ChocAnDataCenter();

    private:
        //MemberDirectory member_directory;
        ProviderDirectory *provider_directory;
        ProvidedServiceDirectory *provided_service_directory;

};

#endif