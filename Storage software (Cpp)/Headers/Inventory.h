#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>

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

    int count()
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

    void countInventory()
    {
        int cpu = 0, gpu = 0, mb = 0, psu = 0, ram = 0;
        Component *temp = head;

        if (isEmpty())
            cout << "There aren't any items to count!"
                 << "\n";

        else
        {
            while (temp != NULL)
            {
                if (temp->type == "cpu")
                    cpu++;

                else if (temp->type == "gpu")
                    gpu++;

                else if (temp->type == "mb")
                    mb++;

                else if (temp->type == "psu")
                    psu++;

                else
                    ram++;

                temp = temp->next;
            }
            cout << "Cpu: " << cpu << "\n";
            cout << "Gpu: " << gpu << "\n";
            cout << "Mb: " << mb << "\n";
            cout << "Psu: " << psu << "\n";
            cout << "ram: " << ram << "\n";
        }
    }

    void addComponent(string type, string name, int price)
    {
        Component *newComponent = new Component();
        newComponent->type = type;
        newComponent->name = name;
        newComponent->price = price;

        newComponent->next = head;
        head = newComponent;
    }

    void deleteComponent(string name)
    {

        Component *current = head, *previous = head;

        if (isEmpty()) // في حالة ان المخزن فاضي
        {
            cout << "Inventory is empty. Cannot remove component.\n";
            return;
        }

        if (current->name == name)
        { // في حالة ان الي هو عايو يمسحة اول حاجة
            head = current->next;
            free(current);
            return;
        }

        while (current != NULL && current->name != name)
        {
            previous = current; // في حالة ان الي عايز يمسحة مش اول حاجة بس المهم يكون موجود اصلا في المخزن
            current = current->next;
        }

        if (current == NULL)
        { // في حالة ان الي عايز يمسحة مش موجود اصلا
            cout << "component not found.\n";
        }

        previous->next = current->next;
        free(current);
        cout << "Component deleted successfully.\n";
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
    void sortInventoryByPrice()
    {
        for (int i = 0; i < count() - 1; i++)
        {
            Component *current = head,
                      *nextNode = head->next,
                      *prev = NULL;

            for (int j = 0; j < count() - i - 1; j++)
            {
                if (current->price > nextNode->price)
                {
                    if (prev == NULL)
                    {
                        head = nextNode;
                    }
                    else
                    {
                        prev->next = nextNode;
                    }

                    current->next = nextNode->next;
                    nextNode->next = current;

                    prev = nextNode;
                    nextNode = current->next;
                }
                else
                {
                    prev = current;
                    current = nextNode;
                    nextNode = nextNode->next;
                }
            }
        }
    }

    void sortInventoryByType()
    {
        for (int i = 0; i < count() - 1; i++)
        {
            Component *current = head,
                      *nextNode = head->next,
                      *prev = NULL;

            for (int j = 0; j < count() - i - 1; j++)
            {
                if (current->type > nextNode->type)
                {
                    if (prev == NULL)
                    {
                        head = nextNode;
                    }
                    else
                    {
                        prev->next = nextNode;
                    }

                    current->next = nextNode->next;
                    nextNode->next = current;

                    prev = nextNode;
                    nextNode = current->next;
                }
                else
                {
                    prev = current;
                    current = nextNode;
                    nextNode = nextNode->next;
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
         << "5. Count inventory\n"
         << "6. Search for a component\n"
         << "0. Exit\n"
         << "*********************************************************\n"
         << "Enter your choice: ";
}
#endif