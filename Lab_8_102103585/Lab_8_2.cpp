#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Date: 10 November
//Implementation of heap sort (decreasing order)

void minHeapify(int * arr,int beg,int end)
{
    int left = beg;
    int right = beg;
    int smallest = beg;
    if (2*(beg+1)-1 <= end)
        left = 2*(beg+1)-1;
    if (2*(beg+1) <= end)
        right = 2*(beg+1);
    if (arr[smallest] > arr[left])
        smallest = left;
    if (arr[smallest] > arr[right])
        smallest = right;
    if (smallest != beg)
    {
        int temp = arr[beg];
        arr[beg] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr,smallest,end);
    }
}

void buildMinHeap(int * arr,int size)
{
    for (int i = (size/2)-1; i > -1; i--)
    {
        minHeapify(arr,i,size-1);
    }
}

void heapSort(int * arr,int size)
{
    buildMinHeap(arr,size);
    int temp;
    for (int i = size - 1; i > 0; i--)
    {
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        minHeapify(arr,0,i-1);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the unsorted array:" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter data: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    heapSort(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}