#include <iostream>
using namespace std;

int top = 0, size;
int *stack = NULL;

/*
Date: 18 August
Question: Menu Driven program for following operations on stacks:
    a. push
    b. pop
    c. isEmpty
    d. isFull
    e. display
    f. peek
*/

void push(int num)
{
    if (top == size)
    {
        cout << "Overflow!" << endl;
    }
    else{
    stack[top] = num;
    top++;

    }
}

void display()
{
    for (int i = 0; i < top; i++)
    {
        cout << stack[i] << endl;
    }
}

int pop()
{
    if (top == -1)
    {
        cout << "Underflow!!" << endl;
        return INT_MIN;
    }
    else{
    return stack[--top];
    }
}

void isEmpty()
{
    if (top == 0)
    {
        cout << "The stack is empty!" << endl;
    }
    else
        cout << "The stack is not empty!" << endl;
}

void isFull(int size)
{
    if (top == size)
    {
        cout << "The stack is full!" << endl;
    }
    else
        cout << "The stack is full!" << endl;
}

void peek()
{
    cout << "The element on the top of the stack is " << stack[top-1] << endl;
}



int main()
{
    int temp;
    char option;
    cout << "Enter the size of stack: " << endl;
    cin >> size;
    stack = new int[size];

    cout << "Select the operation to be perform from the following options: " << endl;
    cout << "a. push" << endl;
    cout << "b. pop" << endl;
    cout << "c. Check empty" << endl;
    cout << "d. Check full" << endl;
    cout << "e. Display stack" << endl;
    cout << "f. peek" << endl;
    cout << "Press z to exit!" << endl;

    while (option != 'z')
    {
        cin >> option;

        switch (option)
        {
        case 'a':
            cout << "Enter the number to be pushed to the stack: " << endl;
            cin >> temp;
            push(temp);
            break;
        case 'e':
            cout << "Elements in stack are as follows: " << endl;
            display();
            break;
        case 'b':
            cout << "Last element has been popped :" << pop() << endl;
            break;
        case 'c':
            isEmpty();
            break;
        case 'd':
            isFull(size);
            break;
        case 'f':
            peek();
            break;
        }
    }
    cout << "Exited program." ;

    return 0;
}