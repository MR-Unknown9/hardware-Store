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
    Component *next;
};

class Inventory
{
private:
    Component *head;

public:
    Inventory() : head(NULL){};
    ~Inventory(){};
    // add your methods here and don't fuck around the rest of the code
    bool isEmpty()
    {
        return (head == NULL);
    }

    int Count()
    {
        int size = 0;

        if (!isEmpty())
        {
            Component *temp = head;
            while (temp->next != NULL)
            {
                size++;
                temp = temp->next;
            }
            size++;
        }
        return size;
    }

    void addComponent(string type, string name, int price)
    {
        Component *newComponent = new Component();
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
        for (int i = 0; i < Count(); i++)
        {
            Component *temp = head, *prev = NULL;
            while (temp->next != NULL)
            {
                if (temp->price < temp->next->price)
                {
                    Component *next = temp->next;
                    temp->next = next->next;
                    next->next = temp;
                    if (prev == NULL)
                        head = next;

                    else
                        prev->next = next;
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
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
         << "5. Exit\n"
         << "*********************************************************\n"
         << "Enter your choice: ";
}
#endif