#include "LinkedList.h"
#include <string>
#include <iostream>
#include <limits>

using namespace std;

void printMenu(){
    cout << "------MENU------" << endl;
    cout << "1: insert\n2: print list\n3: Quit" << endl;
}

int main(){
    cout << "EXECUTING...." << endl;
    string choice = "";
    LinkedList list;

    while(choice != "3"){
        try{
            printMenu();
            cin >> choice;
            if(choice < "1" || choice > "3"){
                throw invalid_argument("");
            }
        } catch(...){
            cout << "ERROR: Exiting program. GoodBye." << endl;
            break;
        }

        if(choice == "1"){
            int toAdd;
            cout << "Enter a value to add: \n";
            try{
                cin >> toAdd;
            }catch(...){
                cout << "ERROR: Exiting program. GoodBye." << endl;
                break;
            }
            list.insert(toAdd);
        }else if(choice == "2"){
            list.print();
        }else{
            cout << "Exiting program. Goodbye." << endl;
            break;
        }
    }
    return -1;
}


// for single unit testing
// int main(){
//     LinkedList list;
//     list.insert(1);
//     list.insert(2);
//     list.insert(4);
//     list.insert(3);

//     LinkedList list2(list);

//     cout << "list 1:" << endl;
//     list.print();
//     cout << "================\nList 2:" << endl;
//     list2.print();
//     return -1;
// }
