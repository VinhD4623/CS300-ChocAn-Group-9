#include "providerdirectory.h"

using namespace std;



/****************************
 * Pnode Struct
*****************************/
pnode::pnode(): next(NULL)
{}

pnode::~pnode()
{
    next = NULL;
}



/*****************************
 * Provider Directory Class
******************************/
ProviderDirectory::ProviderDirectory(): head (NULL)
{}


ProviderDirectory::~ProviderDirectory()
{
    clear();
    head = NULL;
}


//Creates and adds in a new provider in the syster
//Takes in user input to fill in the provider's information before inserting
int ProviderDirectory::addProvider()
{
    pnode * obj = new pnode();
    obj->provider.read_provider();
    if(!head){
        head = obj;
        head->next = NULL;
        return 1;
    }
    return addProvider(head, obj);
}


//Helper function to insert new provider node in alphabetical order
int ProviderDirectory::addProvider(pnode *& head, pnode * obj)
{
    if(!head){
        head = obj;
        head->next = NULL;
        return 1;
    }
    //if(strcasecmp(head->provider.return_name(), obj->provider.return_name())){  
    if(head->provider.return_name() > obj->provider.return_name()){
        pnode * hold = head;
        head = obj;
        head->next = hold;
        return 1;
    }
    return addProvider(head->next, obj);
}



//Ask user to input a provider's name to search and remove from the directory
int ProviderDirectory::removeProvider()
{
    if(!head) return 0;

    char name[32];
    read_string("Name of provider to be removed: ", name, 32);

    return removeProvider(head, name);
}

//Helper function to search through the list for a matching provider name
int ProviderDirectory::removeProvider(pnode *& head, char * name)
{
    if(!head) return 0;

    if(head->provider.compare(name)){
        pnode * temp = head; 
        head = head->next;
        delete temp;
        temp = NULL;
        return 1;
    }
    return removeProvider(head->next, name);

}

//Search to display a specific provider
int ProviderDirectory::searchProvider()
{
    if(!head) return 0;
    char searchname[64];
    read_string("Name of provider to search: ", searchname, 64);
    string name = searchname;
    return searchProvider(head, name);
}


//Helper to traverse the list to find a provider by name
int ProviderDirectory::searchProvider(pnode * head, string name)
{
    if(!head) return 0;
    if(head->provider.compare(name) == 0){
        head->provider.display();
        return 1;
    }
    return searchProvider(head->next, name);
}


//Clears the entire directory
int ProviderDirectory::clear()
{
    if(!head) return 0;
    return clear(head);
}


//Helper that traverse and clears the entire directory
int ProviderDirectory::clear(pnode *& head)
{
    if(!head) return 0;
    pnode * hold = head;
    head = head->next;
    hold->next = NULL;
    delete hold;
    return 1 + clear(head);

}


//Search a provider to edit their information
int ProviderDirectory::editProvider()
{
    if(!head) return 0; //Empty provider list
    char name[32];
    read_string("Name of provider to edit: ", name, 32);
    
    int found = editProvider(head, name);
    if(found == 0){
        cout << "\nNo matching name in provider directory\n";
        return 0;
    }
    else return 1;
}




//Helper to travers through the directory to find the matching provider by name
int ProviderDirectory::editProvider(pnode * head, char * name)
{
    if(!head) return 0;
    if(head->provider.compare(name) == 1){
     /* int cmd;
        do{
        cout << "What do you want to edit?\n\n";
        cout << "1.) Personal information\n"
            << "2.) Add service\n"
            << "3.) Remove service\n"
            << "4.) Exit\n\n";
            cmd = read_int("Selection: ");

            switch(cmd){
                case 1:
                    head->provider.edit_provider();
                    break;
                case 2:
                    head->addService()
                case 3:

                case 4:
            }
        }while(cmd != 4)
        */ 
        head->provider.edit_provider();
        return 1;
    }
    return editProvider(head->next, name);
}


//Prints the entire directory
int ProviderDirectory::printList()
{
    if(!head) return 0;
    return printList(head);
}


//Helper to traverse and print the entire directory
int ProviderDirectory::printList(pnode * head)
{
    if(!head) return 1;
    cout << endl;
    head->provider.display();
    return printList(head->next);
}


int ProviderDirectory::validate(const int id)
{
    if(!head) return 0;
    return validate(head, id);
}

int ProviderDirectory::validate(pnode * head, int id)
{
    if(!head) return 0;
    if(head->provider.ID == id)
        return 1;
    return validate(head->next, id);
}


/****************************************************
* File read and write
*****************************************************/

//Saves the provider directory into file
int ProviderDirectory::writeToFile()
{
    string filename;
    string path;
    filename = "providerDirectory.txt";
    path = "providerList/";
    path.append(filename);
    fstream outFile;

    outFile.open(path, ios::out);
    if(outFile.is_open()){
        while(head){
            outFile << head->provider.Name << "\n"
                    << head->provider.ID << "\n"
                    << head->provider.TotalMember << "\n"
                    << head->provider.TotalFee << "\n"
                    << head->provider.address.Street << "\n"
                    << head->provider.address.City << "\n"
                    << head->provider.address.State << "\n"
                    << head->provider.address.ZIP << "\n"
                    << ".\n";
            head = head->next;
        }
        outFile.close();
    }

    return 1;
}


//Loads the directory from file to recreate the directory
int ProviderDirectory::loadDirectory()
{
    string filename;
    filename = "providerList/providerDirectory.txt";
    
    ifstream inFile;
    inFile.open(filename);
    if(!inFile){
        inFile.clear();
        cerr << endl << "Fail to open " << filename << endl << endl;
		return 0;
    }

    string name;
    int id;
    Address address;
    int totalMem;
    double totalFee;
    string street;
    string city;
    string state;
    int zip;


    while(!inFile.eof()){
        getline(inFile, name);
    
        inFile >> id;
        inFile >> totalMem;
        inFile >> totalFee;
        inFile.get();
        getline(inFile, street);
        getline(inFile, city);
        getline(inFile, state);
        inFile >> zip;
        inFile.ignore(100, '.');
        inFile.get();
        
        pnode * obj = new pnode();
        address.copy_address(street, city, state, zip);
        obj->provider.copy_provider(name, id, address, totalMem, totalFee);

        addProvider(head, obj);
    }
    
    inFile.close();
    return 0;
}


//Creates provider report 
int ProviderDirectory::createReport()
{
    if(!head) return 0;
    return createReport(head);
}


//Creates a provider report for each provider and saves to file 
int ProviderDirectory::createReport(pnode * head)
{
    if(!head) return 0;
    string path;
    string filename;
    string id;

    path = "providerReports/";
    filename = "provider_Report";
    id = to_string(head->provider.ID);

    filename.append(id);
    filename.append(".txt");
    path.append(filename);

    fstream outFile;
    outFile.open(path, ios::out);

    if(outFile.is_open()){
        outFile << "Name: " << head->provider.Name << "\n"
                << "ID nunber: " << head->provider.ID << "\n"
                << "Street: " << head->provider.address.Street << "\n"
                << "City: " << head->provider.address.City << "\n"
                << "State: " << head->provider.address.State << "\n"
                << "Zip: " << head->provider.address.ZIP << "\n"
                << "Total number of consultations with members:" << head->provider.TotalMember << "\n"
                << "Total fee for the week:" << head->provider.TotalFee << "\n";

    }
    outFile.close();

    return 1 + createReport(head->next);
}



/******************************
 *  Provider List of Services
*******************************/


int ProviderDirectory::addService(Service *& new_service)
{
    if(!head) return 0;
    /*
    char searchname[64];
    read_string("Name of provider to add services: ", searchname, 64);
    string name = searchname;
    */

    return addService(head, new_service->provider->Name, new_service);
}

int ProviderDirectory::addService(pnode * head, string name, Service *& new_service)
{
    if(!head) return 0;

    if(head->provider.Name.compare(name) == 0){
        Service * obj = new Service();
        obj = new_service;
        head->serviceList.append(obj);
        /*
        Service *new_service = new Service();
        int serviceCode = read_int_maxdigits("Service code: ", 6);
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

        head->serviceList.append(new_service);
        */
        return 1;
    }

    return addService(head->next, name, new_service);
}