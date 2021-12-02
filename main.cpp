#include <iostream>
#include "define.h"
#include "providerdirectory.h"
#include "providerterminal.h"
#include "managerterminal.h"
#include "util.h"

using namespace std;

int login(ProviderTerminal *p_terminal, ManagerTerminal *m_terminal){

   cout << "\n\nEnter 1 to log in as a Provider" << endl << "Enter 2 to log in as a Manager" << endl << "Enter 3 to exit" << endl;
   int login_choice = read_int_wbounds("", 1, 3); 

   if(login_choice == 1){
      p_terminal->provider_login();
   }
   else if(login_choice == 2){
      //create manager terminal object here
      if(m_terminal->manager_login() == 1)
         m_terminal->run_terminal();
      else{
         cout << endl << "Invalid manager ID number has been entered .... returning login menu." << endl;
         return 1;
      }
   }
   else{
      return 0;
   }
   return 1;
}

int main()
{
  
   ProviderTerminal *p_terminal = new ProviderTerminal();
   ManagerTerminal *m_terminal = new ManagerTerminal();

   while(login(p_terminal, m_terminal));
   
   if(p_terminal) delete p_terminal;
   if(m_terminal) delete m_terminal;
   /*
   ProviderDirectory obj;
   obj.addProvider();
   //obj.printList();
   obj.addProvider();
   obj.createReport();
   
   obj.printList();
   
   obj.writeToFile();
   obj.clear();
   obj.loadDirectory();
   obj.printList();
   */
   
   return 0;
}
