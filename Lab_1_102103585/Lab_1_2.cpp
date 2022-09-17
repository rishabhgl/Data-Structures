#include <iostream>
using namespace std;

// Name: Rishabh Goyal
// Date: 28 July
// Question: Program to remove duplicate items in an array.


void create(int * arr,int  size){
    cout << "Enter the items into the array:" << endl;
    for( int i = 0; i < size; i++){
        cin >> arr[i];
    }
}

void overwrite(int * arr,int *size, int pos){
    for (int i = pos; i < (*size); i++){
        if (pos != (*size)-1)
            arr[i] = arr[i+1];
        else 
            arr[i] = 0;
    }
    (*size)--;
}

void display(int * arr, int size){
    for( int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
}

int main()
{
    
    int size;
    cout << "Enter the number of elements to be put in the array: " << endl;
    cin >> size;
    int * arr = new int[size];
    create(arr,size);
    cout << "The size of the array created is " << sizeof(arr) << endl;
    for (int i = 1; i < size; i++){
        for (int j = i-1; j >= 0; j--){
            if(arr[i] == arr[j]){
                overwrite(arr,&size,i);
                i--;
                break;
            }
        }
    }
    cout << "The new array:" << endl;
    display(arr, size);
    cout << "The size of the array created is " << sizeof(arr) << endl;    
    return 0;
}