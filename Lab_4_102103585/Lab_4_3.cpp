#include <iostream>
#include <string>
using namespace std;

/*Date: 18 August
Question: Parenthesis matching using stacks
*/

int top = -1;
char * stack = NULL;

void push(char in)
{
    top++;
    stack[top] = in;
    
}

char pop()
{
    return stack[top--];
}

bool check(string input)
{
    for (int  i = 0; i < input.length(); i++)
    {
        switch(input[i])
        {
            case '{':
                push('{');
                break;
            case '(':
                push('(');
                break;
            case '[':
                push('[');
                break;
            case '}':
                if (pop() == '{')
                    break;
                else    
                    return false;
            case ']':
                if (pop() == '[')
                    break;
                else    
                    return false;
            case ')':
                if (pop() == '(')
                    break;
                else    
                    return false;
            default:
                break;  
        }
    }
    return true;
}

int main()
{
    string input;
    cout << "Enter input expression: " << endl;
    getline(cin,input);
    cout << input << endl;
    stack = new char[input.length()];
    if(check(input))
    {
        cout << "The paranthesis are matching!" << endl;
    }
    else{
        cout << "The paranthesis are not matching!" << endl;
    }

    return 0;
}