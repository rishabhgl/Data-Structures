#include <iostream>
using namespace std;

// Date: 18 Sept 2022
// Question: Finding the size of a Circular Linked List

struct CLL
{
    int data;
    struct CLL *next;
};

typedef struct CLL node;
node *tail = NULL;

void create()
{
    if (tail == NULL)
    {
        tail = new node;
        cout << "Enter data: " << endl;
        cin >> tail->data;
        tail->next = tail;
    }
    else
    {
        node *temp = new node;
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
        cout << "Enter data: " << endl;
        cin >> tail->data;
    }
}

void getSize()
{
    int count = 0;
    if (tail != NULL)
    {
        node *temp = tail->next;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != tail->next);
        cout << "The size of the linked list is: " << count << endl;
    }
    else
        cout << "The linked list is empty!" << endl;
}

int main()
{
    int menu;
    cout << "Press 0 to exit" << endl;
    cout << "Press 1 to create node" << endl;
    cout << "Press 2 to get size of list" << endl;
    cin >> menu;
    while (menu)
    {
        switch (menu)
        {
        case 1:
            create();
            break;
        case 2:
            getSize();
            break;
        default:
            break;
        }
        cout << "Select menu item: " << endl;
        cin >> menu;
    }
    return 0;
}
