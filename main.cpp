//This is a program for storing and tracking hardware parts
// start: thu 07/12 --> end: tue 19/12 11 days remaining
// INCLUDE the header file => "Headers/Inventory.h", I don't want to kill you 😇 

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <windows.h>
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
            do
            {
                cout << "Enter component type (cpu, gpu, ram, mb, psu): ";
                cin >> type;

                transform(type.begin(), type.end(), type.begin(), ::tolower);

                if (type != "cpu" && type != "gpu" && type != "psu" && type != "ram" && type != "mb")
                    cout << "Invalid choice for component type. Please enter cpu, gpu, psu, ram, or mb.\n";

            } while (type != "cpu" && type != "gpu" && type != "psu" && type != "ram" && type != "mb");

            cout << "Enter component name: ";
            getline(cin >> ws, name);

            cout << "Enter component price: ";
            int price;

            if (!(cin >> price))
            {
                cout << "Invalid price. Please enter an integer.\n";
                cin.clear();

                cin.ignore(10000, '\n');
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
            cout << "Sorted Inventory:\n";
            // i.sortInventory();
            break;

        case 5:
            flag = false;
            break;

        default:
            cout << "Invalid choice\n";
            break;
        }
        // don't touch it
        Sleep(250);
    }
    return 0;
}