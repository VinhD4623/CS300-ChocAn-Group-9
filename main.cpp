#include <iostream>
//#include "info.h"
#include "define.h"
#include "providerdirectory.h"

using namespace std;

int main()
{

    /*
    Address obj;
    obj.read_address();
    obj.display();
    obj.edit_address();
    obj.display();
    
    Member obj1;
    obj1.read_member();
    obj1.display();
    obj1.edit_member();
    obj1.display();

    
    Provider obj2;
    obj2.read_provider();
    obj2.display();
    obj2.edit_provider();
    obj2.display();
    */
   ProviderDirectory list;
   list.addProvider();
   list.addProvider();
   list.addProvider();
   cout << endl << endl;
   list.printList();
   list.removeProvider();
   list.printList();
   list.writeToFile();
    
   return 0;
}
