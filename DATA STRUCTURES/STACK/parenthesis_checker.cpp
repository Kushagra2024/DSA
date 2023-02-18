//This program implements Parenthesis Checker using Stack Data Structure

#include<iostream>
#include<string.h>
using namespace std;

class Stack
{
    int _stk[100];
    int _top;
    int _max;

public:
    Stack()
    {
        this->_top = -1;
        this->_max = 100;
    }
    Stack(int max)
    {
        this->_top = -1;
        this->_max = max;
    }

    int isEmpty()
    {
        if (_top == -1)
        {
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if (_top == _max-1)
        {
            return 1;
        }
        return 0;
    }

    void push(char ch)
    {
        if (isFull())
        {
            return;
        }
        _stk[++_top] = ch;
    }
    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        _top--;
    }
    char top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return(_stk[_top]);
    }
};

int main()
{
    char arr[100];
    int count = 0;
    Stack stk;

    cout << "Enter the expression: ";
    gets(arr);

    cout << "Expression is: " << puts(arr);
    
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[' )
        {
            if (arr[i] == '(')
            {
                stk.push(')');
                count++;
            }
            if (arr[i] == '{')
            {
                stk.push('}');
                count++;
            }
            if (arr[i] == '[')
            {
                stk.push(']');
                count++;
            }
        }
        if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']' )
        {
            if (arr[i] == stk.top())
            {
                stk.pop();
                count--;
            }
            else
            {
                cout << "Expression is invalid!";
                return 0;
            }
        }
    }
    if (count == 0)
    {
        cout << "Expression is Valid";
    }
    else
    {
        cout << "Expression is invalid!";
    }
    
    return 0;
}