#include <iostream>
using namespace std;

//Date:13 October
//Question: Implementation of Selection Sort

int main()
{
    int input,min,temp;
    cout << "Enter the number of inputs: " << endl;
    cin >> input;
    int arr[input];
    for (int i = 0; i < input; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < input-1; i++)
    {
        min = i;
        for (int j = i+1; j < input; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if ( i != min )
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    for (int i = 0; i < input; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}