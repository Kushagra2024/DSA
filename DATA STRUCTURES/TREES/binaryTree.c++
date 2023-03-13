#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        left = NULL;
        right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class binaryTree
{
    public:
        Node *root;

        binaryTree()
        {
            this->root = NULL;
        }

        Node * buildTree(Node *root)
        {
            int data;
            cout << "Enter data in the node: " << endl;
            cin >> data;

            root = new Node(data);
            if (data == -1)
            {
                return NULL;
            }
            cout << "Enter data in the left of " << data << endl;
            root->left = buildTree(root->left);
            cout << "Enter data in the right of " <<data << endl;
            root->right = buildTree(root->right);

            return root;
        }

        void buildTreefromlevelOrder(Node * &root)
        {
            queue <Node *> q;

            int data;
            cout << "Enter data for root: ";
            cin >> data;
            if (data == -1)
            {
                root = NULL;
                return;
            }
            else
            {
                root = new Node(data);
            }
            q.push(root);
            while (!q.empty())
            {
                Node *temp = q.front();
                q.pop();

                int leftdata;
                cout << "Enter left node for: " << temp->data << endl;
                cin >> leftdata;

                if (leftdata != -1)
                {
                    temp->left = new Node(leftdata);
                    q.push(temp->left);
                }

                int rightdata;
                cout << "Enter right node for: " << temp->data << endl;
                cin >> rightdata;

                if (rightdata != -1)
                {
                    temp->right = new Node(rightdata);
                    q.push(temp->right);
                }
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

        void iterative_inorderTraversal()
        {
            stack <Node *> s;
            Node *temp = this->root;
            while (true)
            {
                if (temp)
                {
                    s.push(temp);
                    temp = temp->left;
                }
                else
                {
                    if (s.empty())
                    {
                        break;
                    }
                    temp = s.top();
                    cout << s.top()->data << "    ";
                    s.pop();
                    temp = temp->right;
                }
            }
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

        void iterative_preorderTraversal()
        {
            stack <Node *> s;
            Node *temp = this->root;
            while (true)
            {
                if (temp)
                {
                    s.push(temp);
                    cout << s.top()->data << "    ";
                    temp = temp->left;
                }
                else
                {
                    if (s.empty())
                    {
                        break;
                    }
                    temp = s.top();
                    s.pop();
                    temp = temp->right;
                }
            }
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

        // void iterative_postorderTraversal()
        // {
        //     stack <Node *> s;
        //     Node *temp = this->root;
        //     while (true)
        //     {
        //         if (temp)
        //         {
        //             s.push(temp);
        //             temp = temp->left;
        //         }
        //         else
        //         {
        //             if (s.empty())
        //             {
        //                 break;
        //             }
        //             temp = s.top();
        //             cout << s.top()->data << "    ";
        //             s.pop();
        //             temp = temp->right;
        //         }
        //     }
        // }

        void levelorderTraversal()
        {
            queue <Node *> q;
            q.push(this->root); //push 1st node in the queue
            q.push(NULL);       //push delimeter of 1st level

            while (!q.empty())
            {
                Node *temp = q.front();
                q.pop();

                if (temp == NULL)   //if delimeter is encountered, it means a level of tree is completed, hence print newline 
                {
                    cout << endl;
                    if (!q.empty()) //and if queue is not empty it means all nxt level nodes are pushed
                    {
                        q.push(NULL);
                    }
                }
                else
                {
                    cout << temp->data << " ";
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

        void rev_levelordertraversal()
        {
            queue <Node *> q;
            stack <Node *> s;

            q.push(this->root);
            q.push(NULL);

            while (!q.empty())
            {
                Node *temp = q.front();
                q.pop();

                if (temp == NULL)
                {
                    s.push(NULL);
                    if (!q.empty())
                    {
                        q.push(NULL);
                    }
                }
                else
                {
                    s.push(temp);
                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                    if (temp->left)
                    {
                        q.push(temp->left);
                    }
                }
            }
            while (!s.empty())
            {
                if (s.top())
                {
                    cout << s.top()->data << " ";
                }
                else
                {
                    cout << endl;
                }
                s.pop();
            }
        }

        int countTotalNode(Node *root)
        {
            if (root == NULL)
            {
                return 0;
            }
            return(countTotalNode(root->left) + countTotalNode(root->right) + 1);
        }

        int countLeafNode(Node *root)
        {
            if (root == NULL)
            {
                return 0;
            }
            if (root->left == NULL && root->right == NULL)
            {
                return 1;
            }
            return(countLeafNode(root->left) + countLeafNode(root->right));
        }

        int countInternalnode(Node *root)
        {
            if ((root == NULL) || (root->left == NULL && root->right == NULL))
            {
                return 0;
            }
            return (countInternalnode(root->left) + countInternalnode(root->right) + 1);
        }

        int height(Node *root)
        {
            if (root == NULL)
            {
                return 0;
            }
            if (root->left == NULL && root->right == NULL)
            {
                return 1;
            }
            return (max(height(root->left), height(root->right))+1);
        }

        //Time complexity of this function is less than that of written below
        //pair = {diameter, height}
        pair <int, int> diameterFast(Node *root)
        {
            if (root == NULL)   //storing diamteter and height 0,0 as no tree exits;
            {
                pair <int, int> ans = make_pair(0,0);
                return ans;
            }
            if (root->left == NULL && root->right == NULL)   //storing diamteter and height 1,1 as  only 1 node exits;
            {
                pair <int, int> ans = make_pair(1,1);
                return ans;
            }
            pair <int, int> left = diameterFast(root->left);    //storing info of left subtree
            pair <int, int> right = diameterFast(root->right);  //storing info of right subtree

            int op1 = left.first;   //op1 stores diameter of left subtree
            int op2 = right.first;  //op2 stores diameter of right subtree
            int op3 = left.second + right.second + 1;   //op3 stores height of left subtree and right subtree + root

            pair <int, int> ans;
            ans.first = max(max(op1, op2), op3);
            ans.second = max(left.second, right.second)+1;
            return ans;
        }

        int diameter(Node *root)
        {
            if (root == NULL)
            {
                return 0;
            }
            if (root->left == NULL && root->right == NULL)
            {
                return 1;
            }
            return (max((height(root->left) + height(root->right) + 1), max(diameter(root->left), diameter(root->right))));
        }

        vector <Node *> v;
        void iot(Node *root, Node *node)    //performs inorder traversal of tree and stores into vector
        {
            if(root == NULL)
            {
                return;
            }
            iot(root->left, node);
            v.push_back(root);
            iot(root->right, node);
        }
        Node*inorderSuccesor(Node *root, Node *node)
        {
            iot(root, node);
            v.push_back(NULL);
            for(int i = 0; i <= v.size()-1; i++)
            {
                if(v[i] == node)
                {
                    return v[i+1];
                }
            }
        }
        Node*inorderPredecessor(Node *root, Node *node)
        {
            v.push_back(NULL);
            iot(root, node);
            for(int i = 1; i <= v.size()-1; i++)
            {
                if(v[i] == node)
                {
                    return v[i-1];
                }
            }
        }
};

int main()  //1 2 3 4 5 -1 6 -1 -1 4 -1 8 -1 -1 -1 9 -1 -1 -1
{
    binaryTree b1;
    // b1.root = b1.buildTree(b1.root);
    b1.buildTreefromlevelOrder(b1.root);
    if (b1.root == NULL)
    {
        cout << "Tree is Empty\n";
    }
    else
    {
        cout << "\nInorder Traversal : \n";
        b1.inorderTraversal(b1.root);
        // cout << "\nIterative Inorder Traversal : \n";
        // b1.iterative_inorderTraversal();
        // cout << "\nPreorder Traversal : \n";
        // b1.preorderTraversal(b1.root);
        // cout << "\nIterative Preorder Traversal : \n";
        // b1.iterative_preorderTraversal();
        // cout << "\nPostorder Traversal : \n";
        // b1.postorderTraversal(b1.root);
        // cout << "\nReverse Levelorder Traversal : \n";
        // b1.rev_levelordertraversal();
        cout << "\nLevelorder Traversal : \n";
        b1.levelorderTraversal();
    }

    cout << "\nNumber of nodes in the Tree: " << b1.countTotalNode(b1.root);

    cout << "\nNumber of Leaf nodes in the Tree: " << b1.countLeafNode(b1.root);

    cout << "\nNumber of Internal nodes in the Tree: " << b1.countInternalnode(b1.root);

    // cout <<"\nHeight of Tree: " << b1.height(b1.root);

    // cout <<"\nDiameter of Tree: " << b1.diameter(b1.root);
    // cout <<"\nDiameter of Tree: " << b1.diameterFast(b1.root).first;

    return 0;
}