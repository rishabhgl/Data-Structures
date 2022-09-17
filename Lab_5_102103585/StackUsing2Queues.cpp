#include <iostream>
using namespace std;

/*
Date : 25 Aug
Question: Implement a stack using queue when getting input in same order(reversing input) using 2 queues
*/

class Q{
    int front;
    int rear;
    int size;
    int count;
    int * queue;

    public:

    Q(){
        
    }
    Q(int size){
        this->size = size;
        front = 0;
        rear = 0;
        count  = 0;
        queue = new int[size];
    }

    void enqueue(int element)
    {
        if (rear == size)
        {
            cout << "Overflow" << endl;
        }
        else{
        count++;
        queue[rear] = element;
        rear++;
        }
    }

    int dequeue()
    {
        if(front == rear){
            cout << "Underflow" << endl;
            return INT_MIN;
        }
        else{
            count--;
            return queue[front++];
            
        }
    }

    int getSize()
    {
        return size;
    }
    int getCount()
    {
        return count;
    }
};

int main()
{
    int size, input, count;
    bool factor = 1;
    cout << "Enter the size of input: ";
    cin >> size;
    Q qInitial((size * (size + 1))/2);
    Q qFinal((size * (size + 1))/2);
    for (int i = 0; i < size; i++)
    {
        cin >> input;
        if (factor)
        {
            qInitial.enqueue(input);
            count = qFinal.getCount();
            for (int j = 0; j < count; j++)
            {
                qInitial.enqueue(qFinal.dequeue());
            }
            factor  = !factor;
        }
        else{
            qFinal.enqueue(input);
            count = qInitial.getCount();
            for (int j = 0; j < count; j++)
            {
                qFinal.enqueue(qInitial.dequeue());
            }
            factor = !factor;
        }
    }
    if(factor)
    {
        count  = qFinal.getCount();
        for (int i = 0; i < count; i++)
        {
            cout << qFinal.dequeue() << endl;
        }
    }
    else{
        count  = qInitial.getCount();
        for (int i = 0; i < count; i++)
        {
            cout << qInitial.dequeue() << endl;
        }
    }
    return 0;
}