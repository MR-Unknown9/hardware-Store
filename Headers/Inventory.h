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
    Inventory() : head(NULL){};
    // add your methods here and don't fuck around the rest of the code

    bool isEmpty()
    {
        return (head == NULL);
    }

    void addComponent(string type, string name, int price)
    {
               
        Component* newComponent = new Component();
        newComponent->type = type;
        newComponent->name = name;
        newComponent->price = price;

        newComponent->next = head;
        head = newComponent;

        cout << "Component added successfully.\n";
    }

    void displayInventory()
    {
        if (!isEmpty())
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
        else
            cout << "It is empty for now\n";
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