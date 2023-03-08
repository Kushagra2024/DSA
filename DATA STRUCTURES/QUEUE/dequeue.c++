#include<iostream>
using namespace std;

class Deque
{
    int _arr[100];
    int _front;
    int _rear;
    int _max;

    public:
        Deque()
        {
            _front = -1;
            _rear = -1;
            _max = 5;
        }
        Deque(int size)
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
            if (_front == (_rear+1)%_max)
            {
                return 1;
            }
            return 0;
        }

        void pushBack(int data)
        {
            if (isFull())
            {
                cout << "Queue Overflow\n";
                return;
            }
            if (isEmpty())
            {
                _front = 0;
            }
            _rear++;
            _arr[_rear] = data;
        }

        void pushFront(int data)
        {
            if (isFull())
            {
                cout << "Queue Overflow\n";
                return;
            }
            else if (isEmpty())
            {
                _rear = 0;
                _front = 0;
                _arr[_front] = data;
                return;
            }
            if (_front == 0)
            {
                _front = _max;
            }
            _front--;
            _arr[_front] = data;
        }

        void popFront()
        {
            if (isEmpty())
            {
                cout << "Queue Empty\n";
            }
            if (_rear == _front)
            {
                _rear = -1;
                _front = -1;
            }
            _front++;
        }

        void popBack()
        {
            if (isEmpty())
            {
                cout << "Queue Empty\n";
            }
            else if (_rear == _front)
            {
                _rear = -1;
                _front = -1;
            }
            if (_rear == 0)
            {
                _rear = _max;
            }
            _rear--;
        }

        int back()
        {
            if (isEmpty())
            {
                cout << "Queue Empty\n";
                return -1;
            }
            return _arr[_rear];
        }

        int front()
        {
            if (isEmpty())
            {
                cout << "Queue Empty\n";
                return -1;
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
                cout << "Queue Empty\n";
            }
            for (int i = _front; i != _rear; i = (i+1)%_max)
            {
                cout << _arr[i] << "|";
            }
            cout << _arr[_rear] << "|";
        }
};

int main()
{
    Deque que;
    
    int ch, data;
    while(1)
    {
        printf("\n1. Push_Back\n");
        printf("2. Push_Front\n");
        printf("3. Pop_Back\n");
        printf("4. Pop_Front\n");
        printf("5. Display\n");
        printf("6. Back\n");
        printf("7. Front\n");
        printf("8. Size\n");
        printf("9. Exit\nEnter your Choice: ");
        scanf("%d",&ch); 

		switch(ch)
		{   
			case 1: cout << "Enter data into the Queue: ";
                    cin >> data;
                    que.pushBack(data); break;
			case 2: cout << "Enter data into the Queue: ";
                    cin >> data;
                    que.pushFront(data); break;
			case 3: que.popBack(); break;
			case 4: que.popFront(); break;
			case 5: que.printqueue(); break;
            case 6: cout << que.back(); break;
            case 7: cout << que.front(); break;
            case 8: cout << que.size(); break;          
			case 9: exit(0); break;
			default : printf("\nInvalid choice\n");
		}
    }

    return 0;
}