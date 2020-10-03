#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct binarySearchTree
{
    int data;
    struct binarySearchTree *left, *right;
} binarySearchTree;

binarySearchTree *createTree(int key)
{
    binarySearchTree *temp = (binarySearchTree *)malloc(sizeof(binarySearchTree));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

binarySearchTree *insertNode(binarySearchTree *root, int data)
{
    if (root == NULL)
    {
        return createTree(data);
    }
    if (root->data > data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void preOrder(binarySearchTree *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(binarySearchTree *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void inOrder(binarySearchTree *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void levelOrder(binarySearchTree *root)
{
    queue<binarySearchTree *> s;
    s.push(root);
    while (!s.empty())
    {
        binarySearchTree *temp;
        temp = s.front();
        s.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
        {
            s.push(temp->left);
        }
        if (temp->right != NULL)
        {
            s.push(temp->right);
        }
    }
    cout << endl;
}

void levelOrderSpiral(binarySearchTree *root, vector<int> v)
{
    queue<binarySearchTree *> s;
    s.push(root);
    while (!s.empty())
    {
        binarySearchTree *temp;
        temp = s.front();
        // v.push_back(temp->data);
        s.pop();
        // cout<<temp->data<<" ";
        if (temp->left != NULL)
        {
            s.push(temp->left);
        }
        if (temp->right != NULL)
        {
            s.push(temp->right);
        }
    }
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    int k = 0, l = 1;
    bool even = true;
    for (int i = 0; i < v.size();)
    {
        k = 0;
        if (i == 0)
        {
            cout << v[i] << " ";
            k++;
        }
        else
        {
            int j = 0;
            // cout<<endl<<i<<" "<<l<<endl;
            if (!even)
            {
                for (j = min((int)(pow(2, l) + i - 1), (int)v.size() - 1); j >= i; j--)
                {
                    cout << v[j] << " ";
                    k++;
                }
            }
            else if (even)
            {
                for (j = i; j <= pow(2, l) + i - 1 && j < v.size(); j++)
                {
                    cout << v[j] << " ";
                    k++;
                }
            }
            l++;
            even = !even;
        }
        i += k;
    }
}

//using hashing basics, implementing vertical order
void verticalOrder(binarySearchTree *root, int horiontalDistance, map<int, vector<int>> &m)
{
    if (root == NULL)
        return;
    m[horiontalDistance].push_back(root->data);
    verticalOrder(root->left, horiontalDistance - 1, m);
    //left side nodes will come first or left of root node, so horizontal distance should be negative

    verticalOrder(root->right, horiontalDistance + 1, m);
    //righ side nodes will come first so horizontal distance should be greator than 0
}
void printVerticalOrder(binarySearchTree *root)
{
    map<int, vector<int>> m;
    int horizontalDistance = 0;
    verticalOrder(root, horizontalDistance, m);
    cout << "Vertical order of this binary tree is" << endl
         << "\t";
    map<int, vector<int>>::iterator i;
    for (i = m.begin(); i != m.end();)
    {
        if (i == m.begin())
        {
            cout << "LEFT MOST NODE---->  ";
        }
        for (int j = 0; j < i->second.size(); j++)
        {
            cout << i->second[j] << " ";
        }
        i++;
        if (i == m.end())
        {
            cout << "  <----- RIGHT MOST NODE";
        }
        cout << endl
             << "\t";
    }
}

int height(binarySearchTree *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->right), height(root->left)) + 1;
}

int internalNode(binarySearchTree *root)
{
    if ((root->left == NULL && root->right == NULL) || root == NULL)
    {
        return 0;
    }
    return internalNode(root->right) + internalNode(root->left) + 1;
}

int externalNode(binarySearchTree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return externalNode(root->right) + externalNode(root->left);
}

bool searchNode(binarySearchTree *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data > key)
    {
        return searchNode(root->left, key);
    }
    else if (root->data < key)
    {
        return searchNode(root->right, key);
    }
    return true;
}

binarySearchTree *deleteNode(binarySearchTree *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        binarySearchTree *temp;
        if (root->left == NULL && root->right == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            temp = root->right;
            // root=root->right;
            free(root);
            return temp;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            temp = root->left;
            // root=root->left;
            free(root);
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            temp = root->right;
            while (temp->left->left != NULL)
            {
                temp = temp->left;
            }
            binarySearchTree *temp2 = temp->right;
            swap(temp->left->data, root->data);
            temp->left = temp->left->right;
        }
    }
    return root;
}

int predecessor(binarySearchTree *root, int key)
{
    if (root != NULL)
    {
        if (root->data >= key)
        {
            if (root->left == NULL)
            {
                return -1;
            }
            return predecessor(root->left, key);
        }
        else if (root->data < key)
        {
            if (root->right == NULL)
            {
                return root->data;
            }
            if (root->right->data >= key && root->right->left == NULL)
            {
                return root->data;
            }
            return predecessor(root->right, key);
        }
    }
}

int successor(binarySearchTree *root, int key)
{
    if (root != NULL)
    {
        if (root->data <= key)
        {
            if (root->right == NULL)
            {
                return -1;
            }
            return successor(root->right, key);
        }
        else if (root->data > key)
        {
            if (root->left == NULL)
            {
                return root->data;
            }
            if ((root->left->data <= key && root->left->right == NULL) || (root->left->data < key && root->right->data > key))
            {
                return root->data;
            }
            return successor(root->left, key);
        }
    }
}

int main()
{
    cout << "\t\t\t.................We will here implementing Binary Search Tree................. ";
    binarySearchTree *root = NULL;
    int x, data, y;
    vector<int> v;
    vector<int>::iterator it;
    do
    {
        cout << "\nPRESS\n\t1 To insert element\n\t2 To delete element\n\t3 To show the tree in particular orders\n\t4 To search an element\n\t5 To find predecessor or successor of particular event\n\t6 To find the height of the tree\n\t7 To get no of nodes\n\t9 To exit\t";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "\nEnter data to be inserted\t";
            cin >> data;
            v.push_back(data);
            if (root == NULL)
            {
                root = insertNode(root, data);
                break;
            }
            insertNode(root, data);
            break;
        case 2:
            cout << "\nEnter element to be deleted\t";
            cin >> data;
            it = find(v.begin(), v.end(), data);
            v.erase(it);
            if (root->data == data)
            {
                root = deleteNode(root, data);
            }
            deleteNode(root, data);
            break;
        case 3:
            cout << "\nWhich order you want?PRESS\n\t1 Preorder Traversal\n\t2 PostOrder Traversal\n\t3 Inorder Traversal\n\t4 Breadth First Traversal(level order traversal)\n\t5 Spiral level order traversal\n\t6 Vertical order traversal\n\t7 To have all traversals in one go\t";
            cin >> y;
            switch (y)
            {
            case 1:
                cout << "\nPreorder traversal is ";
                preOrder(root);
                cout << endl;
                break;
            case 2:
                cout << "\nPostorder traversal is ";
                postOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "\nInorder traversal is ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "\nLevel order traversal is ";
                levelOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "\nSpiral Level order traversal is ";
                levelOrderSpiral(root, v);
                cout << endl;
                break;
            case 6:
                printVerticalOrder(root);
                cout << endl;
                break;
            case 7:
                preOrder(root);
                postOrder(root);
                inOrder(root);
                levelOrder(root);
                levelOrderSpiral(root, v);
                printVerticalOrder(root);
                break;
            }
            break;
        case 4:
            cout << "\nEnter element to be searched\t";
            cin >> data;
            searchNode(root, data);
            break;
        case 5:
            cout << "\nEnter element whose predecessor/successor is to be determined\t";
            cin >> data;
            cout << "PRESS \n\t1-SUCCESSOR\n\t2-PREDECESOR\t";
            cin >> y;
            if (y == 1)
            {
                cout << "\nSuccessor of " << data << " is " << successor(root, data) << endl;
            }
            else
            {
                cout << "\nPredecessor of " << data << " is " << predecessor(root, data) << endl;
            }
            break;
        case 6:
            cout << "\nHeight of Bst tree is " << height(root) << endl;
            break;
        case 7:
            cout << "\nPRESS\n\t1 for internal node\n\t2 for external nodes\t";
            cin >> y;
            if (y == 1)
            {
                cout << "\nNo. of internal nodes is " << internalNode(root) << endl;
            }
            else
            {
                cout << "\nNo. of external nodes is " << externalNode(root) << endl;
            }
            break;
        case 9:
            exit(0);
        }
    } while (1);
}
