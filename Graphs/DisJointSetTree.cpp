#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node* parent;
	int rank;
};
class set
{
	private:
		struct node* root;
	public:
	 set(struct node* _root=NULL):root(_root){}
	 void makeSet(struct node* data);
	 void join(struct node* data1,struct node* data2);
	 void link(struct node* data1,struct node* data2);
	 struct node* findSet(struct node* data);
	 bool sameComponent(struct node* data1,struct node* data2);
	 static struct node* init(int data);
	 static void printset(struct node* data);
	 
};
void set::makeSet(struct node* data)
{
	if(!root)
		root = data;
	else
		data->parent = root;
	root =data;
	
}
struct node* set::findSet(struct node* data)
{
	if(data->parent !=data)
		data->parent=findSet(data->parent);	
	return data->parent;
}
struct node* set::init(int data)
{
	struct node* temp= new struct node;
	temp->data= data;
	temp->rank=0;
	temp->parent = temp;
	return temp;
}
void set::link(struct node* data1,struct node* data2)
{
		if(data1->rank > data2->rank)
				data2->parent = data1;
		else
			{
				data1->parent=data2;
				if(data1->rank==data2->rank)
						data2->rank= data2->rank+1;
			}
}
void set::join(struct node* data1,struct node* data2)
{
	struct node *j1=findSet(data1);
	struct node *j2=findSet(data2);
	if(j1!=j2)
			link(j1,j2);
}
bool set::sameComponent(struct node* data1,struct node* data2)
{
	return (findSet(data1)==findSet(data2));
}
void set::printset(struct node *data)
{
	struct node* traversal= data;
	while(traversal->parent!=traversal)
		{
			cout << traversal->data << "....";
			traversal= traversal->parent;
		}
			cout << traversal->data << "....";
}
int main()
{
	set s1,s2;
	struct node*n1=set::init(1);
	struct node*n2=set::init(2);
	struct node*n3=set::init(3);
	struct node*n4=set::init(4);
	struct node*n5=set::init(5);
	struct node*n6=set::init(6);
	struct node*n7=set::init(7);
	s1.makeSet(n1);
	s1.makeSet(n2);	
	s1.makeSet(n3);	
	s1.makeSet(n4);	
	s2.makeSet(n5);	
	s2.makeSet(n6);	
	s2.makeSet(n7);	
	cout << s1.sameComponent(n1,n7)<< endl;
	s1.join(n1,n7);	
	cout << s1.sameComponent(n1,n7)<< endl;
	set::printset(n4);
	cout << endl;
	set::printset(n7);
	return 0;
}
