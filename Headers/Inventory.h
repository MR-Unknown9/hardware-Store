#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

struct Component
{
public:
    string type, name;
    int price;
    Component* next;
};

class Inventory
{
private:
    Component* head;

public:
    Inventory()
    {
        head = NULL;
    };
    // add your methods here and don't fuck around the rest of the code

    bool isEmpty()
    {
        return (head == NULL);
    }

    void displayInventory()
    {
        Component *temp = head;
        while (temp != NULL)
        {
            cout << "Type: " << temp->type 
                 << ", Name: " << temp->name 
                 << ", Price: " << temp->price << "\n";
            temp = temp->next;
        }
    }
};
// don't write any method past this comment 
void printMenu()
{
    cout << "\n********** Computer Store Inventory Management **********\n"
         << "1. Add component\n"
         << "2. Remove component\n"
         << "3. Display inventory\n"
         << "4. Sort inventory\n"
         << "5. Exit\n" << "*********************************************************\n" 
         << "Enter your choice: ";
}
#endif