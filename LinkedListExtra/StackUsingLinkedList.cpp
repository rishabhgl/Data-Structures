#include <iostream>
using namespace std;

//Date: 18 September 2022
//Question: Implementation of stack using linked list

struct LL
{
    int data;
    struct LL * next;
};

typedef struct LL node;

class stack
{
    node * top;

    public:

    stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else 
            return false;
    }

    void push(int item)
    {
        if (top == NULL)
        {
            top = new node;
            top->next = NULL;
            top->data = item;
        }
        else{
            node * ptr = new node;
            ptr->next = top;
            top = ptr;
            top->data = item;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Cannot pop, stack is empty!" << endl;
            return INT16_MIN;
        }
        else{
            int temp;
            temp = top->data;
            node * ptr = top;
            top = top->next;
            delete ptr;
            return temp;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, cannot peek!" << endl;
            return INT_MIN;
        }
        else
            return top->data;
    }

    void display()
    {
        node * ptr = top;
        while(ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};

int main()
{
    stack s;
    int menu,data;
    cout << "Select from the following menu options:" << endl;
    cout << "1.Push" << endl;
    cout << "2.Pop" << endl;
    cout << "3.Check if empty" << endl;
    cout << "4.Peek" << endl;
    cout << "5.Display" << endl;
    cout << "0.Exit" << endl;
    cin >> menu;
    while(menu)
    {
        switch(menu)
        {
            case 1:
                cout << "Enter data:" << endl;
                cin >> data;
                s.push(data);
                break;
            case 2:
                data = s.pop();
                if (data != INT16_MIN)
                    cout << "Element in last node:" << data << endl;
                break;
            case 3:
                if(s.isEmpty())
                    cout << "Stack is empty" << endl;
                else    
                    cout << "Stack is not empty" << endl;
                break;
            case 4:
                data =  s.peek();
                if (data != INT_MIN)
                    cout << "Element in the last node: " << data << endl;
                break;
            case 5:
                s.display();
                break;
            default:
                break;
        }
        cout << "Enter menu item: " << endl;
        cin >> menu;
    }
    return 0;
}