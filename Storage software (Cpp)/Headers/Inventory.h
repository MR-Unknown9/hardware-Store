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
    // void sortInventoryByPrice()
    // {
    //     for (int i = 1; i <= count(); i++)
    //     {
    //         Component *temp = head, *prev = NULL;
    //         while (temp->next != NULL)
    //         {
    //             if (temp->price < temp->next->price)
    //             {
    //                 Component *next = temp->next;
    //                 temp->next = next->next;
    //                 next->next = temp;
    //                 if (prev == NULL)
    //                     head = next;

    //                 else
    //                     prev->next = next;
    //             }
    //             else
    //             {
    //                 prev = temp;
    //                 temp = temp->next;
    //             }
    //         }
    //     }
    // }

    // void sortInventoryByType()
    // {
    //     for (int i = 1; i <= count(); i++)
    //     {
    //         Component *temp = head, *prev = NULL;
    //         while (temp->next != NULL)
    //         {
    //             if (temp->type > temp->next->type)
    //             {
    //                 Component *next = temp->next;
    //                 temp->next = next->next;
    //                 next->next = temp;

    //                 if (prev == NULL)
    //                     head = next;
    //                 else
    //                     prev->next = next;
    //             }
    //             else
    //             {
    //                 prev = temp;
    //                 temp = temp->next;
    //             }
    //         }
    //     }
    // }
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
         << "6. Exit\n"
         << "*********************************************************\n"
         << "Enter your choice: ";
}
#endif