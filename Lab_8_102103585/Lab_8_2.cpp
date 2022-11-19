#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Date: 10 November
//Implementation of heap sort

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

void buildMinHeap(int * arr,int stop)
{
    for (int i = stop; i < -1; i--)
    {

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
    buildMinHeap(arr,size/2-1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}