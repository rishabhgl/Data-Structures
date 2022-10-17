#include <iostream>
using namespace std;

/* Date: 8 August
Question: To find the sum of every column and every row in a two dimensional array.*/



int main()
{
    int size;
    cout << "Enter the number of rows and colums in your square matrix: " << endl;
    cin >> size;
    int sumRow;
    int * sumColumn = new int[size];
    for (int i = 0; i < size; i++)
    {
        sumColumn[i] = 0;
    }
    int arr[size][size];
    cout << "Enter the elements into your array: " << endl;
    for(int i = 0; i < size; i++){
        sumRow = 0;
        for(int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
            sumRow += arr[i][j];
            sumColumn[j] += arr[i][j];
        }
        cout << "The sum of row " << i+1 << " is: " << sumRow << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "The sum of column " << i+1 << " is: " << sumColumn[i] << endl;
    }
    return 0;
}