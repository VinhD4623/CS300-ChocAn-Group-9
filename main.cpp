#include <iostream>
<<<<<<< HEAD
//#include "info.h"
=======
>>>>>>> 35120ba799c6ce9a46d7f05f2c76047d907a7f15
#include "define.h"
#include "providerdirectory.h"

using namespace std;

<<<<<<< HEAD
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
=======
int main(){

    
    return 0;
>>>>>>> 35120ba799c6ce9a46d7f05f2c76047d907a7f15
}
