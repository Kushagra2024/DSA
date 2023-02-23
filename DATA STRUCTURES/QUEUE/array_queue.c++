#include<iostream>
using namespace std;

class Queue
{
    int _queue[100];
    int _rear;
    int _front;
    int _max;

public:
    Queue()
    {
        _front = -1;
        _rear = -1;
        _max = 5;
    }
    Queue(int size)
    {
        _front = -1;
        _rear = -1;
        _max = size;
    }

    int isEmpty()
    {
        if (_front == -1 && _rear == -1)
        {
            return 1;
        }
        return 0;
    }

    int isFull()
    {
        if (_rear == _max-1)
        {
            return 1;
        }
        return 0;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }
        if (isEmpty())
        {
            _rear = 0;
            _front = 0;
        }
        else
        {
            _rear++;
        }
        _queue[_rear] = data;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        if (_rear == _front)
        {
            _rear =_front = -1;
        }
        else
        {
            _front++;
        }
    }

    int back()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return _queue[_rear];
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return _queue[_front];
    }

    int size()
    {
        if (isEmpty())
        {
            return 0;
        }
        return(_rear-_front+1);
    }

    void printqueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "\nContent in Queue is: \n|";
        for (int i = _front; i < _rear+1; i++)
        {
            cout <<_queue[i] << "|";
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