#include <iostream>
#include "define.h"
#include "providerdirectory.h"
#include "providerterminal.h"
#include "util.h"

using namespace std;

int login(ProviderTerminal *p_terminal){

   cout << "\n\nEnter 1 to log in as a Provider" << endl << "Enter 2 to log in as a Manager" << endl << "Enter 3 to exit" << endl;
   int login_choice = read_int_wbounds("", 1, 3); 

   if(login_choice == 1){
      p_terminal->provider_login();
   }
   else if(login_choice == 2){
      //create manager terminal object here
   }
   else{
      return 0;
   }
   return 1;
}

int main()
{
   
   ProviderTerminal *p_terminal = new ProviderTerminal();

   while(login(p_terminal));

   if(p_terminal) delete p_terminal;
   
   /*
   ProviderDirectory obj;
   obj.addProvider();
   obj.printList();
   obj.addProvider();
   obj.printList();
   
   obj.writeToFile();
   obj.clear();
   obj.loadDirectory();
   obj.printList();
   */
   
   return 0;
}
