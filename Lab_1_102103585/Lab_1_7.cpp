#include <iostream>
using namespace std;

/*Name: Rishabh Goyal
Date : 29 July 2022
Question: To find the missing elements in a sorted array. (Pattern : Consecutive numbers.)*/


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

int find(int * arr, int * miss, int size){
    int missing_size = 0, index = 0;
    const int ref = *arr;
    for (int i = 0; i < size; i++){
        if((arr[i] - i) != ref){
            missing_size = (arr[i] - i) - ref;
            int num = 1;
            for (index; index < missing_size; index++){
                miss[index] = arr[i - 1] + num;
                num++;
            }
        }
    }
    return missing_size;
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
    int * missingArray = new int[size];
    create(arr,size);
    bubble_sort(arr,size);
    int missingSize = find(arr,missingArray,size);
    display(missingArray,missingSize);
    free(missingArray);
    free(arr);
    return 0;
}