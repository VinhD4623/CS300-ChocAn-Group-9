#ifndef PROVIDERTERMINAL_H
#define PROVIDERTERMINAL_H

#include "terminal.h"
#include "info.h"

class ProviderTerminal : public Terminal{
    public:
        void provider_login();
        void check_member_validation();
        int run_terminal();
        void bill_member();
        void create_service_report();
        void print_services();
        int check_service_code(int);
        void display_fee(int);
        void fill_member();

        ProviderTerminal();
        ~ProviderTerminal();

    private:
        Member *current_member;
        Provider *current_provider;
};

#endif