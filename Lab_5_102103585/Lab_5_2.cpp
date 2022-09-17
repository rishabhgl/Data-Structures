#include <iostream>
using namespace std;

class CircularQ
{
    int front;
    int rear;
    int * q;

    public:

    CircularQ(){
        front = -1;
        rear = -1;
        q = new int[3];
    }
    bool isFull()
    {
        if(front == (rear+1)%3)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (rear == -1 && front == rear)
            return true;
        else 
            return false;
    }
    void enqueue(int element)
    {
        if(isFull())
        {
            cout << "Cannot enqueue, queue is full!" << endl;
        }
        else{
            if (rear == -1)
            {
                front = 0;
            }
            rear = (rear+1)%3;
            q[rear] = element;
            cout << "The value of front now is: " << front << endl;
            cout << "The value of rear now is: " << rear << endl;
        }
    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout << "Cannot dequeue, queue is empty!" << endl;
            return INT_MIN;
        }
        else{
            int temp = q[front];
            if(front ==rear)
            {
                rear = -1;
                front = -1;
            }
            else
                front = (front+1)%3;
            return temp;
        }
    }

    int peek()
    {
        if(isEmpty())
        {
            cout << "Cannot peek, queue is empty!" << endl;
            return INT_MIN;
        }
        else
            return q[front];
    }
    void display()
    {
        int i = front-1;
        do
        {
            i = (i+1)%3;
            cout << q[i] << endl;
        }   while (i != rear);
    }
};

int main()
{
    int menu,item;
    CircularQ q;
    cout << "Select from following operations that can be performed on the queue: " << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Check whether empty" << endl;
    cout << "4. Check if full" << endl;
    cout << "5. Peek at the element in front of queue" << endl;
    cout << "6. Display all items in queue" << endl;
    cout << "0. Exit" << endl;
    do
    {
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Enter the item to enqueue: " << endl;
            cin >> item;
            q.enqueue(item);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            if (q.isEmpty())
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
            break;
        case 4:
            if (q.isFull())
                cout << "Queue is full" << endl;
            else
                cout << "Queue is not full" << endl;
            break;
        case 5:
            if (q.isEmpty())
            {
                cout << "Cannot peek, queue is empty!" << endl;
            }
            else
            {
                cout << "The first element in line to be dequeued is " << q.peek() << endl;
            }
            break;
        case 6:
            cout << "The elements in the queue are as follows: " << endl;
            q.display();
            break;
        default:
            break;
        }
    } while (menu != 0);
}