#include <iostream>
using namespace std;

/*Date: 8 August
Question: To find the saddle point in a 2D array.
(Largest or equal to every number in its column, and smallest or equal to every number in its row.)
*/

void create (int ** matrix, int rows, int columns)
{
    cout << "Give input: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns ; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

int * findSaddlePoint(int rows, int columns,int ** arr)
{
    int * saddlePoint = new int[2];
    int * largestInColumn = new int[columns];
    int * smallestInRow = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == 0)
            {
                largestInColumn[j] = 0;
            }
            else if (arr[i][j] > arr[largestInColumn[j]][j])
                {
                    largestInColumn[j] = i;
                }
            if (j == 0)
            {
                smallestInRow[i] = 0;
            }
            else if (arr[i][j] < arr[i][smallestInRow[i]])
                {
                    smallestInRow[i] = j;
                }
        }
    }
    
    for (int i = 0; i < rows; i++)
    {
        if (largestInColumn[smallestInRow[i]] == i)
        {
            saddlePoint[0] = i;
            saddlePoint[1] = smallestInRow[i];
            cout << "Encountered saddlePoint" << endl;
            return saddlePoint;
        }
    }
    return NULL;
}

int main()
{
    int * saddlePoint = NULL;
    int rows, columns;
    cout << "Enter the number of rows in the array: " << endl;
    cin >> rows;
    cout << "Enter the number of columns in the array: " << endl; 
    cin >> columns;
    int ** arr = new int*[rows];
    for ( int i = 0; i < rows; i++ )
    {
        arr[i] = new int[columns];
    }
    create(arr,rows,columns);

    saddlePoint = findSaddlePoint(rows, columns,arr);
    

    if (saddlePoint == NULL)
    {
        cout << "The entered matrix has no saddle point!" << endl;
    }
    else{
        cout << "The saddle Point lies in the (" << saddlePoint[0] << "," << saddlePoint[1] << ") position" << endl;
    }
    return 0;
}