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
    int price;

    while (true) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter component type (cpu, gpu, mb, psu, ram): ";
                std::cin >> type;
                std::cout << "Enter component name: ";
                std::cin >> name;
                std::cout << "Enter component price: ";
                std::cin >> price;
                inventory.addComponent(type, name, price);
                break;
            case 2:
                std::cout << "Enter component name to remove: ";
                std::cin >> name;
                inventory.removeComponent(name);
                break;
            case 3:
                std::cout << "\nCurrent Inventory:\n";
                inventory.displayInventory();
                break;
            case 4:
                inventory.sortInventory();
                std::cout << "\nSorted Inventory:\n";
                inventory.displayInventory();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
