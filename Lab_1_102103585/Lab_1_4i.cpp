#include <iostream>
using namespace std;

/* Name: Rishabh Goyal
Date: 28 July
Question: Reversing an array */

void create(int * arr,int size){
    cout <<"Enter the elements in the array:" << endl;
    for (int i = 0; i < size ; i++){
        cin >> arr[i];
    }
}
void reverse(int *arr, int size){
    int temp;
    for (int i = 0; i < size/2; i++){
        temp = arr[size - 1 - i];
        arr[size - 1 - i] = arr[i];
        arr[i] = temp;
    }
}

void display(int *arr, int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
}

int main()
{
    int size;
    cout << "Enter the number of elements in the array:" << endl;
    cin >> size;
    int arr[size];
    create(arr,size);
    reverse(arr,size);
    cout << "The reversed array is: " << endl;
    display(arr,size);
    return 0;
}