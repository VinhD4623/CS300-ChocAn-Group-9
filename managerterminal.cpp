#include "managerterminal.h"
using namespace std;

ManagerTerminal::ManagerTerminal(){}

ManagerTerminal::~ManagerTerminal(){}

int ManagerTerminal::manager_login()
{
    int atempt = 0;
    atempt = read_int("Enter manger ID number: ");
    if(id == atempt)
        return 1;
    else
        return 0;
}

void ManagerTerminal::run_terminal()
{
    int cmd = 0;
    do{
        cout << "Manager Terminal Menu\n"
            << "Select one of the following\n"
            << "1.) Provider Directory Menu. (Make changes or view)\n"
            << "2.) Member Directory Menu. (Make changes or view)\n"
            << "3.) Request Provider Report\n\n";
        cmd = read_int("Selection: ");
        switch (cmd)
        {
        case 1: 
            edit_provider_menu();
            break;
        case 2: 
            edit_member_menu();
            break;
        case 3: 
            break;
        default:
            break;
        }
    }while(cmd != 0);
}


void ManagerTerminal::edit_provider_menu()
{
    int cmd = 0;
    do{
        cout << "Make Changes To Provider Directory\n"
            << "Select one of the following\n"
            << "1.) Add a new provider\n"
            << "2.) Edit an existing provider\n"
            << "3.) Search and display a existing provider\n"
            << "4.) Remove an existing provider\n"
            << "5.) Print entire provider directory\n"
            << "6.) Exit \n\n";
        cmd = read_int("Selection: ");

        switch(cmd){
            case 1:
                data_center->addProvider();
                break;
            case 2:
                data_center->editProvider();
                break;
            case 3:
                data_center->searchProvider();
                break;
            case 4:
                data_center->removeProvider();
                break;
            case 5:
                data_center->print_provided_list();
          
            default:
                break;
        }
    }while(cmd != 6);
}

void ManagerTerminal::edit_member_menu()
{

}



int ManagerTerminal::addMember()
{}

int ManagerTerminal::editMember()
{}

int ManagerTerminal::searchMember()
{}

int ManagerTerminal::removeMember()
{}

int ManagerTerminal::printAllMembers()
{}