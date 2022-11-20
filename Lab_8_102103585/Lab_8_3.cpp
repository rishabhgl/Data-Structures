#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Date: 10 November
// Implementation of priority queue using heaps, including operations on it like:
//  insertKey
//  extractMax
//  peekMax
//  increaseKey

void maxHeapify(int *arr, int beg, int end)
{
    int left = beg;
    int right = beg;
    int largest = beg;
    if (2 * (beg + 1) - 1 <= end)
        left = 2 * (beg + 1) - 1;
    if (2 * (beg + 1) <= end)
        right = 2 * (beg + 1);
    if (arr[largest] < arr[left])
        largest = left;
    if (arr[largest] < arr[right])
        largest = right;
    if (largest != beg)
    {
        int temp = arr[beg];
        arr[beg] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest, end);
    }
}

void buildMaxHeap(int *arr, int size)
{
    for (int i = (size / 2) - 1; i > -1; i--)
    {
        maxHeapify(arr, i, size - 1);
    }
}

void increaseKey(int *arr, int pos)
{
    cout << "Enter the new key: " << endl;
    cin >> arr[pos];
    cout << endl;
    int parent = (pos - 1) / 2, temp;
    while (pos != parent && arr[parent] < arr[pos])
    {
        temp = arr[parent];
        arr[parent] = arr[pos];
        arr[pos] = temp;
        pos = parent;
        parent = (pos - 1) / 2;
    }
}

int main()
{
    int size, menu, pos;
    cout << "Enter the size of the heap used as priority queue:" << endl;
    cin >> size;
    int *arr = new int[size];
    int *arrNew;
    cout << "Enter data: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    buildMaxHeap(arr, size);
    cout << "The following operations can be performed on the heap:" << endl;
    cout << "1. Inserting a new key " << endl;
    cout << "2. Extracting the maximum key " << endl;
    cout << "3. Returning the maximum key" << endl;
    cout << "4. Increasing an existing key " << endl;
    cout << "5. Displaying all the keys in the heap" << endl;
    cout << "0. Exit " << endl;
    cout << endl
         << "Select one of the above options to continue:" << endl
         << endl;
    cin >> menu;
    while (menu)
    {
        switch (menu)
        {
        case 1:
            size++;
            arrNew = new int[size];
            arrNew[size - 1] = INT_MIN;
            for (int i = 0; i < size - 1; i++)
            {
                arrNew[i] = arr[i];
            }
            delete arr;
            arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = arrNew[i];
            }
            delete arrNew;
            increaseKey(arr, size - 1);
            break;
        case 2:
            pos = arr[0];
            arr[0] = arr[size-1];
            arr[size-1] = pos; 
            arrNew = new int[--size];
            for (int i = 0; i < size; i++)
            {
                arrNew[i] = arr[i];
            }
            delete arr;
            arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = arrNew[i];
            }
            delete arrNew;
            maxHeapify(arr,0,size-1);
            cout << "The maximum key that was previously present and now has been deleted from the heap is " << pos << endl;
            break;
        case 3:
            cout << "The maximum key in the heap is " << arr[0] << endl;
            break;
        case 4:
            cout << "Enter the position of the node in the heap whose key must be increased: " << endl;
            cin >> pos;
            if (!(pos >= size))
            {
                increaseKey(arr, pos);
            }
            break;
        case 5:
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            break;
        default:
            break;
        }
        cout << endl
             << "Select one of the above options to continue:" << endl
             << endl;
        cin >> menu;
    }
}