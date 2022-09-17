#include <iostream>
#include <string>
using namespace std;

/*
Date : 18 August
Question: Write a program to convert an Infix expression into a Postfix expression.
*/

class Stack
{
    int top;
    char *stack;
    int size;

public:
    Stack(){};
    Stack(int size)
    {
        stack = new char[size];
        top = 0;
    }
    void push(char element)
    {
        if (isFull())
            cout << "Stack is overflowing!" << endl;
        else
            stack[top] = element;
            top++;
    }
    bool isFull()
    {
        if (top == size)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (top == 0)
            return true;
        else
            return false;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Underflowing!!" << endl;
            return CHAR_MIN;
        }
        else
            return stack[top--];
    }
    char peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Underflowing!!" << endl;
            return CHAR_MIN;
        }
        else
        {
            return stack[top];
        }
    }
};

string convert(string input, string output)
{
    input.push_back(')'); //input = 1+2)
    Stack stack = Stack(input.length()); // stack size = 4
    stack.push('(');  //top = 1,stack = (
    char temp = ')';   // temp =  )
    int i = 0;
    while (input[i] != '\0')
    {
        switch (input[i])
        {
        case '(':
            stack.push('(');
            break;
        case ')':
            while (temp != '(')
            {
                temp = stack.pop();
                if (temp != '(')
                    output.push_back(temp);
            }
            temp = ')';
            break;
        case '+':
            while (temp != '+' && temp != '-' && temp != '(')
            {
                if (temp != '(')
                {
                    temp = stack.pop();
                    output.push_back(temp);
                }
            }
            stack.push('+');
            temp = ')';
            break;
        case '-':
            while (temp != '-' && temp != '+' && temp != '(')
            {
                if (temp != '(')
                {
                    temp = stack.pop();
                    output.push_back(temp);
                }
            }
            stack.push('-');
            temp = ')';
            break;
        case '*':
            if (stack.peek() != '+' && stack.peek() != '-')
            {
                while (temp != '*' && temp != '/' && temp != '(')
                {
                    if (temp != '(')
                    {
                        temp = stack.pop();
                        output.push_back(temp);
                    }
                }
            }
            stack.push('*');
            temp = ')';
            break;
        case '/':
            if (stack.peek() != '+' && stack.peek() != '-')
            {
                while (temp != '*' && temp != '/' && temp != '(')
                {

                    if (temp != '(')
                    {
                        temp = stack.pop();
                        output.push_back(temp);
                    }
                }
            }
            stack.push('/');
            temp = ')';
            break;
        case '^':
            if (stack.peek() == '^')
                output.push_back(stack.pop());
            stack.push('^');
            temp = ')';
            break;
        

        default:
            output.push_back(input[i]);  //output = 1
            break;
        }
        i++;
    }
    return output;
}

int main()
{
    string input, output = "";
    cout << "Enter infix expression: " << endl;
    getline(cin, input);
    output = convert(input, output);
    cout << "The postfix expression is: " << output << endl;
    return 0;
}