#include<iostream>
using namespace std;

class Node
{
public:
    int _data;
    Node *_next;

    Node()
    {
        this->_next = NULL;
    }
    Node(int info, Node *nxt = NULL)
    {
        this->_data = info;
        this->_next = nxt;
    }
};

class Queue
{
    Node *_rear;
    Node *_front;

public:
    Queue()
    {
        this->_rear = NULL;
        this->_front = NULL;
    }
    ~Queue()
    {
        Node *tptr = _front;
        while (tptr != NULL)
        {
            tptr = tptr->_next;
            delete _front;
        }
        _front = NULL, _rear = NULL;
    }

    int isEmpty()
    {
        if (_front == NULL && _rear == NULL)
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
            cout << "Queue is Full\n";
            return;
        }
        if (_rear == NULL && _rear == NULL)
        {
            _rear = temp;
            _front = temp;
        }
        else
        {
            _rear->_next = temp;
            _rear = temp;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        Node *ptr = _front;
        if (_rear == _front)
        {
            _rear = NULL;
        }
        _front = _front->_next;
        delete ptr;
    }

    int back()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return _rear->_data;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return _front->_data;
    }

    int size()
    {
        int count = 0;
        Node *tptr = _front;
        while (tptr != NULL)
        {
            tptr = tptr->_next;
            count++;
        }
        return count;
    }

    void printqueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "\nContent in Queue is: \n|";
        Node *tptr = _front;
        while (tptr != NULL)
        {
            cout << tptr->_data << "|";
            tptr = tptr->_next;
        }
    }
};

int main()
{
    Queue que;
    
    int ch, data;
    while(1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Back\n");
        printf("5. Front\n");
        printf("6. Size\n");
        printf("7. Exit\nEnter your Choice: ");
        scanf("%d",&ch); 

		switch(ch)
		{   
			case 1: cout << "Enter data into the Queue: ";
                    cin >> data;
                    que.push(data); break;
			case 2: que.pop(); break;
			case 3: que.printqueue(); break;
            case 4: cout << que.back(); break;
            case 5: cout << que.front(); break;
            case 6: cout << que.size(); break;          
			case 7: exit(0); break;
			default : printf("\nInvalid choice\n");
		}
    }

    return 0;
}