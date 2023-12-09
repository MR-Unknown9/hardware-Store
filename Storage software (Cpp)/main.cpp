// This is a program for storing and tracking hardware parts
//  start: thu 07/12 --> end: tue 19/12
//   10 days remaining
//  INCLUDE the header file => "Headers/Inventory.h", I don't want to kill you 😇

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <windows.h>
#include "Headers/Inventory.h"

using namespace std;

const int MAX_IGNORE = 10000;
bool checkType(string &type);

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
            do
            {
                cout << "Enter component type (cpu, gpu, psu, mb, psu): ";
                cin >> type;

                transform(type.begin(), type.end(), type.begin(), ::tolower);

                if (!checkType(type))
                    cout << "Invalid component type.\n";

            } while (!checkType(type));

            cout << "Enter component name: ";
            getline(cin >> ws, name);

            cout << "Enter component price: ";
            int price;

            if (!(cin >> price))
            {
                cout << "Invalid price. Please enter an integer.\n";
                cin.clear();

                cin.ignore(MAX_IGNORE, '\n');
                break;
            }

            i.addComponent(type, name, price);
            break;

        case 2:
            cout << "Enter component name to remove: ";
            // i.deleteComponent();
            cin >> name;

            break;

        case 3:
            cout << "Current Inventory:\n";
            i.displayInventory();
            break;

        case 4:
            do
            {
                cout << "Enter your filter\n"
                     << "1. By price\n"
                     << "2. By type\n";

                cin >> choice;

                if (choice != 1 && choice != 2)
                    cout << "Invalid number.\n";

            } while (choice != 1 && choice != 2);

            if (choice == 1) // sorting by price
                i.sortInventory();

            else
                // i.sortInventory();
                cout << "sorted inventory: \n";
                i.displayInventory();
                break;

            case 5:
                flag = false;
                break;

            default:
                cout << "Invalid choice\n";
                break;
            
            Sleep(250);
        }   
    }
    return 0;
}

bool checkType(string &type)
{
    if (type != "cpu" && type != "gpu" && type != "psu" && type != "ram" && type != "mb")
        return false;

    else
        return true;
}