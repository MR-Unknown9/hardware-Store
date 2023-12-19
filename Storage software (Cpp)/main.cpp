// This is a program for storing and tracking hardware parts
//  start: thu 07/12 --> end: tue 19/12
//   6 days remaining
//  INCLUDE the header file => "Headers/Inventory.h", I don't want to kill you 😇

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

#include "Headers/Inventory.h"

using namespace std;

void save(const string &type, const string &name, const int &price)
{
    ofstream file("Save.txt", ios::ate | ios::app);
    if (file.is_open())
    {
        file << "Type: " << type << " Name: " << name << " Price: " << price << endl;
        file.close();
        cout << "File saved successfully.\n";
    }
    else
        cout << "Unable to open file for saving.";
}

int main()
{
    Inventory i;
    string type, name, freshName;
    Component *foundByName, *foundByType;
    int choice, searchChoice, freshPrice, exitChoice, price;
    bool flag = true, foundInRange;

    while (flag)
    {
    start:
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 0:
            do
            {
                cout << "1. Save and exit.\n"
                     << "2.Exit.\n"
                     << "3. Continue.\n"
                     << " Enter your choice: ";
                cin >> exitChoice;

                if (exitChoice == 1)
                {
                    if (i.isEmpty())
                    {
                        cout << "Nothing to save.\n"
                             << "Exiting...";
                        flag = false;
                    }
                    else
                    {
                        cout << "Saving...\n";
                        save(type, name, price);
                        cout << "Exiting...";
                        flag = false;
                    }
                }
                else if (exitChoice == 2)
                {
                    cout << "Exiting...";
                    flag = false;
                }
                else if (exitChoice == 3)
                    goto start;

                else
                    cout << "Unvalid input";

            } while (exitChoice != 1 && exitChoice != 2 && exitChoice != 3);
            break;

        case 1:
            do
            {
                cout << "Enter component type (cpu, gpu, ram, mb, psu): ";
                cin >> type;
                transform(type.begin(), type.end(), type.begin(), ::tolower);

                if (type != "cpu" && type != "gpu" && type != "psu" && type != "ram" && type != "mb")
                    cout << "\nInvalid choice for component type. Please enter (cpu, gpu, psu, ram, or mb).\n";

            } while (type != "cpu" && type != "gpu" && type != "psu" && type != "ram" && type != "mb");

            cout << "Enter component name: ";
            getline(cin >> ws, name);

            do
            {
                cout << "Enter component price: ";
                cin >> price;

                if (cin.fail())
                {
                    cout << "Invalid price. Please enter an integer.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            } while (cin.fail());

            i.addComponent(type, name, price);
            break;

        case 2:
            cout << "\nEnter component name to remove: ";
            cin >> name;

            i.deleteComponent(name);

            break;

        case 3:
            cout << "\nCurrent Inventory:\n";
            i.displayInventory();
            break;

        case 4:
            do
            {
                cout << "\nChoose filter\n"
                     << "1. By price\n"
                     << "2. By type\n";

                cin >> choice;

                if (choice != 1 && choice != 2)
                    cout << "Invalid number.\n";

            } while (choice != 1 && choice != 2);

            if (choice == 1) // sorting by price
                i.sortInventoryByPrice();

            else // sorting by type
                i.sortInventoryByType();

            cout << "\nsorted inventory: \n";
            i.displayInventory();

            break;

        case 5:
            i.countInventory();
            break;

        case 6:
            printSearchMenu();
            cin >> searchChoice;

            switch (searchChoice)
            {
            case 1:
                cout << "Enter component name to search: ";
                cin >> name;

                foundByName = i.searchByName(name);
                if (foundByName != NULL)
                    cout << "Found component - Type: " << foundByName->type << ", Name: " << foundByName->name << ", Price: " << foundByName->price << "\n";

                else
                    cout << "No component found with the given name.\n";

                break;

            case 2:
                cout << "Enter component type to search: ";
                cin >> type;

                foundByType = i.searchByType(type);
                if (foundByType != NULL)
                    cout << "Found component - Type: " << foundByType->type << ", Name: " << foundByType->name << ", Price: " << foundByType->price << "\n";

                break;

            case 3:
                int minPrice, maxPrice;
                cout << "Enter minimum price: ";
                cin >> minPrice;

                cout << "Enter maximum price: ";
                cin >> maxPrice;

                foundInRange = i.searchByPriceRange(minPrice, maxPrice);
                if (!foundInRange)
                    cout << "No component found in the given price range.\n";

                break;

            case 4:
                // Go back to main menu
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
            }
            break;

        case 7:
            cout << "Which component do you want to tweak? :-  ";
            cin >> name;

            foundByName = i.searchByName(name);
            if (foundByName == NULL)
            {
                cout << "Oops! Couldn't find a component with that name.\n";
                break;
            }
            cout << "What's the new type? ";
            cin >> type;

            cout << "And the new name? ";
            cin >> freshName;

            cout << "Finally, the new price? ";
            cin >> freshPrice;

            i.tweakComponent(name, type, freshName, freshPrice);
            break;

        case 8:
            cout << "saving...\n";
            save(type, name, price);
            break;

        default:
            cout << "Invalid choice. Please enter a number between 0 and 6.\n";
            break;
        }
    }
    return 0;
}