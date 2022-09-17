#include <iostream>
#include <string>
using namespace std;

int top = -1;
char * stack = NULL;

/*
Date: 18 August
Question: Reversing a string using a stack.
*/

void push(char in)
{
    top++;
    stack[top] = in;
}

void pop(int flag, int SIZE)
{
    cout << stack[top];
    top--;
}
    

int main()
{
    string input;
    int  i = 0,flag = 0;
    cout << "Enter the string to be reversed: " << endl;
    getline(cin,input);
    int SIZE = input.length();
    stack = new char[SIZE];
    while(input[i] != '\0')
    {
        if (input[i] == 32)
        {
            cout << "Space character encountered" << endl;
            flag++;
        }
        else
            push(input[i]);
        
        i++;
    }

    for (int j = 0; j < SIZE - flag; j++)
    {
        pop(flag,SIZE);
    }
    return 0;
}