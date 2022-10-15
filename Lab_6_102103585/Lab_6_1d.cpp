#include <iostream>
using namespace std;

//Date:13 October
//Question: Implementation of Merge Sort

int comp = 0;

void Merge(int * arr, int low, int notMid, int high)
{
    int index1= low,index2 = notMid,index3 = 0;
    int tempArr[high+1];
    while (index1 < notMid && index2 <= high)
    {
        if (arr[index1] <= arr[index2])
        {
            tempArr[index3] = arr[index1];
            comp++;
            index1++;
            index3++;
        }
        else{
            tempArr[index3] = arr[index2];
            comp++;
            index2++;
            index3++;
        }
    }
    if (index1 == notMid)
    {
        while (index2 <= high)
        {
            tempArr[index3] = arr[index2];
            index2++;
            index3++;
        }
    }
    if (index2 > high)
    {
        while (index1 !=  notMid)
        {
            tempArr[index3] = arr[index1];
            index1++;
            index3++;
        }

    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = tempArr[i-low];
    }
}

void MergeSort(int * arr,int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid+1,high);
    }

}

int main()
{
    int input;
    cout << "Number of items in array: " << endl;
    cin >> input;
    int arr[input];
    for (int i = 0; i < input; i++)
    {
        cin >> arr[i];
    }
    MergeSort(arr,0,input-1);
    for (int i = 0; i < input; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << "Number of comparisons = " << comp << endl;
    return 0;
}