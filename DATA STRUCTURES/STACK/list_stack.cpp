//This program implements the Stack Data Structure using Linked List
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }
    Node(int data, Node *nxt = NULL)
    {
        this->data = data;
        this->next = nxt;
    }
};

class Stack
{
    Node *_top;

public:
    Stack()
    {
        this->_top = NULL;
    }
    ~Stack()
    {
        Node *temp = _top;
        while (_top != NULL)
        {
            _top = _top->next;
            delete temp;
            temp = _top;
        }
        
    }

    int isEmpty()   //returns true if Stack is empty else false
    {
        if (_top == NULL)
        {
            return 1;
        }
        return 0;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        if (temp == NULL)
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            //implemented through addbeg
            temp->next = _top;
            _top = temp;
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
            //implemented through delbeg
            Node *ptr = _top;
            _top = _top->next;
            delete ptr;
        }
    }

    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return _top->data;
    }

    int size()  //returns the size of the Stack
    {
        int count = 0;
        Node *tptr = _top;
        while (tptr != NULL)
        {
            count++;
            tptr = tptr->next;
        }
        return count;
    }

    void printStack()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "\nContent in Stack is: \n";
        Node *tptr = _top;
        while (tptr != NULL)
        {
            cout << "|" << tptr->data << "|" << "\n";
            tptr = tptr->next;
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