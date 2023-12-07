//This is a program for storing and tracking hardware parts
// start: thu 07/12 --> end: tue 19/12 11 days remaining
// INCLUDE the header file "Headers/Inventory.h", I don't want to kill you 😇 

#include <iostream>
#include "Headers/Inventory.h"

using namespace std;

int main()
{
    Inventory i;
    int choice;
    string type, name;
    bool flag = true;

    while (flag)
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter component type: ";
                cin >> type;
                cout << "Enter component name: ";
                cin >> name;
                // i.addComponent(type, name);
            break;

            case 2:
                cout << "Enter component name to remove: ";
                cin >> name;
                // i.removeComponent(name);
            break;

            case 3:
                cout << "\nCurrent Inventory:\n";
                // i.displayInventory();
            break;

            case 4:
                //i.sortInventory();
                cout << "\nSorted Inventory:\n";
                //i.displayInventory();
            break;

            case 5:
                flag = false;
            break;

            default:
                cout << "Invalid choice\n";
            break;
        }
    }
    return 0;
}