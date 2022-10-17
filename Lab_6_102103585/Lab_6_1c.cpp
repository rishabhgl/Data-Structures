#include <iostream>
using namespace std;

//Date:13 October
//Question: Implementation of Bubble Sort

int main()
{
    int input,temp;
    cout << "Enter the number of inputs: " << endl;
    cin >> input;
    int arr[input];
    for (int i = 0; i < input; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < input-1; i++)
    {
        for (int j = 0; j < input - i- 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < input; i++)
    {
        cout << arr[i] << " "; 
    }
    return 0;
}