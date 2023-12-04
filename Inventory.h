#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string info;
    Node *next;
};

class Inventory
{
private:
    Node *head;
public:
    Inventory()
    {
        head = NULL;
    };

    bool isEmpty()
    {
        return (head == NULL);
    }

    void print()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                cout << temp->info << "  ";
                temp->next;
            }
        }
        else
            cout << "The Inventory Is Empty.";
    }

};
#endif