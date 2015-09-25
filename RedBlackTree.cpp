#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
enum color
{
	red,
	black
};

struct node 
{
	struct node * left;
	struct node * right;
	struct node * parent;
	color clr;
	int data;
}*root =NULL ;

struct node * newnode(int key)
{
	struct node* create= new struct node;
	create->left = NULL;
	create->right =NULL;
	create->parent = NULL;
	create->data = key;
	create->clr = red;
	return create;
}
void RB_Transplant(struct node *btree,struct node *u ,struct node *v)
{
	if(!btree)
			btree = v;
	if(u->parent->left ==u)
		u->parent->left =v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}
void RB_Left_Rotation(struct node *btree,struct node *x)
{
	struct node * y = x->right;
	if(y)
	{
		x->right = y->left;
		if(y->left)
			y->left->parent =x;
		y->parent = x->parent;
		if(x->parent ==NULL)
			btree =y;
		else if(x==x->parent->left)
				x->parent->left = y;
		else
				x->parent->right =y;
		y->left = x;
		x->parent =y;
	}
}
void RB_Right_Rotation(struct node *btree,struct node *y)
{
	struct node *x= y->left;
	if(x)
	{
		if(x->right)
			y->left =x->right;
		x->parent = y->parent;
		if(y->parent==NULL)
				btree =x;
		else if(y==y->parent->left)
				y->parent->left =x;
		else
				y->parent->right =x;
		x->right =y;
		y->parent =x;
	}
}

struct node *findelement(int key)
{
	struct node * traversal = root;
	while(traversal)
	{
		if(traversal->data ==key)
				return traversal;
		traversal = (traversal->data >key) ? traversal->left : traversal->right;
	}
		return NULL;
}

struct node * TreeMinimum(struct node* btree)
{
		while(btree->left)
		 btree= btree->left;
		return btree;
}

void inorder(struct node* btree)
{
	if(btree)
	{
		inorder(btree->left);
		cout << btree->data << "...." << btree->clr << "...";
		inorder(btree->right);
	}
}
void RB_Insert_Fixup(struct node *btree,struct node *z)
{
	if(!(z->parent))
	{	
			z->clr =black;
			return;
	}
	 while(z->parent && z->parent->clr==red)
	 {
	    if(z->parent->parent)
		{
			if(z->parent==z->parent->parent->left)
			{
			struct node * y= z->parent->parent->right;
			if(y->clr==red)
			{
				z->parent->clr=black;
				y->clr=black;
				z->parent->parent->clr= red;
				z= z->parent->parent;
			}
			else if (z==z->parent->right)
			{
				z= z->parent;
				RB_Left_Rotation(btree,z);
			}
			z->parent->clr= black;
			z->parent->parent->clr=red;
			RB_Right_Rotation(btree,z->parent->parent);	
			}
			else 
			{
				struct node * y= z->parent->parent->left;
				if(y->clr==red)
				{
					z->parent->clr=black;
					y->clr=black;
					z->parent->parent->clr= red;
					z= z->parent->parent;
				}
				else if (z==z->parent->left)
				{
					z= z->parent;
					RB_Left_Rotation(btree,z);
				}
				z->parent->clr= black;
				z->parent->parent->clr=red;
				RB_Right_Rotation(btree,z->parent->parent);	
			}
		}		
	}
}
void insert(struct node **btree,int key)
{
	struct node * cr = newnode(key);
	if(*btree==NULL) *btree = cr;
	else
	{
		struct node *traversal = *btree;
		struct node * parent =NULL;
		while(traversal)
		{
			parent = traversal;
			traversal= (traversal->data >key)? traversal->left : traversal->right;
		}
		if(parent->data > key)
			parent->left = cr;
		else 
			parent->right= cr;
		cr->parent = parent;
	}
	RB_Insert_Fixup(*btree,cr);
}
struct node * getparent(int key)
{
		if(!root || root->data == key) return NULL;
		else
		{
			struct node *_ret = NULL;
			struct node * traversal = root;
			while(traversal)
			{
				_ret = traversal;
				traversal = (traversal->data >key) ? traversal->left : traversal->right;
				if(traversal->data == key)
				return _ret;
			}
		}
		return NULL;
}
struct node * Successor(int key)
{
		if(!root)
		return NULL;
		struct node *find = findelement(key);
		if(find)
		{
			if(find->right) 
			 return TreeMinimum(find->right);
			struct node *ancestor = getparent(key);
			while(ancestor && find ==ancestor->right)
			{
				find = ancestor;
				ancestor = getparent(find->data);
			}
			return ancestor;
		}
			return NULL;
}
int main()
{
	insert(&root,26);
	insert(&root,17);
	insert(&root,14);
	insert(&root,10);
	insert(&root,7);
	insert(&root,3);
	insert(&root,12);
	insert(&root,16);
	insert(&root,15);
	insert(&root,21);
	insert(&root,19);
	insert(&root,20);
	insert(&root,23);
	insert(&root,41);
	insert(&root,30);
	insert(&root,28);
	insert(&root,38);
	insert(&root,35);
	insert(&root,39);
	insert(&root,47);
	cout << "inorder traversal ..." << endl;
	inorder(root);
	cout << endl;
	return 0;
}
