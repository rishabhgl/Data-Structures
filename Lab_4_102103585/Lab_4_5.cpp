#include <iostream>
#include <cmath>
using namespace std;

/*
Date: 24 Aug
Question: Postfix expression evaluation
*/

class Stack{

    int size;
    int top;
    int * stack;

    public:

    Stack()
    {

    }

    int getSize()
    {
        return size;
    }
    void createStack()
    {
        cout << "Enter the size of the input expression: " << endl;
        cin >> size;
        top = 0;
        stack = new int[size];
    }
    void push(int element)
    {
        if (top == size){
            cout << "Overflowing stack" << endl;
        }
        else{
        stack[top] = element;
        top++;
        }
    }
    int pop(){
        if(top == 0)
        {
            cout << "Underflowing stack" << endl;
            return INT_MIN;
        }
        else{
            top--;
            return stack[top];
        }
    }
};

int main()
{
    Stack stack;
    char unit;
    int initial, final;
    stack.createStack();
    cout << "Please enter the expression entering space after each operand/operator: " << endl;
    for (int i = 0; i < stack.getSize(); i++)
    {
       cin >> unit;
       switch(unit)
       {
        case '+':
            stack.push(stack.pop() + stack.pop());
            break;
        case '-':
            final = stack.pop();
            initial = stack.pop();
            stack.push(initial - final);
            break;
        case '*':
            stack.push(stack.pop() * stack.pop());
            break;
        case '^':
            final = stack.pop();
            initial = stack.pop();
            stack.push(pow(initial,final));
            break;
        case '/':
            final = stack.pop();
            initial = stack.pop();
            stack.push(int(float(initial)/final));
            break;
        default:
            stack.push(int (unit - '0'));
            break;
       } 
    }
    cout << endl << "The expression evaluates to: " << stack.pop() << endl;
    return 0;
}