#ifndef PROVIDERTERMINAL_H
#define PROVIDERTERMINAL_H

#include "terminal.h"
#include "info.h"

class ProviderTerminal : public Terminal{
    public:
        void run_terminal();
        void check_member_validation(Member *);
        void bill_member(Member *);

    private:
        
};

#endif