#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include<string>

using namespace std;

struct Component
{
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

    void display()
    {
        Component *temp = head;
        while (temp != NULL)
        {
            std::cout << "Type: " << temp->type << ", Name: " << temp->name << ", Price: " << temp->price << std::endl;
            temp = temp->next;
        }
    }
};












// don't write any method past this comment 
void printMenu() {
    cout << "\n\n********** Computer Store Inventory Management **********\n";
    cout << "1. Add component\n";
    cout << "2. Remove component\n";
    cout << "3. Display inventory\n";
    cout << "4. Sort inventory\n";
    cout << "5. Exit\n";
    cout << "*********************************************************\n";
    cout << "Enter your choice: ";
}
#endif