#include<iostream>
using namespace std;

class C_Queue
{
    int _arr[100];
    int _front;
    int _rear;
    int _max;

public:
    C_Queue()
    {
        _front = -1;
        _rear = -1;
        _max = 5;
    }
    C_Queue(int size)
    {        
        _front = -1;
        _rear = -1;
        _max = size;
    }

    int isEmpty()
    {
        if (_rear == -1 && _front == -1)
        {
            return 1;
        }
        return 0;
    }
    
    int isFull()
    {
        if ((_rear+1)%_max == _front)
        {
            return 1;
        }
        return 0;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }
        if (_rear == -1 && _front == -1)
        {
            _front = 0;
        }
        _rear = (_rear+1)%_max;
        _arr[_rear] = data;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }
        if (_rear == _front)
        {
            _rear = -1;
            _front = -1;
            return;
        }
        _front = (_front+1)%_max;
    }

    int back()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow";
            return;
        }
        return _arr[_rear];
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow";
            return;
        }
        return _arr[_front];
    }

    int size()
    {
        int count = 0;
        if (isEmpty())
        {
            return count;
        }
        for (int i = _rear; i != _front; i = (i+1)%_max)
        {
            count++;
        }
        return count+1;
    }

    void printqueue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow";
            return;
        }
        cout << "\nContent in Queue is: \n|";
        for (int i = _front; i != _rear; i = (i+1)%_max)
        {
            cout << _arr[i] << "|";
        }
        cout << _arr[_rear] << "|";
        
    }
};

int main()
{
    C_Queue que;
    
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