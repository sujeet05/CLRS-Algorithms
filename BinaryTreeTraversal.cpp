#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

struct node 
{
	struct node * left;
	struct node * right;
	int data;
}*root =NULL ;

struct node * newnode(int key)
{
	struct node* create= new struct node;
	create->left = NULL;
	create->right =NULL;
	create->data = key;
	return create;
}
void insert(int data)
{
	struct node* cr = newnode(data);
	if(!root)
			root=cr;
	else
	{
		struct node* traversal =root;
		struct node* parent =NULL;
		while(traversal)
		{
			    parent = traversal;
				traversal = (traversal->data > data) ? traversal->left : traversal->right;
		}
		if (parent->data >data) 
				 parent->left = cr;
	    else	
			     parent->right =cr;
	}
}
int main()
{
	insert(15);
	insert(6);
	insert(3);
	insert(2);
	insert(4);
	insert(7);
	insert(13);
	insert(9);
	insert(18);
	insert(17);
	insert(20);
	cout << "Inorder Traversal... " << endl;
	inorder(root);
	cout << "Prerder Traversal... " << endl;
//	preorder(root);
	cout << "Postorder Traversal... " << endl;
//	postorder(root);
	cout << endl;
	return 0;
}
