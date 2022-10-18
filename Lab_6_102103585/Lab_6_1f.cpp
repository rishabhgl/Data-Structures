#include <iostream>
using namespace std;

//Date:13 October
//Question: Implementation of Counting Sort

int main()
{
    int input,k,num = 1, i = 0; 
    cout << "Enter the number of inputs: " << endl;
    cin >> input;
    int inArr[input];
    cout << "Enter the maximum number k that is present in the array: " << endl;
    cin >> k;
    int freqArr[k+1];
    int outArr[input];
    for (int i = 0; i < input; i++)
    {
        cin >> inArr[i];
    }
    for (int i  = 0; i <= k ; i++)
    {
        freqArr[i] = 0;
    }
    for (int i = 0; i < input; i++)
    {
        freqArr[inArr[i]]++;
    }
    while (i < input)
    {
        if (freqArr[num])
        {
            outArr[i] = num;
            freqArr[num]--;
            if (!freqArr[num])
                num++;
            i++;
        }
    }
    for (int i = 0; i < input; i++)
    {
        cout << outArr[i] << " "; 
    }
    return 0;
}