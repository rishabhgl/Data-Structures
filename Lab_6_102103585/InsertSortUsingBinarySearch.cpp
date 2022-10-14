#include <iostream>
using namespace std;

//Date: 14 October 2022
//Question: Implementing Insertion Sort Using Binary Search

int binarySearch(int * arr,int * compAdd,int pos){
    int key = arr[pos];
    int low = 0;
    int high = pos - 1;
    int mid = (low + high)/2;
    while (low <= high)
    {
        if (key < arr[mid])
        {
            (*compAdd)++;
            high = mid - 1;
            mid = (low + high)/2;

        }
        else if (key > arr[mid])
        {
            (*compAdd)++;
            low = mid + 1;
            mid = (low + high)/2;
        }
    }
    return low;
};

int main()
{
    int in, key, j, passes = 0, swaps = 0, comp = 0,passComp = 0,pos;
    cout << "Number of inputs = " << endl;
    cin >> in;
    int arr[in];
    for (int i = 0; i < in; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < in; i++)
    {
        passes++;
        pos = binarySearch(arr,&comp,i);
        key = arr[i];
        for (int j = i; j > pos; j--)
        {
            arr[j] = arr[j-1];
            swaps++;
        }
        arr[pos] = key;
    }
    for (int i = 0; i < in; i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl;
    cout << "Number of passes = " << passes << endl;
    cout << "Number of swaps = " << swaps << endl;
    cout << "Number of comparisons = " << comp << endl;
    return 0;
}

