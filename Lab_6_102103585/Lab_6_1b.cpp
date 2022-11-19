#include <iostream>
using namespace std;

//Date:13 October
//Question: Implementation of Insertion Sort

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
        key = arr[i];
        passes++;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key){
                arr[j+1] = arr[j];
                comp++;
                passComp++;
            }
            else{
                comp++;
                break;
            }
                
        }
        swaps = swaps + passComp;
        passComp = 0;
        arr[j+1] = key;
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