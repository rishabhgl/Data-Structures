#include <iostream>
using namespace std;

//Date:13 October
//Question: Implementation of Counting Sort

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
    for (int i = 0; i < input; i++)
    {
        cout << arr[i] << " "; 
    }
    return 0;
}