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





/****************************************************
* File read and write
*****************************************************/

//Saves the provider directory into file
int ProviderDirectory::writeToFile()
{
    string filename;
    filename = "providerDirectory.txt";
    fstream outFile;

    //read_string("Name of file: ", filename, 101);
    outFile.open(filename, ios::out);
    if(outFile.is_open()){
        while(head){
            outFile << head->provider.Name << "\n"
                    << head->provider.ID << "\n"
                    << head->provider.TotalMember << "\n"
                    << head->provider.TotalFee << "\n"
                    << ".\n";
            /*
            if(head->serviceList.head){
                outFile << head->serviceList.head->serviceservice_code << "\n"
                        << head->serviceList.head->service.datetime << "\n"
                        << head->serviceList.head->service.comments << "\n"
                        << "..\n";
            }
            */
            head = head->next;
        }
        outFile.close();
    }

    return 0;
}


//Reads in from file 
int ProviderDirectory::loadDirectory()
{
    string filename;
    filename = "providerDirectory.txt";



}



