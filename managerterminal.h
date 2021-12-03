#ifndef MANAGERTERMINAL_H
#define MANAGERTERMINAL_H

#include "terminal.h"
#include "providerterminal.h"
#include "info.h"
#include "util.h"
#include <ctime>
#include <string>


class ManagerTerminal: public Terminal
{
    public:
        ManagerTerminal();
        ManagerTerminal(ChocAnDataCenter *);
        ~ManagerTerminal();

        int manager_login();
        void run_terminal();
        void edit_provider_menu();
        void edit_member_menu();

        int addMember();
        int editMember();
        int searchMember();
        int removeMember();
        int printAllMembers();
    
    private:
        string Name = "admin";
        int id = 123456789;

};

#endif