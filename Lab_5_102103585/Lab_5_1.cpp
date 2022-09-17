#include <iostream>
using namespace std;

class Q
{

    int front;
    int rear;
    int size;
    int *q;

public:
    Q() {}

    Q(int size)
    {
        this->size = size;
        q = new int[size];
        front = 0;
        rear = 0;
    }

    bool isFull()
    {
        if (rear == size)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }

    void enqueue(int element)
    {
        if (isFull())
            cout << "Queue is full, cannot enqueue!" << endl;
        else
        {
            q[rear] = element;
            rear++;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, cannot dequeue!" << endl;
            return INT_MIN;
        }
        else
        {
            return q[front++];
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Cannot display, queue is empty!" << endl;
        }
        else
        {
            for (int i = front; i < rear; i++)
            {
                cout << q[i] << endl;
            }
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        else
        {
            return q[front];
        }
    }
};

int main()
{
    int menu, size, item;
    cout << "Enter the maximum size of the queue to be created: " << endl;
    cin >> size;
    Q q(size);
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