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
    ~Inventory(){};
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

    // I want to kill myself 😒
    void sortInventory()
    {
        int choice = NULL, max = INT_MIN, min = INT_MAX;
        do
        {
            cout << "Enter your filter\n"
                 << "1. By price\n"
                 << "2. By type\n";

            cin >> choice;

            if (choice != 1 && choice != 2)
                cout << "Invalid number.\n";

        } while (choice != 1 && choice != 2);

        if (choice == 1) // sorting by price
        {
            choice = NULL;
            do
            {
                cout << "edit your filter\n"
                     << "1. High to low\n"
                     << "2. Low to high\n";

                cin >> choice;

                if (choice != 1 && choice != 2)
                    cout << "Invalid number.\n";

            } while (choice != 1 && choice != 2);

            if (choice == 1) // High to low
            {

            }
            // else if (choice == 2) // Low to high
            // {

            // }
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