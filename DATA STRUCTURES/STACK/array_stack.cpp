//This program implements the Stack Data Structure using Array
#include<iostream>
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
        this->_max = 5;
    }
    Stack(int size)
    {
        this->_top = -1;
        this->_max = size;
    }

    int isEmpty()   //returns true if Stack is empty else false
    {
        if (_top == -1)
        {
            return 1;
        }
        return 0;
    }

    int isFull()    //returns true if Stack is full else false
    {
        if (_top == _max-1)
        {
            return 1;
        }
        return 0;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            _top++;
            _stk[_top] = data;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n"; 
        }
        else
        {
            _top--;
        }
    }

    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return _stk[_top];
    }

    int size()  //returns the size of the Stack
    {
        return (_top+1);
    }

    void printStack()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "\nContent in Stack is: \n";
        for (int i = _top; i >= 0 ; i--)
        {
            cout << "|" << _stk[i] << "|" << "\n";
        }
    }
};

int main()
{
    Stack stk;
    
    int ch, data;
    while(1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Top\n");
        printf("5. Size\n");
        printf("6. Exit\nEnter your Choice: ");
        scanf("%d",&ch); 

		switch(ch)
		{   
			case 1: cout << "Enter data into the Stack: ";
                    cin >> data;
                    stk.push(data); break;
			case 2: stk.pop(); break;
			case 3: stk.printStack(); break;
            case 4: cout << stk.top(); break;
            case 5: cout << stk.size(); break;          
			case 6: exit(0); break;
			default : printf("\nInvalid choice\n");
		}
    }

    return 0;
}