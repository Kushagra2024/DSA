#include<iostream>
#include<stdlib.h>
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

    Node(int info, Node *nxt = NULL)
    {
        this->data = info;
        this->next = nxt;
    }
};

class SCLL
{
    Node *_head;

public:
    SCLL()
    {
        _head = NULL;
    }
    ~SCLL()
    {
        Node *tptr = _head;
        while (tptr != NULL)
        {
            _head = _head->next;
            delete tptr;
            tptr = _head;
        }
        cout << "List Deleted!";
    }

    void addbeg(int info)
    {
        Node *temp = new Node(info);
        if (_head == NULL)
        {
            _head = temp;
            _head->next = _head;
        }
        else
        {
            temp->next = _head;
            Node *tptr = _head;
            while (tptr->next != _head)
            {
                tptr = tptr->next;
            }
            tptr->next = temp;
            _head = temp;
        }
    }

    void addlast(int info)
    {
        if (_head == NULL)
        {
            addbeg(info);
        }
        else
        {
            Node *temp = new Node(info);
            Node *tptr = _head;
            while (tptr->next != _head)
            {
                tptr = tptr->next;
            }
            tptr->next = temp;
            temp->next = _head;
        }
    }

    void delbeg()
    {
        if (_head == NULL)
        {
            cout << "List empty!\n";
            return;
        }
        else
        {
            if (_head->next == _head)
            {
                delete _head;
                _head = NULL;
            }
            else
            {
                Node *tptr1 = _head, *tptr2 = _head;
                while (tptr2->next != _head)
                {
                    tptr2 = tptr2->next;
                }
                _head = _head->next;
                delete tptr1;
                tptr2->next = _head;
            }
        }
    }

    void dellast()
    {
        if (_head == NULL)
        {
            cout << "List empty!\n";
            return;
        }
        else
        {
            if (_head->next == _head)
            {
                delete _head;
                _head = NULL;
            }
            else
            {
                Node *tptr = _head;
                while (tptr->next->next != _head)
                {
                    tptr = tptr->next;
                }
                delete tptr->next;
                tptr->next = _head;
            }
        }
    }

    void delnode(int val)
    {
        if (_head == NULL)  //logic for if list is empty
        {
            cout << "List empty!\n";
            return;
        }
        while (_head->data == val)  //logic that checks for first node
        {
            delbeg();
        }
        Node *tptr = _head;
        while (tptr != NULL && tptr->next != _head) //logic that check for rest of the node
        {
            if (tptr->next->data == val)
            {
                Node *ptr = tptr->next;
                tptr->next = ptr->next;
                delete ptr;
            }
            else
            {
                tptr = tptr->next;
            }
        }
    }

    bool ispresent(int val)
    {
        if (_head == NULL)
        {
            cout << "List empty!\n";
            return false;
        }
        Node *tptr = _head;
        while (tptr->next != _head)
        {
            if (tptr->data == val)
            {
                return true;
            }
            tptr = tptr->next;
        }
        if (tptr->data == val)
        {
            return true;
        }
        return false;
    }

    int countnode()
    {
        int count = 0;
        Node *tptr = _head;
        while (tptr != NULL && tptr->next != _head)
        {
            count++;
            tptr = tptr->next;
        }
        if (tptr == NULL)
        {
            return 0;
        }
        return ++count;
        
    }

    void printList()
    {

        if (_head == NULL)
        {
            cout << "List empty!\n";
            return;
        }
        Node *tptr = _head;
        while (tptr->next != _head)
        {
            cout << tptr->data << "\t";
            tptr = tptr->next;
        }
        cout << tptr->data;
    }

};


int main()
{
    SCLL list;
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
            // list.insertafter(val,data);
            break;
        case 7:
            cout << "\nEnter data in the List: " ;
            cin >> data;
            cout << "\nEnter value before which to insert: " ;
            cin >> val;
            // list.insertbefore(val,data);
            break;
        case 8:
            cout << "\nNo of nodes in the List: " << list.countnode();
            break;
        case 9:
            cout << "\nEnter value to search: " ;
            cin >> data;
            cout << list.ispresent(data);
            break;
        case 10:
            cout << "\nData in the List: ";
            list.printList();
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