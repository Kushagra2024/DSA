#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
    public:
        Node *prev;
        int data;
        Node *next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
        this->data = data;
    }
    Node(int data, Node *next = NULL, Node *prev = NULL)
    {
        this->prev = prev;
        this->next = next;
        this->data = data;
    }
};

class SDLL
{
    Node *_head;

    public:
        SDLL()
        {
            this->_head = NULL;
        }
        ~SDLL()
        {
            while (_head != NULL)
            {
                Node *ptr = _head;
                _head = _head->next;
                delete ptr;
            }
        }

        void addbeg(int data)
        {
            Node *temp = new Node(data, _head);
            if (_head != NULL)
            {
                _head->prev = temp;
            }
            _head = temp;
        }

        void delbeg()
        {
            if (_head == NULL)
            {
                cout << "Linkedlist Empty\n";
                return;
            }
            Node *ptr = _head;
            _head = _head->next;
            if (_head != NULL)
            {
                _head->prev = NULL;
            }
            delete ptr;
        }

        void addlast(int data)
        {
            if (_head == NULL)
            {
                addbeg(data);
                return;
            }
            Node *tptr = _head;
            while (tptr->next != NULL)
            {
                tptr = tptr->next;
            }
            Node *temp = new Node(data, NULL, tptr);
            tptr->next = temp;
        }

        void dellast()
        {
            if (_head == NULL)
            {
                cout << "Linkedlist Empty\n";
                return;
            }
            if (_head->next == NULL)
            {
                Node *ptr = _head;
                _head = NULL;
                delete ptr;
            }
            Node *tptr = _head;
            while (tptr->next != NULL)
            {
                tptr = tptr->next;
            }
            tptr->prev->next = NULL;
            delete tptr;
        }

        void delnode(int val)
        {
            if (_head == NULL)
            {
                cout << "Linkedlist Empty\n";
                return;
            }
            while (_head != NULL && _head->data == val)
            {
                delbeg();
            }
            Node *tptr = _head;
            while (tptr != NULL && tptr->next != NULL)
            {
                if (tptr->next->data == val)
                {
                    Node *ptr = tptr->next;
                    tptr->next = tptr->next->next;
                    if (tptr->next->next != NULL)
                    {
                        tptr->next->next->prev = tptr;
                    }
                    delete ptr;
                }
            }
        }

        void ispresent(int val)
        {
            if (_head == NULL)
            {
                cout << "Linkedlist Empty\n";
                return;
            }
            Node *tptr = _head;
            while (tptr != NULL)
            {
                if (tptr->data == val)
                {
                    cout << "Data found\n";
                    return;
                }
                tptr = tptr->next;
            }
            cout << "Data not present\n";
        }
        
        void insertafter(int info, int val)
        {
            if (_head == NULL)
            {
                cout << "Linkedlist Empty\n";
                return;
            }
            Node *tptr = _head;
            while (tptr != NULL)
            {
                if (tptr->data == val)
                {
                    Node *temp = new Node(info, tptr->next, tptr);
                    if (tptr->next != NULL)
                    {
                    tptr->next->prev = temp;
                    }
                    tptr->next = temp;
                }
                tptr = tptr->next;
            }
        }

        void insertbefore(int info, int val)
        {
            if (_head == NULL)
            {
                cout << "Linkedlist Empty\n";
                return;
            }
            if (_head->data == val)
            {
                addbeg(info);
            }
            Node *tptr = _head;
            while (tptr->next != NULL)
            {
                if (tptr->next->data == val)
                {
                    Node *temp = new Node(info, tptr->next, tptr);
                    tptr->next->prev = temp;
                    tptr->next =  temp;
                }
                tptr = tptr->next;
            }
        }
        
        int countnode()
        {
            int count = 0;
            Node *tptr = _head;
            while (tptr != NULL)
            {
                count++;
                tptr = tptr->next;
            }
            return count;
        }

        void printlist()
        {
            if (_head == NULL)
            {
                cout << "Linkedlist Empty\n";
                return;
            }
            Node *tptr = _head;
            cout << "Data in the Linkedlist: ";
            while (tptr != NULL)
            {
                cout << tptr->data << "\t";
                tptr = tptr->next;
            }
        }
};

int main()
{
    SDLL list;
    int ch, data, val;
    while (1)
    {
        cout << "\n*********************************************************************************************\n";
        cout << "\n1.The new node is inserted at the beginning.\n2.The new node is inserted at the end.\n3.Delete the first node.\n4.Delete the last node.\n5.Delete a given node.\n6.The new node is inserted after a given node.\n7.The new node is inserted before a given node.\n8.Print the number of nodes in a linked list.\n9.Searching for a Value in a Linked List.\n10. Display\n11. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter data in List: ";
            cin >> data;
            list.addbeg(data);
            break;
        case 2:
            cout << "\nEnter data in List: ";
            cin >> data;
            list.addlast(data);
            break;
        case 3:
            list.delbeg();
            break;
        case 4:
            list.dellast();
            break;
        case 5:
            cout << "\nValue to be deleted: " ;
            cin >> data;
            list.delnode(data);
            break;
        case 6:
            cout << "\nEnter data in the List: " ;
            cin >> data;
            cout << "\nEnter value after which to insert: " ;
            cin >> val;
            list.insertafter(val,data);
            break;
        case 7:
            cout << "\nEnter data in the List: " ;
            cin >> data;
            cout << "\nEnter value before which to insert: " ;
            cin >> val;
            list.insertbefore(val,data);
            break;
        case 8:
            cout << "\nNo of nodes in the List: " << list.countnode();
            break;
        case 9:
            cout << "\nEnter value to search: " ;
            cin >> data;
            list.ispresent(data);
            break;
        case 10:
            cout << "\nData in the List: ";
            list.printlist();
            break;
        case 11:
            exit(0);
        default:
            cout << "Invalid Choice!\n";
            break;
        }
    }
    return 0;
}