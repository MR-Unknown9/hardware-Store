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
    // int choice;
    // string type, name;
    // bool flag = true;

    // while (flag)
    // {
    //     printMenu();
    //     cin >> choice;

    //     switch (choice)
    //     {
    //     case 1:
    //         do
    //         {
    //             cout << "\nEnter component type (cpu, gpu, psu, mb, psu): ";
    //             cin >> type;

    //             transform(type.begin(), type.end(), type.begin(), ::tolower);

    //             if (!checkType(type))
    //                 cout << "Invalid component type.\n";

    //         } while (!checkType(type));

    //         cout << "\nEnter component name: ";
    //         getline(cin >> ws, name);

    //         cout << "\nEnter component price: ";
    //         int price;

    //         if (!(cin >> price))
    //         {
    //             cout << "Invalid price. Please enter an integer.\n";
    //             cin.clear();

    //             cin.ignore(MAX_IGNORE, '\n');
    //             break;
    //         }

    //         i.addComponent(type, name, price);
    //         cout << "Component added successfully.\n";

    //         break;

    //     case 2:
    //         cout << "\nEnter component name to remove: ";
    //         // i.deleteComponent();
    //         cin >> name;

    //         break;

    //     case 3:
    //         cout << "\nCurrent Inventory:\n";
    //         i.displayInventory();
    //         break;

    //     case 4:
    //         do
    //         {
    //             cout << "\nEnter your filter\n"
    //                  << "1. By price\n"
    //                  << "2. By type\n";

    //             cin >> choice;

    //             if (choice != 1 && choice != 2)
    //                 cout << "Invalid number.\n";

    //         } while (choice != 1 && choice != 2);

    //         if (choice == 1) // sorting by price
    //             i.sortInventoryByPrice();

    //         else // sorting by type
    //             i.sortInventoryByType();

    //         cout << "\nsorted inventory: \n";
    //         i.displayInventory();
    //             break;

    //         case 5:
    //             i.countInventory();
    //             break;

    //         case 6:
    //             flag = false;
    //             break;

    //         default:
    //             cout << "Invalid choice\n";
    //             break;
            
    //         Sleep(250);
    //     }   
    // }
    i.addComponent("cpu", "asdf", 1000);
    i.addComponent("cpu", "asdf", 100);
    i.addComponent("cpu", "asdf", 1400);
    i.addComponent("gpu", "asdf", 2000);
    i.addComponent("gpu", "asdf", 200);
    i.addComponent("psu", "asdf", 8000);
    i.addComponent("psu", "asdf", 8000);
    i.addComponent("psu", "asdf", 8050);
    i.addComponent("ram", "asdf", 5000);
    i.addComponent("ram", "asdf", 6000);

    cout << i.count() << "\n";
    i.countInventory();
    // i.sortInventoryByPrice();

    // cout << i.count() << "\n";
    // i.sortInventoryByType();

    // cout << i.count();

    return 0;
}

bool checkType(string &type)
{
    if (type != "cpu" && type != "gpu" && type != "psu" && type != "ram" && type != "mb")
        return false;

    else
        return true;
}