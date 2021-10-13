
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

int level =0;
bool flag= true;

void printLevelOrder(Node *root)
{

	if (root == NULL) 
	return;

	queue<Node *> q;
    stack<Node *>s;
    
	q.push(root);
    
	while (!q.empty())
	{
	    
	    int sa = q.size();
	    level++;
	   
		while(sa--)
		{
		    	Node *node = q.front();
		        q.pop();
                
        
            if(flag)
                cout <<node->data<<" " ;
            else
                s.push(node);
            
                if (node->left != NULL)
    			    q.push(node->left);
    
    		
    		    if (node->right != NULL)
    			    q.push(node->right);
         
		}
		
		if(!flag)
		{
		    while(!s.empty())
		    {
		        Node* ptr=s.top();
		        s.pop();
		        
		        cout<<ptr->data<<" ";
		    }
		}
		
		
		 if(level==2)
	    {
	        flag =!flag;
	        level=0;
	    }
		cout<<endl;
		
	}
}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(2);
    root->left->right->left->left = newNode(16);
    root->left->right->left->right = newNode(17);
    root->right->left->right->left = newNode(18);
    root->right->right->left->right = newNode(19);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	return 0;
}


