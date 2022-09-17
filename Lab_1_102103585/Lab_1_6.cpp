#include <iostream>
using namespace std;

/*Name: Rishabh Goyal
Date: 28 July
Question: Bubble sort of given array*/

void bubble_sort(int *arr){
    int temp;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i+1; j < 7; j++){
            if(arr[i] > arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void display(int *arr){
    for(int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
}


int main(){

    int arr[] = {64,34,25,12,22,11,9};
    bubble_sort(arr);
    display(arr);
    return 0;
}