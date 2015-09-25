#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#define PARENT 99999

using namespace std;
enum color
{
		W=0,
		G,
		B
};
class vertix
{
		private:
				int m_name;
				vertix* m_parent;
				color m_clr;
		public:
				vertix(){}
				vertix(int _name,vertix* _parent=NULL ,color _clr=W):m_name(_name),m_parent(_parent),m_clr(_clr){}
				vertix(const vertix& c)
				{
					m_name = c.m_name;
					m_clr = c.m_clr;
					m_parent = new vertix;
					m_parent->m_name = (c.m_parent)->m_name;
					m_parent->m_clr = (c.m_parent)->m_clr;
				}
				int m_getvertixName() {return m_name;}
				vertix* m_getvertixParent() {return m_parent;}
				color m_getvertixcolor() {return m_clr;}
				void MySet_vertixParent(vertix* _v) {m_parent = _v;}	
				void MySet_vertixcolor(color clr) {m_clr =clr;}
};
struct node
{
	vertix* data;
	struct node* parent;
	int rank;
};
class edge
{
	public:
	edge(node* _start,node* _end,int _weight):start(_start),end(_end),weight(_weight){}
	int getweight()const {return weight;}
	node* getstartnode()const {return start;}
	node* getendnode()const {return end;}
	private:
		node *start;
		node *end;
		int weight;
};
struct less_than_key
{
	inline bool operator() (const edge* e1, const edge* e2)
	{
			return (e1->getweight() < e2->getweight());
	}
};

class MySet
{
	private:
		struct node* root;
	public:
	 MySet(struct node* _root=NULL):root(_root){}
	 void makeSet(struct node* data);
	 static void join(struct node* data1,struct node* data2);
	 static void link(struct node* data1,struct node* data2);
	 static struct node* findSet(struct node* data);
	 bool sameComponent(struct node* data1,struct node* data2);
	 static struct node* init(int data);
	 static void printset(struct node* data);
}; 
class Graph
{
		public:
			Graph(vector<edge*>& _e):m_edges(_e){}
			static edge* AddEdge(node *x,node *y,int weight);
			void printEdges();
			void makesets();
			void  KruskalAlgo();	
				
		private:
			//vector<node*> m_vertices;
			vector<edge*>  m_edges;
};
void MySet::makeSet(struct node* data)
{
	if(!root)
		root = data;
	else
		data->parent = root;
	root =data;
	
}
struct node* MySet::findSet(struct node* data)
{
	if(data->parent !=data)
		data->parent=findSet(data->parent);	
	return data->parent;
}
struct node* MySet::init(int data)
{
	struct node* temp= new struct node;
	temp->data= new vertix(data);
	temp->rank=0;
	temp->parent = temp;
	return temp;
}
void MySet::link(struct node* data1,struct node* data2)
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
void MySet::join(struct node* data1,struct node* data2)
{
	struct node *j1=findSet(data1);
	struct node *j2=findSet(data2);
	if(j1!=j2)
			link(j1,j2);
}
bool MySet::sameComponent(struct node* data1,struct node* data2)
{
	return (findSet(data1)==findSet(data2));
}
void MySet::printset(struct node *data)
{
	struct node* traversal= data;
	while(traversal->parent!=traversal)
		{
			cout << traversal->data->m_getvertixName() << "....";
			traversal= traversal->parent;
		}
			cout << traversal->data->m_getvertixName() << "....";
}
edge* Graph::AddEdge(node *x,node *y,int weight)
{
	edge *_e = new edge (x,y,weight);	
	return _e;
}
void Graph::printEdges()
{
	for(int i=0;i<m_edges.size();++i)
			cout << m_edges[i]->getweight() << "..."<< endl;
}
void Graph::KruskalAlgo()
{
	vector<edge*> _ret;
	int tweight =0;
	std::sort(m_edges.begin(), m_edges.end(), less_than_key());	
	for(int i=0;i<m_edges.size();++i)
		if(MySet::findSet(m_edges[i]->getstartnode()) !=MySet::findSet(m_edges[i]->getendnode()))	
		{
				MySet::join(m_edges[i]->getstartnode(),m_edges[i]->getendnode());
				_ret.push_back(m_edges[i]);
		}	
	for(int i=0;i<_ret.size();++i){
			cout << _ret[i]->getstartnode()->data->m_getvertixName() << "..." ;
			cout << _ret[i]->getendnode()->data->m_getvertixName()<< "...." ;
			cout << _ret[i]->getweight() << endl;
			tweight+=_ret[i]->getweight();}
			cout << "total weight..."<< tweight << endl;
}
int main()
{
	cout << "........." << endl;
	struct node*n1=MySet::init(1);
	struct node*n2=MySet::init(2);
	struct node*n3=MySet::init(3);
	struct node*n4=MySet::init(4);
	struct node*n5=MySet::init(5);
	struct node*n6=MySet::init(6);
	struct node*n7=MySet::init(7);
	struct node*n8=MySet::init(8);
	struct node*n9=MySet::init(9);

	vector<edge*> e;
	edge* e1=Graph::AddEdge(n1,n2,4);
	e.push_back(e1);
	edge*e2=Graph::AddEdge(n1,n8,8);
	e.push_back(e2);
	edge*e3=Graph::AddEdge(n2,n1,4);
	e.push_back(e3);
	edge*e5=Graph::AddEdge(n2,n8,11);
	e.push_back(e5);
	edge*e6=Graph::AddEdge(n2,n3,8);
	e.push_back(e6);
	edge*e7=Graph::AddEdge(n3,n2,8);
	e.push_back(e7);
	edge*e8=Graph::AddEdge(n3,n4,7);
	e.push_back(e8);
	edge*e9=Graph::AddEdge(n3,n6,4);
	e.push_back(e9);
	edge*e10=Graph::AddEdge(n3,n9,2);
	e.push_back(e10);
	edge*e11=Graph::AddEdge(n4,n3,7);
	e.push_back(e11);
	edge*e12=Graph::AddEdge(n4,n5,9);
	e.push_back(e12);
	edge*e13=Graph::AddEdge(n4,n6,14);
	e.push_back(e13);
	edge*e14=Graph::AddEdge(n5,n4,9);
	e.push_back(e14);
	edge*e15=Graph::AddEdge(n5,n6,10);
	e.push_back(e15);
	edge*e16=Graph::AddEdge(n6,n4,14);
	e.push_back(e16);
	edge*e17=Graph::AddEdge(n6,n5,10);
	e.push_back(e17);
	edge*e18=Graph::AddEdge(n6,n3,4);
	e.push_back(e18);
	edge*e19=Graph::AddEdge(n6,n7,2);
	e.push_back(e19);
	edge*e20=Graph::AddEdge(n7,n6,2);
	e.push_back(e20);
	edge*e21=Graph::AddEdge(n7,n8,1);
	e.push_back(e21);
	edge*e22=Graph::AddEdge(n7,n9,6);
	e.push_back(e22);
	edge*e23=Graph::AddEdge(n8,n7,1);
	e.push_back(e23);
	edge*e24=Graph::AddEdge(n8,n9,7);
	e.push_back(e24);
	edge*e25=Graph::AddEdge(n8,n2,11);
	e.push_back(e25);
	edge*e26=Graph::AddEdge(n8,n1,8);
	e.push_back(e26);
	edge*e27=Graph::AddEdge(n9,n3,2);
	e.push_back(e27);
	edge*e28=Graph::AddEdge(n9,n7,6);
	e.push_back(e28);
	edge*e29=Graph::AddEdge(n9,n8,7);
	e.push_back(e29);
	Graph G1(e);
	G1.KruskalAlgo();
	return 0;
}
