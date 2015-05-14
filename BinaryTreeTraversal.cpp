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
void print(stack<struct node*> &s, struct node ** current)
{
	if(!(*current) && !s.empty())
	{
		*current = s.top();
		cout << (*current)->data << "....";
		s.pop();
		*current = ((*current)->right);
	}
}
void leftsubtree(struct node **current,stack<struct node*>& s)
{
	while(*current)
	{
		s.push(*current);
		*current = (*current)->left;
	}
}
void inorder(struct node * btree)
{
		stack<struct node*> s;
		struct node *current = btree;
		do  
		{
				leftsubtree(&current,s);
				print(s,&current);
		}
		while(!s.empty() || current); 
}
void preorder(struct node *btree)
{
		stack<struct node* > s;
		struct node *current = btree;
		s.push(btree);
		while(!s.empty())
		{
			current = s.top();
			cout << current->data << "....";
			s.pop();
			if(current->right)
				s.push(current->right);
			if(current->left)
				s.push(current->left);		
		}

}
void postorder(struct node *btree)
{
	 stack<struct node*> s1;
	 stack<struct node*> s2;
	 s1.push(btree);
	 while(!s1.empty())
	 {
		struct node *first_top = s1.top();
		s2.push(first_top);
		s1.pop();
		if(first_top->left)
			s1.push(first_top->left);
		if(first_top->right)
			s1.push(first_top->right);
	 }
	 while(!s2.empty())
	 {
	    struct node * current = s2.top();
		if(current)
			cout << current->data << "....";
		s2.pop();
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
	cout << endl <<"Prerder Traversal... " << endl;
	preorder(root);
 	cout << endl << "Postorder Traversal... " << endl;
	postorder(root);
	cout << endl;
	return 0;
}
