#include <iostream>
using namespace std;

/*Name: Rishabh Goyal
Date : 29 July 2022
Question:Implementation of binary serach.*/

int binarySearch(int * arr, int size){
    int num;
    int low = 0;
    int high = size - 1;
    int mid = (low + high)/2;
    cout << "Enter the number to be found: " << endl;
    cin >> num;
    while(low <= high){
        if(arr[mid] == num){
            return mid;
        }
        else if(arr[mid] > num){
            high = mid-1;
            mid = (low + high)/2;
        }
        else{
            low = mid + 1;
            mid = (low + high)/2;
        }
    }
    return -1;
}
void bubble_sort(int *arr, int size){
    int temp;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void create(int * arr, int size){
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
}

void display(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int size;
    
    
    
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int * arr = new int[size];
    create(arr,size);
    bubble_sort(arr,size);
    
    
    int index = binarySearch(arr, size);
    if(index != -1){
        cout << "The number was found at index: " << index << endl;
    }
    else{
        cout << "The number was not found!!" << endl;
    }
    free(arr);
    return 0;
}