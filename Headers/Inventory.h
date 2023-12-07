#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include<string>

struct Component {
    std::string type;
    std::string name;
    int price;
    Component* next;
};

class Inventory {
    private:
        Component* head;
    public:
        Inventory() : head(NULL) {}
};

// add your methods here and don't fuck around the rest of the code












// don't write any method past this comment 

void displayInventory() {
            Component* temp = head;
            while (temp != NULL) {
                std::cout << "Type: " << temp->type << ", Name: " << temp->name << ", Price: " << temp->price << std::endl;
                temp = temp->next;
            }
        }

void printMenu() {
    std::cout << "\n\n********** Computer Store Inventory Management **********\n";
    std::cout << "1. Add component\n";
    std::cout << "2. Remove component\n";
    std::cout << "3. Display inventory\n";
    std::cout << "4. Exit\n";
    std::cout << "*********************************************************\n";
    std::cout << "Enter your choice: ";
}


#endif
