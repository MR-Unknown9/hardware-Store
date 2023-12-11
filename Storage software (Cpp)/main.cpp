// This is a program for storing and tracking hardware parts
//  start: thu 07/12 --> end: tue 19/12
//   6 days remaining
//  INCLUDE the header file => "Headers/Inventory.h", I don't want to kill you 😇

#include <iostream>
#include <string>

#include "Headers/Inventory.h"

using namespace std;

int main()
{
    Inventory i;
    int choice,searchChoice;
    string type, name;
    bool flag = true;
    Component* foundByName;
    Component* foundByType;
    bool foundInRange;
    

    while (flag)
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 0:
            flag = false;
            break;

        case 1:
            do {
                cout << "Enter component type (cpu, gpu, ram, mb, psu): ";
                cin >> type;
                if (type != "cpu" && type != "gpu" && type != "psu" && type != "ram" && type != "mb") {
                    cout << "\nInvalid choice for component type. Please enter cpu, gpu, psu, ram, or mb.\n";
                }
            } while (type != "cpu" && type != "gpu" && type != "psu" && type != "ram" && type != "mb");
            
            cout << "Enter component name: ";
            cin >> name;
            int price;
            do {
                cout << "Enter component price: ";
                cin >> price;
                if (cin.fail()) {
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
                if (foundByName != NULL) {
                    cout << "Found component - Type: " << foundByName->type << ", Name: " << foundByName->name << ", Price: " << foundByName->price << "\n";
                } else {
                    cout << "No component found with the given name.\n";
                }
                break;

            case 2:
                cout << "Enter component type to search: ";
                cin >> type;
                foundByType = i.searchByType(type);
                if (foundByType != NULL) {
                    cout << "Found component - Type: " << foundByType->type << ", Name: " << foundByType->name << ", Price: " << foundByType->price << "\n";
                }
                break;

            case 3:
                int minPrice, maxPrice;
                cout << "Enter minimum price: ";
                cin >> minPrice;
                cout << "Enter maximum price: ";
                cin >> maxPrice;
                foundInRange = i.searchByPriceRange(minPrice, maxPrice); 
                if (!foundInRange) {
                    cout << "No component found in the given price range.\n";
                }
                break;

            case 4:
                // Go back to main menu
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
            }
            break;
            
        default:
            cout << "Invalid choice. Please enter a number between 0 and 6.\n";
            break;
        }        
    }
    return 0;
}
