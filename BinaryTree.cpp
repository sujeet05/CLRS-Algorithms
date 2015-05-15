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
void insert2(struct node** btree,int key)
{
		if(!*btree)
				*btree = newnode(key);
		else
			((*btree)->data >key) ? insert2(&((*btree)->left),key):insert2(&((*btree)->right),key);
}
void inorder(struct node *btree)
{
	if(btree)
	{
		inorder(btree->left);
		cout << btree->data << "...";
		inorder(btree->right);
	}
}

void preorder(struct node *btree)
{
	if(btree)
	{
		cout << btree->data << "...";
		preorder(btree->left);
		preorder(btree->right);
	}
}

void postorder(struct node *btree)
{
	if(btree)
	{
		postorder(btree->left);
		postorder(btree->right);
		cout << btree->data << "...";
	}
}
struct node * TreeMinimum(struct node* btree)
{
		while(btree->left)
		 btree= btree->left;
		return btree;
}

struct node * TreeMinimum2(struct node* btree)
{
	  if(!(btree->left)) return btree;
	  return TreeMinimum(btree->left);
}
struct node * TreeMaximum(struct node* btree)
{
		while(btree->right)
		 btree= btree->right;
		return btree;
}
struct node * TreeMaximum2(struct node* btree)
{
	  if(!(btree->right)) return btree;
	  return TreeMaximum2(btree->right);
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
struct node* findelement2(struct node *btree,int key)
{
	   if( !btree || btree->data ==key) return btree;
      	return (btree->data >key) ? findelement2(btree->left,key):findelement2(btree->right,key);
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
struct node* Predecessor(int key)
{
		if(!root)
		return NULL;
		struct node *find = findelement(key);
		if(find)
		{
			if(find->left)
			 return TreeMaximum(find->left);
			struct node *ancestor = getparent(key);
			while(ancestor && find == ancestor->left)
			{
				find = ancestor;
				ancestor = getparent(find->data);
			}
			return ancestor;
		}
		return NULL;
}
void Transplant(struct node **btree,struct node *u, struct node *v)
{
	struct node *Uparent = NULL;
	struct node *Vparent = NULL;
	if(u)
		 Uparent= getparent(u->data);
	if(v)
		 Vparent= getparent(v->data);
	if(!Uparent)
		*btree = v;
	else if (u==Uparent->left)
		Uparent->left = v;
	else
		Uparent->right =v;
	
}
void Delete(struct node **btree,struct node * _deletenode)
{
	if(_deletenode)
	{
		if(!(_deletenode->left)) //No left child of deleted node handle two case 1. no left child 2. leaf node 
			Transplant(btree,_deletenode,_deletenode->right);
		else if(!(_deletenode->right))
			Transplant(btree,_deletenode,_deletenode->left);
		else
		{
			struct node *successornode = Successor(_deletenode->data);
			if(successornode)
			{
				if(_deletenode->right != successornode)
				{
					 Transplant(btree,successornode,successornode->right);
					 successornode->right = _deletenode->right;
					 _deletenode->right = successornode;
				}
		        Transplant(btree,_deletenode,successornode);
				successornode->left = _deletenode->left;
			}
		}
	}
}
int main()
{
	insert2(&root,15);
	insert2(&root,6);
	insert2(&root,3);
	insert2(&root,2);
	insert2(&root,4);
	insert2(&root,7);
	insert2(&root,13);
	insert2(&root,9);
	insert2(&root,18);
	insert2(&root,17);
	insert2(&root,20);
#if 0
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
#endif 
	cout << "Inorder Traversal... " << endl;
	inorder(root);
	cout << "Prerder Traversal... " << endl;
	preorder(root);
	cout << "Postorder Traversal... " << endl;
	postorder(root);
	cout << endl;
	cout << "Tree Minimum :" << TreeMinimum(root)->data << endl;
	cout << "Tree Minimum  Recursive:" << TreeMinimum2(root)->data << endl;
	cout << "Tree Maximum :" << TreeMaximum(root)->data << endl;
	cout << "Tree Maximum : Recursive" << TreeMaximum2(root)->data << endl;
	cout << "Find Element 18 :" << findelement(18) << endl;
	cout << "Find Element 18 Recursive:" << findelement2(root,18) << endl;
	cout << "Tree Minimum :" << TreeMinimum(findelement(3))->data << endl;
	cout << "Tree Minimum  Recursive:" << TreeMinimum2(findelement(3))->data << endl;
	cout << "Tree Maximum :" << TreeMaximum(findelement(3))->data << endl;
	cout << "Tree Maximum : Recursive" << TreeMaximum(findelement(3))->data << endl;
	cout << "Find Element 90 :" << findelement(90) << endl;
	cout << "parnet of node 13 :" << getparent(13)->data << endl;
	cout << "parnet of node 2 :" << getparent(2)->data << endl;
	cout << "parnet of node 6 :" << getparent(6)->data << endl;
	cout << "successor of node 2 :" << Successor(2)->data << endl;
	cout << "successor of node 13 :" << Successor(13)->data << endl;
	cout << "successor of node 17 :" << Successor(17)->data << endl;
	cout << "successor of node 15 :" << Successor(15)->data << endl;
	cout << "predecessor of node 4 :" << Predecessor(4)->data << endl;
	cout << "predecessor of node 13 :" << Predecessor(13)->data << endl;
	cout << "predecessor of node 17 :" << Predecessor(17)->data << endl;
	cout << "predecessor of node 15 :" << Predecessor(15)->data << endl;
	Delete(&root,findelement(13));
	cout << "After delete 13 inorder traversal " << endl;
	inorder(root);
	Delete(&root,findelement(6));
	cout << "After delete 6 inorder traversal " << endl;
	inorder(root);
	Delete(&root,findelement(9));
	cout << "After delete 9 inorder traversal " << endl;
	inorder(root);
	Delete(&root,findelement(15));
	cout << "After delete 15 inorder traversal " <<  endl;
	inorder(root);
	return 0;
}
