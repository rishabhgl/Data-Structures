#include <iostream>
using namespace std;

/*Name : Rishabh Goyal
Date: 28 July
Question: Matrix multiplication of any two matrices*/

void create(int row, int column, int **arr){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cin >> arr[i][j];
        }
    }
}

void multiply(int **arr1, int **arr2,int row1, int column1,int row2, int column2){
    int sum = 0;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column2 ; j++)
        {
            for(int k = 0; k < row2; k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            cout << sum << " ";
            sum = 0;
        }
        cout << endl;
    }
}

int main(){
    int row1, column1, row2, column2;

    //Creating first matrix
    cout << "Enter the number of rows in the first matrix: " << endl;
    cin >> row1;
    cout << "Enter the number of columns in the first matrix: " << endl;
    cin >> column1;
    int ** arr1 = new int*[row1] ;
    for (int i = 0; i < column1; i++)
    {
        arr1[i] = new int [column1] ;
    }

    
    create(row1,column1,arr1);

    //Creating second matrix
    
    cout << "Enter the number of rows in the second matrix: (must be equal to columns in first matrix) " << endl;
    cin >> row2;
    cout << "Enter the number of columns in the second matrix: " << endl;
    cin >> column2;

    int ** arr2 = new int*[row2] ;
    for (int i = 0; i < column2; i++)
    {
        arr2[i] = new int [column2] ;
    }

    create(row2,column2,arr2);

    //Multiplying and displaying product 

    multiply(arr1,arr2,row1,column1,row2,column2);
    
    return 0;
}