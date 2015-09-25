#include<iostream>
#include<vector>
#include<map>
#include<Algorithm>
#include <math.h>

#define KEY 999

using namespace std;

class vertix
{
 public:
	char name;
	char parent;
	int  key;
	vertix(char name ,char parent='T',int key=999):name(name),parent(parent),key(key) {}
};
#if 0
class vertix
{
		public:
				int m_name;
				vertix* m_parent;
				int  key;
				vertix(int _name,vertix* _parent=NULL ,int _key=KEY):m_name(_name),m_parent(_parent),key(_key){}
};
#endif
bool operator < (const vertix& u, const vertix& v)
{
		return(u.key < v.key);
}


int parent(int i) {return floor(((i-1)/2));}
int left(int i){return ((2*i)+1);}
int right(int i){return( (2*i)+2);}

void printArray(vector<vertix*>& arr)
{
	for(int i =1;i<=arr.size();i++)
			cout << arr[i-1]->name << "..";
	cout<<endl;
}
void swap(vertix *x,vertix *y)
{
    vertix temp = *x;
	*x= *y;
	*y=temp;
}

void Min_HeapIFY(vector<vertix*>& arr,int i)
{
	int smallest =i;
	if(i <arr.size() && left(i) < arr.size() && *arr[left(i)] < *arr[i])
	  smallest= left(i);
	 if(i <arr.size() && right(i) < arr.size() && *arr[right(i)] < *arr[smallest])
	  smallest= right(i);
	if(smallest != i)
		{
			swap(arr[smallest],arr[i]);
			Min_HeapIFY(arr,smallest);
		}
}
void Min_HeapIFY_iterative(vector<vertix*>& arr,int i)
{
	int smallest =i;
	while(i< arr.size())
	{
	   if(left(i)< arr.size() && *arr[left(i)] < *arr[i])
			   smallest = left(i);
	    if(right(i) < arr.size() && *arr[right(i)] < *arr[smallest])
			   smallest = right(i);
	   if(smallest !=i)
	   {
			  swap(arr[smallest],arr[i]);
			  i= smallest;
	   }
	   else 
			break;
	}
}

void Build_Min_Heap(vector<vertix*>& arr)
{
	for(int i=floor((arr.size()-1)/2);i >=0;--i)
		Min_HeapIFY_iterative(arr,i);
}

vertix* Heap_Minimum(vector<vertix*>& arr)
{
	Build_Min_Heap(arr);
	return arr[0];
}
vertix* Heap_Extract_Miinimum(vector<vertix*>& arr)
{
	Build_Min_Heap(arr);
	vertix *_ret = arr[0];
	_ret= arr[0];
	arr[0]=arr[arr.size()-1];
	arr.pop_back();
	Min_HeapIFY(arr,0);
	return _ret;
}
void Heap_increase_key(vector<vertix*>& arr,int key,int i)
{
	if(key < *arr[i])
	{
		cout << "key is lesser than already it has.."<< endl;
		return;
	}
	*arr[i]=key;
	while( i >0 &&  *arr[parent(i)] < *arr[i])
	{
		 swap(arr[parent(i)],arr[i]);
		 i = parent(i);
	}
}
class Graph
{
		public:
				Graph(vector<vertix*>& _v):m_vertices(_v)
				{   
					Init();
				}   
				
				void AddEdge();
				void Init();
				int getweight(char c) {int _ret;for (auto i:m_vertices) if(i->name==c) _ret= i->key;return _ret;}
				void setweight(char c,int key) {for (auto i:m_vertices) if(i->name==c)  i->key=key;}
				void setparent(char c,char p) {for(auto i:m_vertices) if(i->name==c) i->parent=p;}
				void initializeSingleSource(vertix& _v);
				void Relax(vertix* _v);
				void RunDijkstraAlgorithm();
				vector<vertix*> m_vertices;
				vector<vertix*> m_ordered;
				map<char,map<char,int>> m_edges;
};

ostream& operator << (ostream& os ,const vector<vertix*>& v)
{
	for(auto i:v)
		os << i->name << ".." << i->parent << ".." << i->key << endl;
}
void Graph::AddEdge()
{
	m_edges['s']['t'] =10;
	m_edges['s']['y'] =5;
	m_edges['t']['x'] =1;
	m_edges['t']['y'] =2;
	m_edges['x']['z'] =4;
	m_edges['z']['x'] =6;
	m_edges['z']['s'] =7;
	m_edges['y']['t'] =3;
	m_edges['y']['x'] =9;
	m_edges['y']['z'] =2;
}
void Graph::Init()
{
	AddEdge();
}

void Graph::initializeSingleSource(vertix& _v)
{
	for(auto i:m_vertices)
	{
		i->parent = 'T';
		i->key = 999;
		if(i->name==_v.name)
			i->key =0;
	}
}
void Graph::Relax(vertix* _v)
{
		for(map<char,map<char,int>>::iterator i = m_edges.begin();i != m_edges.end() ;++i)
		{
		    if(_v->name ==i->first)
			for(map<char, int>::iterator j=i->second.begin(); j!=i->second.end();++j)
			{
				int _w = j->second;
				int u_w= _v->key;
				int v_w=getweight(j->first);
				if(v_w > u_w+_w)
				{
					setweight(j->first,u_w+_w);
					setparent(j->first,_v->name);
				}		 
			}
		}
}
void Graph::RunDijkstraAlgorithm()
{
	initializeSingleSource(*m_vertices[0]);
	while(m_vertices.size() >0)
	{
		vertix* _min=Heap_Extract_Miinimum(m_vertices);
		m_ordered.push_back(_min);
		Relax(_min);
		Build_Min_Heap(m_vertices);
	}

}
int main()
{
	vector<vertix*> v;
	vertix v1('s');
	v.push_back(&v1);
	vertix v2('t');
	v.push_back(&v2);
	vertix v3('x');
	v.push_back(&v3);
	vertix v4('y');
	v.push_back(&v4);
	vertix v5('z');
	v.push_back(&v5);
	Graph G(v);
    cout << G.m_vertices;	
	cout << endl;
	G.RunDijkstraAlgorithm();
    cout << "RESULT..." << endl << G.m_ordered;	
	cout << endl;
	return 0;
}
	

