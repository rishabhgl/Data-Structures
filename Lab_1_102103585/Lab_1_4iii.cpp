#include <iostream>
using namespace std;

/*Name: Rishabh Goyal
Date: 28 July 
Question: Find the transpose of a matrix*/

void create(int row, int column, int **arr){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cin >> arr[i][j];
        }
    }
}

void transpose(int row, int column, int ** arr){
    for (int i = 0; i < column; i++)
    {
        for(int j = 0; j < row; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

int main(){
    int row, column;
    cout << "Enter the number of rows in the matrix" << endl;
    cin >> row;
    cout << "Enter the number of columns in the matrix" << endl;
    cin >> column;

    int **arr = new int*[row];
    for (int i = 0; i < row; i++){
        arr[i] = new int[column];
    }
    cout << "Enter the elements in the array:" << endl;
    create(row,column,arr);

    transpose(row,column,arr);
    return 0;
}