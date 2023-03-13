#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class binarySearchTree
{
    public:
        Node *root;

        binarySearchTree()
        {
            this->root = NULL;
        }

        void buildBST() //build BST iteratively
        {
            int data;

            cout << "Enter data for root: ";
            cin >> data;

            if (data == -1)
            {
                return;
            }
            root = new Node(data);

            while (true)
            {
                cout << "\nEnter data for next node: ";
                cin >> data;
                if (data == -1)
                {
                    return;
                }
                
                Node *temp = root;
                while (temp != NULL)
                {
                    if ((temp->data > data) && (temp->left != NULL))
                    {
                        temp = temp->left;
                    }
                    if ((temp->data < data) && (temp->right != NULL))
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        break;
                    }
                }
                if (temp->data > data)
                {
                    temp->left = new Node(data);
                }
                else
                {
                    temp->right = new Node(data);
                }
            }
        }

        void buildBST(Node *&root, int data)
        {
            if (root == NULL)
            {
                root = new Node(data);
                return;
            }
            if (data < root->data)
            {
                buildBST(root->left, data);
            }
            else
            {
                buildBST(root->right, data);
            }
        }

        void buildBSTRecursively()  //build BST recusively
        {
            int data;
            cout << "\nEnter data into BST: ";
            cin >> data;

            while (data != -1)
            {
                buildBST(root, data);
                cout << "\nEnter data into BST: ";
                cin >> data;
            }
            
        }

        void inorderTraversal(Node *root)
        {
            if (root == NULL)
            {
                return;
            }
            inorderTraversal(root->left);
            cout << root->data << "    ";
            inorderTraversal(root->right);
        }

        void preorderTraversal(Node *root)
        {
            if (root == NULL)
            {
                return;
            }
            cout << root->data << "    ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }

        void postorderTraversal(Node *root)
        {
            if (root == NULL)
            {
                return;
            }
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << "    ";
        }

        void levelOrdedtraversal()
        {
            queue <Node *>q;
            q.push(root);
            q.push(NULL);

            while (!q.empty())
            {
                Node *temp = q.front();
                q.pop();

                if (temp == NULL)
                {
                    cout << "\n";
                    if (!q.empty())
                    {
                        q.push(NULL);
                    }
                }
                else
                {
                    cout << temp->data << "    ";

                    if (temp->left)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
        }

        void insertIntoBST()
        {
            int data;
            cout << "\nEnter data you want to insert into BST: ";
            cin >> data;

            buildBST(root, data);
        }

        bool searchInBST(Node *root, int val)   //search in BST using Binary Search logic, implementing recursively
        {
            if (root == NULL)
            {
                return false;
            }
            if (root->data == val)
            {
                return true;
            }
            if (root->data > val)
            {
                return searchInBST(root->left, val);
            }
            else
            {
                return searchInBST(root->right, val);
            }
        }

        bool searchInBST(int val)   //search in BST iteratively
        {
            Node *temp = root;
            while (temp)
            {
                if (temp->data == val)
                {
                    return true;
                }
                if (temp->data > val)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return false;
        }

        void findMin()
        {
            Node *temp = root;
            while (temp != NULL && temp->left != NULL)
            {
                temp = temp->left;
            }
            if (temp)
            {
                cout << "Minimum value in the BST is: " << temp->data;
                return;
            }
            cout << "Tree is empty\n";
        }

        void findMax()
        {
            Node *temp = root;
            while (temp != NULL && temp->left != NULL)
            {
                temp = temp->right;
            }
            if (temp)
            {
                cout << "Maximum value in the BST is: " << temp->data;
                return;
            }
            cout << "Tree is empty\n";
        }

        Node *p, *s;
        void iot(Node *root, int data) //this inorder traversal(iot) finds inorder predecessor & successor of given 'data'
        {
            if(root == NULL) return;
            iot(root->left, data);
            if((root->data > data) && s == NULL)
            {
                s = root;
            }
            if(root->data < data)
            {
                p = root;
            }
            iot(root->right, data);
        }
        void findPredecessorSuccessor(Node* root)
        {
            p = NULL, s = NULL;
            int key;
            cout << "\nEnter data to find inorder predecessor and successor of: ";
            cin >> key;
            iot(root, key);
            cout << "\nInorder predecessor of " << key << " is ";
            if (p)
            {
                cout << p->data;
            }
            else
            {
                cout << -1;
            }
            cout << "\nInorder successor of " << key << " is ";
            if (s)
            {
                cout << s->data;
            }
            else
            {
                cout << -1;
            }
        }
        
        Node *ans;
        void iot(Node *root, Node *x)   //this iot function finds inorder successor of given node with time complexity O(H)
        {
            if(root == NULL)
            {
                return;
            }
            if(root->data > x->data)
            {
                ans = root;
                iot(root->left, x);
            }
            if(root->data <= x->data)
            {
                iot(root->right, x);
            }
        }
        void inOrderSuccessor(Node *root, Node *x)
        {
            ans = NULL;
            iot(root ,x);
            cout << "Inorder Successor of " << x->data << " is " << ans->data;
            return;
        }

        Node *minVal(Node *root) //function that finds the minimum value for deleteNode function
        {
            if(root == NULL)
            {
                return NULL;
            }
            if(root->left == NULL && root->right == NULL)
            {
                return root;
            }
            return minVal(root->left);
        }
        // Function to delete a node from BST.
        Node *deleteNode(Node *root, int X) 
        {
            if(root == NULL)
            {
                return root;
            }
            if(root->data == X)
            {
                if(root->left == NULL && root->right == NULL)
                {
                    Node *temp = root;
                    root = NULL;
                    delete temp;
                    return root;
                }
                else if(root->left != NULL && root->right == NULL)
                {
                    Node *temp = root;
                    root = root->left;
                    delete temp;
                    return root;
                }
                else if(root->left == NULL && root->right != NULL)
                {
                    Node *temp = root;
                    root = root->right;
                    delete temp;
                    return root;
                }
                else
                {
                    Node *min = minVal(root->right);
                    root->data = min->data;
                    root->right = deleteNode(root->right, min->data);
                    return root;
                }
            }
            else if(root->data > X)
            {
                root->left = deleteNode(root->left, X);
                return root;
            }
            else
            {
                root->right = deleteNode(root->right, X);
                return root;
            }
        }

        void countTotalLevel(Node *root)
        {
            queue <Node *>q;
            q.push(root);
            q.push(NULL);
            int count = 0;
            while(!q.empty())
            {
                Node *temp = q.front();
                q.pop();
                if(temp)
                {
                    if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                }
                else
                {
                    count++;
                    if(!q.empty())
                    {
                        q.push(NULL);
                    }
                }
            }
            cout << "Total nodes in the BST: " << count;
        }
};


int main()
{
    binarySearchTree bst;
    bst.buildBSTRecursively();
    // bst.buildBST();

    cout << "\nData in the Tree: ";
    bst.inorderTraversal(bst.root);

    cout << "\nData in the Tree: \n";
    bst.levelOrdedtraversal();

    // bst.insertIntoBST();

    // cout << "\nData in the Tree: \n";
    // bst.levelOrdedtraversal();

    // int data;
    // cout << "\nEnter data to search: ";
    // cin >> data;
    // cout << bst.searchInBST(bst.root, data);
    // cout << "\nEnter data to search: ";
    // cin >> data;
    // cout << bst.searchInBST(data);

    // bst.findMin();
    // bst.findMax();
    // bst.findPredecessorSuccessor(bst.root);

    bst.deleteNode(bst.root, 3);
    cout << "\nData in the Tree: \n";
    bst.levelOrdedtraversal();

    bst.countTotalLevel(bst.root);

    return 0;
}