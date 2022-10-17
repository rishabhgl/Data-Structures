#include <iostream>
using namespace std;

//Date:13 October
//Question: Implementation of Quick Sort

int partition(int * arr,int low,int high)
{
    int key = arr[high] , i = low - 1, temp;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < key)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = key;
    arr[high] = temp;
    return i+1;
}

void quickSort(int * arr, int low, int high)
{
    if (low < high)
    {
        int pos = partition(arr,low,high);
        quickSort(arr,low,pos-1);
        quickSort(arr,pos+1,high);
    }
    
}

int main()
{
    int in;
    cout << "Enter the number of inputs: " << endl;
    cin >> in;
    int arr[in];
    for (int i = 0; i < in; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr,0,in-1);
    for (int i = 0; i < in; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}