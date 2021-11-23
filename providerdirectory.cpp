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


int ProviderDirectory::clear()
{
    if(!head) return 0;
    return clear(head);
}

int ProviderDirectory::clear(pnode *& head)
{
    if(!head) return 0;
    pnode * hold = head;
    head = head->next;
    hold->next = NULL;
    delete hold;
    return 1 + clear(head);

}

int ProviderDirectory::editProvider()
{

    return 0;
}





int ProviderDirectory::printList()
{
    if(!head) return 0;
    return printList(head);
}
        
int ProviderDirectory::printList(pnode * head)
{
    if(!head) return 1;
    cout << endl;
    head->provider.display();
    return printList(head->next);
}

int ProviderDirectory::writeToFile()
{
    char filename[101];
    fstream outFile;

    read_string("Name of file: ", filename, 101);
    outFile.open(filename, ios::out);
    if(outFile.is_open()){
        while(head){
            outFile << head->provider.Name << ";"
                    << head->provider.ID << ";"
                    << head->provider.TotalMember << ";"
                    << head->provider.TotalFee << "\n";

            head = head->next;
        }
        outFile.close();
    }

    return 0;
}