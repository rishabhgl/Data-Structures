#include <iostream>
using namespace std;

/* Name : Rishabh Goyal
Date : 28 July 2022
Question : Write a Menu driven program to demonstrate the following operations of arrays:
create 
display
insert 
delete
search
exit
*/

int size;

void create(int * arr){
    int count;
    cout << "Enter the number of items to be entered into the array: (number must be less than 9)" << endl;
    cin >> count;
    size  = count;
    cout << "Enter the items into the array:" << endl;
    for( int i = 0; i < count; i++){
        cin >> arr[i];
    }
}

void display(int * arr){
    int count;
    cout << "Enter the number of items to be displayed (from the beginning of the array)" << endl;
    cin >> count;
    for( int i = 0; i < count; i++){
        cout << arr[i] << endl;
    }
}
void insert(int * arr){
    int pos,num;
    cout << "Enter the index at which the vlaue must be inserted:" << endl;
    cin >> pos;
    cout << "Enter the number to be inserted:" << endl;
    cin >> num;
    for (int i = size ; i > pos ; i--){
        if(!(i == pos+1))
            arr[i] = arr[i-1];
        else{
            arr[i] = arr[i-1];
            arr[i-1] = num;
        }
    }

}

void overwrite(int * arr){
    int pos;
    cout << "Enter the index at which the item must be overwritten:" << endl;
    cin >> pos;
    for (int i = pos; i < size; i++){
        if (pos != size-1)
            arr[i] = arr[i+1];
        else 
            arr[i] = 0;
    }
}

void search (int * arr){
    int item, flag = 0;
    cout << "Enter the item to be searched for:" << endl;
    cin >> item;
    for(int i = 0; i < size; i++){
            if(arr[i] == item){
                cout << "The required item found at index " << i << endl;
                break;
            }
            if((i == size -1) && (flag == 0)){
                cout << "Item not found!!" << endl;
            }
    }
}


int main(){
    int ref;
    int arr[10];
    cout<< "An input executes any one of the following operations:\n1. create\n2.display\n3.insert\n4.delete\n5.search\n6.exit" << endl;
    int j = 0;
    while(1){
        cout << "Enter the reference for the menu item" << endl;
        cin >> ref;
            switch(ref){
        case 1: create(arr);
                break;
        case 2: display(arr);
                break;
        case 3: insert(arr);
                break;
        case 4: overwrite(arr);
                break;
        case 5: search(arr);
                break;
        case 6: exit(0);
    }
    }
    return 0;
}