#include <iostream>
using namespace std;

// Date: 19 October
// Question: Improved Selection Sort

int main()
{
    int input, temp;
    cout << "Enter number of inputs:" << endl;
    cin >> input;
    int arr[input];
    int min, max;
    for (int i = 0; i < input; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < input / 2; i++)
    {
        max = i;
        min = i;
        for (int j = i + 1; j < input - i; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }

        // Swap minimum to the front
        if (min != i)
        {
            
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            
        }

        // Swap maximum to the back
        if (max == i)
            max = min;

        if (max != input - 1 - i)
        {
            temp = arr[input - 1 - i];
            arr[input - 1 - i] = arr[max];
            arr[max] = temp;
        }
    }
    for (int i = 0; i < input; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}