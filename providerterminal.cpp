#include "providerterminal.h"
#include "info.h"

using namespace std;

void ProviderTerminal::run_terminal(){
    this->login_with_id();

    Member *current_member = new Member();

    this->check_member_validation(current_member);

    this->bill_member(current_member);

    delete(current_member);
}

void ProviderTerminal::check_member_validation(Member *current_member){
    current_member->ID = read_int_maxdigits("Enter the Member ID number", 9);
    //check here if the Id number matches one from the member files


}

void ProviderTerminal::bill_member(Member *current_member){
    current_member->ID = read_int_maxdigits("Enter the Member ID number", 9);
}
