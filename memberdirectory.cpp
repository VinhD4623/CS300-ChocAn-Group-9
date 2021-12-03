#include "memberdirectory.h"

using namespace std;



/****************************
 * Mnode Struct
*****************************/
mnode::mnode(): next(NULL)
{}

mnode::~mnode()
{
    next = NULL;
}



/*****************************
 * Member Directory Class
******************************/
MemberDirectory::MemberDirectory(): head (NULL)
{}


MemberDirectory::~MemberDirectory()
{
    clear();
    head = NULL;
}



//Creates and adds in a new provider in the system
//Takes in user input to fill in the member's information before inserting
int MemberDirectory::addMember()
{
    mnode * obj = new mnode();
    obj->member.read_member();
    if(!head){
        head = obj;
        head->next = NULL;
        return 1;
    }
    return addMember(head, obj);
}



//Helper function to insert new m3mb34 node in alphabetical order
int MemberDirectory::addMember(mnode *& head, mnode * obj)
{
    if(!head){
        head = obj;
        head->next = NULL;
        return 1;
    }
    if(head->member.return_name() > obj->member.return_name()){
        mnode * hold = head;
        head = obj;
        head->next = hold;
        return 1;
    }
    return addMember(head->next, obj);
}



//Ask user to input a member's name to search and remove from the directory
int MemberDirectory::removeMember()
{
    if(!head) return 0;

    char name[30];
    read_string("Name of member to be removed: ", name, 30);

    return removeMember(head, name);
}



//Helper function to search through the list for a matching member name
int MemberDirectory::removeMember(mnode *& head, char * name)
{
    if(!head) return 0;

    if(head->member.compare(name)){
        mnode * temp = head; 
        head = head->next;
        delete temp;
        temp = NULL;
        return 1;
    }
    return removeMember(head->next, name);
}



//Search to display a specific member
int MemberDirectory::searchMember()
{
    if(!head) return 0;
    char searchname[64];
    read_string("Name of member to search: ", searchname, 64);
    string name = searchname;
    return searchMember(head, name);
}


//Helper to traverse the list to find a member by name
int MemberDirectory::searchMember(mnode * head, string name)
{
    if(!head) return 0;
    if(head->member.compare(name) == 0){
        head->member.display();
        return 1;
    }
    return searchMember(head->next, name);
}



//Clears the entire directory
int MemberDirectory::clear()
{
    if(!head) return 0;
    return clear(head);
}


//Helper that traverse and clear the entire directory
int MemberDirectory::clear(mnode *& head)
{
    if(!head) return 0;
    mnode * hold = head;
    head = head->next;
    hold->next = NULL;
    delete hold;
    return 1 + clear(head);

}


//Search a member to edit their information
int MemberDirectory::editMember()
{
    if(!head) return 0; //Empty provider list
    char name[32];
    read_string("Name of member to edit: ", name, 32);
    
    int found = editMember(head, name);
    if(found == 0){
        cout << "\nNo matching name in member directory\n";
        return 0;
    }
    else return 1;
}



//Helper to traverse through the directory to find the matching member by name
int MemberDirectory::editMember(mnode * head, char * name)
{
    if(!head) return 0;
    if(head->member.compare(name) == 1){
        head->member.edit_member();
        return 1;
    }
    return editMember(head->next, name);
}


//Prints the entire directory
int MemberDirectory::printList()
{
    if(!head) return 0;
    return printList(head);
}


//Helper to traverse and print the entire directory
int MemberDirectory::printList(mnode * head)
{
    if(!head) return 1;
    cout << endl;
    head->member.display();
    return printList(head->next);
}



//Validate that member exists and account is valid
int MemberDirectory::validate(const int id)
{
    if(!head) return 0;
    return validate(head, id);
}



//Helper to traverse directory
int MemberDirectory::validate(mnode * head, int id)
{
    if(!head) return 0;
    if((head->member.ID == id) && head->member.Status)
        return 1;
    return validate(head->next, id);
}


/****************************************************
* File read and write
*****************************************************/

//Saves the member directory into file
int MemberDirectory::writeToFile()
{
    string filename;
    string path;
    filename = "memberDirectory.txt";
    path = "memberList/";
    path.append(filename);
    fstream outFile;

    outFile.open(path, ios::out);
    if(outFile.is_open()){
        while(head){
            outFile << head->member.Name << "\n"
                    << head->member.ID << "\n"
                    << head->member.address.Street << "\n"
                    << head->member.address.City << "\n"
                    << head->member.address.State << "\n"
                    << head->member.address.ZIP << "\n";
	    if(head->member.Status){
	        outFile << "1\n.\n";
	    }
	    else{
                outFile << "0\n.\n";
            }

            head = head->next;
        }
        outFile.close();
    }
    return 1;
}


//Loads the directory from file to recreate the directory
int MemberDirectory::loadDirectory()
{
    string filename;
    filename = "memberList/memberDirectory.txt";
    
    ifstream inFile;
    inFile.open(filename);
    if(!inFile){
        inFile.clear();
        cerr << endl << "Fail to open " << filename << endl << endl;
		return 0;
    }

    string name;
    int id;
    Address address;
    string street;
    string city;
    string state;
    int zip;
    bool status;


    while(!inFile.eof()){
        getline(inFile, name);
    
        inFile >> id;
        inFile.get();
        getline(inFile, street);
        getline(inFile, city);
        getline(inFile, state);
        inFile >> zip;
	inFile >> status;
        inFile.ignore(100, '.');
        inFile.get();
        
        mnode * obj = new mnode();
        address.copy_address(street, city, state, zip);
        obj->member.copy_member(name, id, address, status);

        addMember(head, obj);
    }
    
    inFile.close();
    return 0;
}


//Creates member report 
int MemberDirectory::createReport()
{
    if(!head) return 0;
    return createReport(head);
}


//Creates a member report for each member and saves to file 
int MemberDirectory::createReport(mnode * head)
{
    if(!head) return 0;
    string path;
    string filename;
    string id;

    path = "memberReports/";
    filename = "member_Report";
    id = to_string(head->member.ID);

    filename.append(id);
    filename.append(".txt");
    path.append(filename);

    fstream outFile;
    outFile.open(path, ios::out);

    if(outFile.is_open()){
        outFile << "Name: " << head->member.Name << "\n"
                << "ID nunber: " << head->member.ID << "\n"
                << "Street: " << head->member.address.Street << "\n"
                << "City: " << head->member.address.City << "\n"
                << "State: " << head->member.address.State << "\n"
                << "Zip: " << head->member.address.ZIP << "\n";
        if(head->member.Status){
            outFile << "Status: Valid" << "\n";
        }
	else{
            outFile << "Status: Expired" << "\n";
        } 
    }
    //head->serviceList.writeToFile(path);
    outFile.close();

    return 1 + createReport(head->next);
}

