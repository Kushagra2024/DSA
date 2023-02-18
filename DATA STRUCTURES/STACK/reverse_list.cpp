//This program reverses list using Stack
#include<iostream>
using namespace std;

class Stack
{
    int stk[10];
    int top;
    int max;

public:
    Stack()
    {
        this->top = -1;
        this->max = 10;
    }
    Stack(int max)
    {
        this->top = -1;
        this->max = max;
    }
    int isEmpty()
    {
        if(top == -1)
        {
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if (top == max-1)
        {
            return 1;
        }
        return 0;
    }
    void push(int data)
    {
        if (isFull())
        {
            return;
        }
        this->stk[++top] = data;
    }
    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        return(stk[top--]);
    }
};

int main()
{
    int arr[100], num;
    Stack stk;
    cout << "Enter number of Elements in array: ";
    cin >> num;

    cout << "Enter Number: ";
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    cout << "Number: ";
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << "\t";
    }

    for (int i = 0; i < num; i++)
    {
        stk.push(arr[i]);
    }

    for (int i = 0; i < num; i++)
    {
        arr[i] = stk.pop();
    }

    cout << "\nNumber in Reverse Order: ";
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << "\t";
    }

    return 0;
}