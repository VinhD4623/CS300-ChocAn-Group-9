#include "terminal.h"
#include "util.h"
#include <iostream>

using namespace std;

void Terminal::login_with_id(){

    this->id_number = read_int_maxdigits("Enter your Provider ID number", 9);
    
}