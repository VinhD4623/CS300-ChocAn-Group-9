#include "providerterminal.h"
#include "info.h"
#include "util.h"
#include <ctime>
#include <string>

using namespace std;

ProviderTerminal::ProviderTerminal(){
    current_provider = new Provider();
    current_member = new Member();
}

ProviderTerminal::~ProviderTerminal(){
    if(current_provider) delete current_provider;
    if(current_member) delete current_member;
}

void ProviderTerminal::provider_login(){
    //Provider logs in with there ID number
    this->current_provider->ID = read_int_maxdigits("Enter your Provider ID number", 9);
    
    while(this->run_terminal());
}

int ProviderTerminal::run_terminal(){
    
    cout << "\nWhat would you like to do?" << endl;
    cout << "1. Record a service you provided" << endl;
    cout << "2. Quit" << endl;
    int option = read_int_wbounds("", 1, 2); 

    if(option == 1){
        //check that the member/member number is valid or not
        this->check_member_validation();

        //Create a new service that was provided to a member
        this->bill_member();
    } else if(option == 2){
        return 0;
    }

    return 1;
}

//Gets input for terminal fot eh member ID and checks that it matches 
//a member number that already exists with in the member files
void ProviderTerminal::check_member_validation(){
    this->current_member->ID = read_int_maxdigits("Enter the Member ID number", 9);
    //check here if the Id number matches one from the member files


}

//Function that is initiated when a provider has preformed a service and 
//is going to record it
void ProviderTerminal::bill_member(){
    this->current_member->ID = read_int_maxdigits("Enter the Member ID number", 9);

    this->create_service_report();
}

void ProviderTerminal::create_service_report(){
    
    Service *new_service = new Service();

    read_string("Enter the date that the service was preformed (MM-DD-YYYY)\n", new_service->date, 11);

    time_t now = time(0);
    tm *ltm = localtime(&now);
    string temp;
    temp.append(to_string(1+ltm->tm_mon));
    temp.append("-");
    temp.append(to_string(ltm->tm_mday));
    temp.append("-");
    temp.append(to_string(1900+ltm->tm_year));
    temp.append(" ");
    temp.append(to_string(ltm->tm_hour));
    temp.append(":");
    temp.append(to_string(ltm->tm_min));
    temp.append(":");
    temp.append(to_string(ltm->tm_sec));

    new_service->dateTime = temp;
   
    new_service->provider = this->current_provider;
    new_service->member = this->current_member;


    //Display all service and there service codes from the file containing the data and 
    //prompt the provider to enter the corresponding service code to the service they provided
    new_service->service_code = read_int_maxdigits("Enter corresponding service code of the service provided", 6);

    read_string("Enter any additional comments about the service provided (max 100 char)\n", new_service->comments, 100);

    data_center->append(new_service);
    data_center->addService(new_service);   //send new service to be copied to a providers list of services
    data_center->print_provided_list();

    //Data structure for services
    //needs to also be cleaned up


    //Display fee for the service
}