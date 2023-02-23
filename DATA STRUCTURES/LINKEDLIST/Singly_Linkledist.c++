#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Node
{
public:
    //Data Member
    int data;
    Node *nxt;

    //Constructors
    Node()   //default
    {
        this->nxt = NULL;
    }
    Node(int info, Node *nxt = NULL)  //parameterized
    {
        this->data = info;
        this->nxt = nxt;
    }

};

class SLL
{
    Node *_head;

public:
    SLL()
    {
        _head = NULL;
    }
    ~SLL()
    {
        Node *tptr = _head;
        while (_head != NULL)
        {
            _head = _head->nxt;
            delete tptr;
            tptr = _head;
        }
        cout << "\nList Deleted\n";
    }
    
    void addbeg(int info)
    {
        Node *tempNode = new Node(info, _head);
        _head = tempNode;
    }
    void addlast(int info)
    {
        if (_head == NULL)
        {
            addbeg(info);
        }
        else
        {
            Node *tPtr  = _head;
            Node *temp = new Node(info);
            while (tPtr->nxt != NULL)
            {
                tPtr = tPtr->nxt;
            }
            tPtr->nxt = temp;
        }
    }
    void delbeg()
    {
        if (_head == NULL)
        {
            cout << "List empty\n";
            return;
        }
        else
        {
            Node *tptr = _head;
            cout << "Data deleted: " << tptr->data << endl;
            _head = _head->nxt;
            delete tptr;
        }
    }
    void dellast()
    {
        if (_head == NULL)
        {
            cout << "List Empty\n";
            return;
        }
        Node *tptr1 = _head, *tptr2 = NULL;
        if (tptr1->nxt == NULL)
        {
            cout << "Data deleted: " << tptr1->data << endl;
            delete tptr1;
            _head = NULL;
            return;
        }
        while (tptr1->nxt != NULL)
        {
            tptr2 = tptr1;
            tptr1 = tptr1->nxt;
        }
        cout << "Data deleted: " << tptr1->data << endl;
        delete tptr1;
        tptr2->nxt = NULL;
    }
    void delnode(int val)
    {
        if (_head == NULL)
        {
            cout << "List Empty\n";
            return;
        }
        else
        {
            //Checks for Head(1st node)
            while (_head != NULL && _head->data == val)
            {
                delbeg();
            }
            //Checks for rest of the node
            Node *tptr = _head, *temp;
            while (tptr != NULL && tptr->nxt != NULL)
            {
                if (tptr->nxt->data == val)
                {
                    temp = tptr->nxt;
                    cout << "Data deleted: " << temp->data << endl;
                    tptr->nxt = temp->nxt;
                    delete temp;
                }
                else
                {
                    tptr = tptr->nxt;
                }
            }
        }
    }
    void ispresent(int val)
    {
        if (_head == NULL)
        {
            cout << "List Empty!\n";
            return;
        }
        Node *tptr = _head;
        int count = 0;
        while (tptr != NULL)
        {
            count++;
            if(tptr->data == val)
            {
                cout << "Data present at: " << count << "index.";
            }
            tptr = tptr->nxt;
        }
    }
    void insertbefore(int val, int info)
    {
        if (_head == NULL)
        {
            cout << "List Empty!\n";
            return;
        }
        else
        {
            //checks for head/1st idex
            if (_head->data == val)
            {
                addbeg(info);
                return;
            }
            Node *tptr = _head;
            while (tptr->nxt != NULL && tptr->nxt->data != val)
            {
                tptr = tptr->nxt;
            }
            if (tptr->nxt != NULL)
            {
                Node *temp = new Node(info,tptr->nxt);
                tptr->nxt = temp;
            }
        }
    }
    void insertafter(int val, int info)
    {
        if (_head == NULL)
        {
            cout << "List Empty!\n";
            return;
        }
        else
        {
            Node *tptr = _head;
            while (tptr != NULL && tptr->data != val)
            {
                tptr = tptr->nxt;
            }
            if (tptr != NULL)
            {
                Node *temp = new Node(info, tptr->nxt);
                tptr->nxt = temp;
            }
        }
    }
    int countnode()
    {
        int count = 0;
        Node *tptr = _head;
        while (tptr != NULL)
        {
            count++;
            tptr = tptr->nxt;
        }
        return count;
    }
    void printlist()
    {
        if (_head == NULL)
        {
            cout << "\n\nList Empty\n";
            return;
        }
        Node *tptr = _head;
        while (tptr != NULL)
        {
            cout << tptr->data << "\t";
            tptr = tptr->nxt;
        }
    }
};

int main()
{
    SLL list;
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