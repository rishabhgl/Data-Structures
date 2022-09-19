#include <iostream>
using namespace std;

//Backward and Forward rotations of an n sized 3D array k times

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int arr[n][n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                cin >> arr[i][j][l];
            }
        }
    }

    int i, temp1, temp2, column;

    for (int rot = 0; rot < k; rot++)
    {
        i = 0;
        // Backward Rotation
        if (n % 2 == 1)
            temp1 = arr[n - 1][n - 1][n - 1];
        else
            temp1 = arr[0][n - 1][0];

        for (int row = 0; row < n; row++)
        {
            if (row % 2 == 0)
            {
                while (i < n)
                {
                    if (i == -1)
                        i++;
                    temp2 = arr[i][row][i];
                    arr[i][row][i] = temp1;
                    temp1 = temp2;
                    i++;
                }
            }
            else
            {
                while (i >= 0)
                {
                    if (i == n)
                        i--;
                    temp2 = arr[i][row][i];
                    arr[i][row][i] = temp1;
                    temp1 = temp2;
                    i--;
                }
            }
        }

        // Forward rotation

        i = n - 1;
        column = 0;

        if (n % 2 == 1)
            temp1 = arr[0][n - 1][n - 1];
        else
            temp1 = arr[n - 1][n - 1][0];

        for (int row = 0; row < n; row++)
        {
            if (row % 2 == 0)
            {
                while (i >= 0)
                {
                    if (i == n)
                    {
                        i--;
                        column++;
                    }
                    temp2 = arr[i][row][column];
                    arr[i][row][column] = temp1;
                    temp1 = temp2;
                    i--;
                    column++;
                }
            }
            else
            {
                while (i < n)
                {
                    if (i == -1)
                    {
                        i++;
                        column--;
                    }
                    temp2 = arr[i][row][column];
                    arr[i][row][column] = temp1;
                    temp1 = temp2;
                    i++;
                    column--;
                }
            }
        }
    }

    // Display
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                cout << arr[i][j][l] << " ";
            }
        }
    }
    return 0;
}