// This is a program for storing and tracking hardware parts
//  start: thu 07/12 --> end: tue 19/12
//   6 days remaining
//  INCLUDE the header file => "Headers/Inventory.h", I don't want to kill you 😇

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>
#include <windows.h>
#include "Headers/Inventory.h"

const int MAX_IGNORE = 10000;

enum MenuChoice
{
    EXIT,
    ADD_COMPONENT,
    REMOVE_COMPONENT,
    DISPLAY_INVENTORY,
    SORT_INVENTORY,
    COUNT_INVENTORY,
    SEARCH_COMPONENT
};

bool checkType(const std::string &type);

int main()
{
    Inventory i;
    int choice;
    std::string type, name;
    bool flag = true;

    while (flag)
    {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case EXIT:
            flag = false;
            break;

        case ADD_COMPONENT:
            do
            {
                std::cout << "\nEnter component type (cpu, gpu, psu, mb, psu): ";
                std::cin >> type;

                std::transform(type.begin(), type.end(), type.begin(), ::tolower);

                if (!checkType(type))
                    std::cout << "Invalid component type.\n";

            } while (!checkType(type));

            std::cout << "\nEnter component name: ";
            std::getline(std::cin >> std::ws, name);

            std::cout << "\nEnter component price: ";
            int price;

            if (!(std::cin >> price))
            {
                std::cout << "Invalid price. Please enter an integer.\n";
                std::cin.clear();

                std::cin.ignore(MAX_IGNORE, '\n');
                break;
            }

            i.addComponent(type, name, price);
            std::cout << "Component added successfully.\n";

            break;

        case REMOVE_COMPONENT:
            std::cout << "\nEnter component name to remove: ";
            std::cin >> name;
            i.deleteComponent(name);

            break;

        case DISPLAY_INVENTORY:
            std::cout << "\nCurrent Inventory:\n";
            i.displayInventory();
            break;

        case SORT_INVENTORY:
            do
            {
                std::cout << "\nEnter your filter\n"
                          << "1. By price\n"
                          << "2. By type\n";

                std::cin >> choice;

                if (choice != 1 && choice != 2)
                    std::cout << "Invalid number.\n";

            } while (choice != 1 && choice != 2);

            if (choice == 1) // sorting by price
                i.sortInventoryByPrice();

            else // sorting by type
                i.sortInventoryByType();

            std::cout << "\nsorted inventory: \n";
            i.displayInventory();

            break;

        case COUNT_INVENTORY:
            i.countInventory();
            break;

        case SEARCH_COMPONENT:
            std::cout << "Enter Component name to search";
            break;

        default:
            std::cout << "Invalid choice\n";
            break;

        }
        Sleep(250);
    }
    return 0;
}

bool checkType(const std::string &type)
{
    std::set<std::string> valid_types = {"cpu", "gpu", "psu", "ram", "mb"};
    return valid_types.count(type);
}