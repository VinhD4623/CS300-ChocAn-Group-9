#include <iostream>
#include "define.h"
#include "providerdirectory.h"
#include "providerterminal.h"
#include "util.h"

using namespace std;

void login(){
   cout << "\n\nEnter 1 to log in as a Provider" << endl << "Enter 2 to log in as a Manager" << endl;
   int login_choice = read_int_wbounds("", 1, 2); 

   if(login_choice == 1){
      ProviderTerminal *p_terminal = new ProviderTerminal();
      p_terminal->run_terminal();
   }
   else{
      //create manager terminal object here
   }
}

int main()
{
   ProviderTerminal *p_terminal = new ProviderTerminal();

   login();

   delete(p_terminal);

   return 0;
}
