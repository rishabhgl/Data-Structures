#include <iostream>
using namespace std;

//Date: 18 Sept 2022
//Question: To find the size of a doubly linked list

struct DLL
{
    int data;
    struct DLL * next;
    struct DLL * prev;
};

typedef struct DLL node;
node * head = NULL, * temp = NULL;

void create()
{
    if (head == NULL)
    {
        head = new node;
        cout << "Enter data: " << endl;
        cin >> head->data;
        head->prev = NULL;
        head->next = NULL;
        temp = head;
    }
    else{
        temp->next = new node;
        cout << "Enter data: " << endl;
        cin >> temp->next->data;
        temp->next->next = NULL;
        temp->next->prev = temp;
        temp = temp->next;
    }
}

void getSize()
{
    int count = 0;
    node * ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    cout << "The size of the linked list is: " << count << endl;
}


int main()
{
    int menu;
    cout << "Press 0 to exit\nPress 1 to add node\nPress 2 to get size of the linked list" << endl;
    cin >> menu;
    while (menu)
    {
        switch(menu)
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