#include <iostream>
using namespace std;

/* Date: 8 August
Question: Implement the following operations on a sparse matrix:
1. Transpose of a matirx
2. Addition of two matrices
3. Multiplication of two matrices */

void create(int ** triplet,int size){
    cout << "Input data into the sparse matrix triplet by specifying the row index, column index, and then value: " << endl;
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < 3; j++)
        {
           cin >> triplet[i][j]; 
        }
    }

}

void display(int **triplet, int sizeMatrix)
{
    int index = 0;;
    for (int i = 0; i < sizeMatrix; i++)
    {
        for (int j = 0; j < sizeMatrix; j++)
        {
            if (index >= sizeMatrix)
            {
                cout << "0 ";
            }
            else if (i == triplet[index][0] && j == triplet[index][1])
            {
                cout << triplet[index][2] << " ";
                index++;
            }
            else   
                cout << "0 " ;
        }
        cout << endl;
    }
}

void sort(int ** triplet, int size)
{
    int * temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (triplet[i][0] > triplet[j][0])
            {
                temp = triplet[j];
                triplet[j] = triplet[i];
                triplet[i] = temp;
            }
            if(triplet[i][0] == triplet[j][0] && triplet[i][1] > triplet[j][1])
            {
                temp = triplet[j];
                triplet[j] = triplet[i];
                triplet[i] = temp;
            }
        }
        
    }
}

void transpose(int ** triplet, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        temp = triplet[i][0];
        triplet[i][0] = triplet[i][1];
        triplet[i][1] = temp;
    }
    
}

int find(int ** triplet, int sizeTriplet, int i, int j)
{
    for (int x = 0; x < sizeTriplet; x++)
    {
        if (triplet[x][0] == i && triplet[x][1] == j)
        {
            return triplet[x][2];
        }
    }
    return 0;
}

void add(int **triplet1, int ** triplet2,int sizeMatrix, int sizeTriplet1, int sizeTriplet2)
{
    int a,b,index1 = 0,index2 = 0;
    for (int i = 0; i < sizeMatrix; i ++)
    {
        for (int j = 0; j < sizeMatrix; j++)
        {
            if (index1 >= sizeTriplet1)
            {
                a= 0;
            }else if(i == triplet1[index1][0] && j == triplet1[index1][1])
                {a = triplet1[index1][2];
                index1++;}
            else    
                a = 0;
            if (index2 >= sizeTriplet2)
            {
                b = 0;
            }
            else if (i == triplet2[index2][0] && j == triplet2[index2][1])
                {b = triplet2[index2][2];
                index2++;}
            else    
                b = 0;
            cout << a + b << "\t";
            
        }
        cout << endl;
    }
}
void multiply(int ** triplet1, int ** triplet2, int sizeMatrix, int sizeTriplet1, int sizeTriplet2)
{
    int a,b,sum = 0;
    for (int i = 0; i < sizeMatrix; i++)
    {
        for(int j = 0; j < sizeMatrix; j++)
        {
            for (int k = 0; k < sizeMatrix; k++)
            {
            a = find(triplet1,sizeTriplet1,i,k);
            b = find(triplet2,sizeTriplet2,k,j);
            sum += a * b;
            }
            cout << sum << "\t";
            sum = 0;
        }
        cout << endl;
    }
}

int main()
{
    int sizeTriplet1,sizeTriplet2,menu,sizeMatrix;
    cout << "Enter the number of rows and columns in the square sparse matrix: " << endl;
    cin >> sizeMatrix;
    int **triplet1 = NULL;
    int **triplet2 = NULL;
    cout << "Select one of the following options by entering the corresponding number: " << endl;
    cout << "1. Transpose" << endl << "2. Addition of two matrices" << endl << "3.Multiplication of two matrices" << endl;
    cin >> menu;
    switch(menu){
        case 1:
            cout << "Enter the number of non-zero elements in the sparse matrix" << endl;
            cin >> sizeTriplet1;
            triplet1 = new int* [sizeTriplet1];
            for(int i = 0; i < sizeTriplet1; i++){
                triplet1[i] = new int[3];
            }
            create(triplet1,sizeTriplet1);
            transpose(triplet1,sizeTriplet1);
            sort(triplet1,sizeTriplet1);
            display(triplet1,sizeMatrix);
            break;
        case 2:
            cout << "Enter the number of non-zero elements in the sparse matrix" << endl;
            cin >> sizeTriplet1;
            triplet1 = new int* [sizeTriplet1];
            for(int i = 0; i < sizeTriplet1; i++){
                triplet1[i] = new int[3];
            }
            create(triplet1,sizeTriplet1);
            sort(triplet1,sizeTriplet1);
            cout << "Enter the number of non-zero elements in the sparse matrix" << endl;
            cin >> sizeTriplet2;
            triplet2 = new int* [sizeTriplet2];
            for(int i = 0; i < sizeTriplet2; i++){
                triplet2[i] = new int[3];
            }
            create(triplet2,sizeTriplet2);
            sort(triplet2,sizeTriplet2);
            add(triplet1,triplet2,sizeMatrix, sizeTriplet1,sizeTriplet2);
            break;
        case 3:
            cout << "Enter the number of non-zero elements in the sparse matrix" << endl;
            cin >> sizeTriplet1;
            triplet1 = new int* [sizeTriplet1];
            for(int i = 0; i < sizeTriplet1; i++){
                triplet1[i] = new int[3];
            }
            create(triplet1,sizeTriplet1);
            cout << "Enter the number of non-zero elements in the sparse matrix" << endl;
            cin >> sizeTriplet2;
            triplet2 = new int* [sizeTriplet2];
            for(int i = 0; i < sizeTriplet2; i++){
                triplet2[i] = new int[3];
            }
            create(triplet2,sizeTriplet2);
            multiply(triplet1,triplet2,sizeMatrix,sizeTriplet1,sizeTriplet2);
            break;
    }
    return 0;
}