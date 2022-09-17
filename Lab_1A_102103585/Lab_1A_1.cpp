#include <iostream>
using namespace std;

/*Name: Rishabh Goyal
Date: 4 August
Question: Implement the following two dimensional matrices in the most efficient way possible
1. Diagonal matrix
2. Tridiagonal matrix
2.Lower Triangular matrix
4. Upper triangular matrix
5. Symmetric matrix*/

void create(int *arr, int size){
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

}

void printDiagonalMatrix(int rows, int * arr){
    int index = 0;
    cout << "Printing the required matrix: " << endl;
    for (int i = 0; i < rows; i++)
            {
                for(int j = 0; j < rows; j++)
                {
                    if(i==j){
                        cout << arr[index] << " ";
                        index++;
                    }
                    else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
}

void printTriDiagonalMatrix(int *arr, int rows){
    int index = 0;
    cout << "Printing the required matrix: " << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if( i==j || i-j==1 || j-i==1){
                cout << arr[index] << " ";
                index++;
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void printLowerTriangularMatrix(int * arr, int rows){
    int index = 0;
    cout << "Printing the required matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (i >= j)
            {
                cout << arr[index] << " ";
                index++;
            }
            else{
                cout << "0 " ;
            }
        }
            cout << endl;
    }
}
void printUpperTriangularMatrix(int * arr, int rows){
    int index = 0;
    cout << "Printing the required matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (i <= j)
            {
                cout << arr[index] << " ";
                index++;
            }
            else{
                cout << "0 " ;
            }
        }
            cout << endl;
    }
}

void printSymmetricMatrix(int * arr, int rows){
    int upperIndex = 0;
    int lowerIndex = 1;
    int skipIndex = 0;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if( j >= i)
            {
                cout << arr[upperIndex] << " ";
                upperIndex++;
            }
            else{
                if (lowerIndex == (skipIndex + 1)*rows - skipIndex)
                {
                    lowerIndex++;
                    skipIndex++;
                }
                cout << arr[lowerIndex] << " ";
                lowerIndex++;
                
            }
        }
        cout << endl;
    }
}


int main(){
    int rows,columns,menu;
    cout << "Enter the number of rows and columns in the matrix: " << endl;
    cin >> rows;
    int * arr = NULL;
    cout << "Select the desired menu option from the following: " << endl;
    cout << "1. Diagonal matrix" << endl << "2. Tri-diagonal matrix" << endl << "3. Lower triangular matrix" << endl << "4. Upper triangular matrix" << endl << "5. Symmetric matrix" << endl;
    cin >> menu;
    switch(menu){
        case 1:
            arr = new int[rows];
            cout << "Enter the elements in the array: " << endl;
            create(arr,rows);
            printDiagonalMatrix(rows,arr);
            free(arr);
            break;
        case 2:
            arr = new int[3*rows -2];
            cout << "Enter the elements into the array in row-major order: " << endl;
            create(arr,3*rows-2);
            printTriDiagonalMatrix(arr,rows);
            free(arr);
            break;
        case 3:
            arr = new int[(rows*(rows+1))/2];
            cout << "Enter the elements into the array in row-major order: " << endl;
            create(arr,(rows*(rows+1))/2);
            printLowerTriangularMatrix(arr,rows);
            free(arr);
            break;
        case 4:
            arr = new int[(rows*(rows+1))/2];
            cout << "Enter the elements into the array in row-major order: " << endl;
            create(arr,(rows*(rows+1))/2);
            printUpperTriangularMatrix(arr,rows);
            free(arr);
            break;
        case 5:
            arr = new int[(rows*(rows+1))/2];
            cout << "Enter the elements of the upper triangle into the array in row major order: " << endl;
            create(arr,(rows*(rows+1))/2);
            printSymmetricMatrix(arr,rows);

    }
    return 0;
}

