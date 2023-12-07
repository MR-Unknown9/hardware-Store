// This is a hardware repo to store the parts
// and track the parts and₫the spare

#include <iostream>
#include "Inventory.h"
// INCLUDE the header file, i don't want to kill you 😇 

using namespace std;


int main() {
    Inventory inventory;
    int choice;
    std::string type, name;

    while (true) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter component type: ";
                std::cin >> type;
                std::cout << "Enter component name: ";
                std::cin >> name;
                // inventory.addComponent(type, name);
                break;
            case 2:
                std::cout << "Enter component name to remove: ";
                std::cin >> name;
                // inventory.removeComponent(name);
                break;
            case 3:
                std::cout << "\nCurrent Inventory:\n";
                // inventory.displayInventory();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
