#include<iostream>
#include<vector>
#include<map>
#include<Algorithm>
#include <math.h>

#define KEY 99999

using namespace std;

class vertix
{
		public:
				int m_name;
				vertix* m_parent;
				int  key;
				vertix(int _name,vertix* _parent=NULL ,int _key=KEY):m_name(_name),m_parent(_parent),key(_key){}
};
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
			cout << arr[i-1]->m_name << "..";
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
					 m_weight=0;
					Init();
				}   
				
				void AddEdge(int u,int v,int weight);
				void Init();
				void printedges();
				void primAlgorithm();
				int m_weight;
		private:
				vector<vertix*> m_vertices;
				map<int,map<int,int>> m_weightededges;
};
void Graph::printedges()
{
		for(auto i:m_weightededges)
		{   
				int k =i.first;
				for(auto j:m_weightededges[k])
						cout << i.first <<"..."<< j.first <<"..."<< j.second << endl;
		}   
}
void Graph::AddEdge(int u,int v,int weight)
{
		m_weightededges[u][v]=weight;
}
void Graph::Init()
{
		AddEdge(1,2,4);
		AddEdge(1,8,8);
		AddEdge(2,1,4);
		AddEdge(2,8,11);
		AddEdge(2,3,8);
		AddEdge(3,2,8);
		AddEdge(3,4,7);
		AddEdge(3,6,4);
		AddEdge(3,9,2);
		AddEdge(4,3,7);
		AddEdge(4,5,9);
		AddEdge(4,6,14);
		AddEdge(5,4,9);
		AddEdge(5,6,10);
		AddEdge(6,4,14);
		AddEdge(6,5,10);
		AddEdge(6,3,4);
		AddEdge(6,7,2);
		AddEdge(7,6,2);
		AddEdge(7,8,1);
		AddEdge(7,9,6);
		AddEdge(8,7,1);
		AddEdge(8,9,7);
		AddEdge(8,2,11);
		AddEdge(8,1,8);
		AddEdge(9,3,2);
		AddEdge(9,7,6);
		AddEdge(9,8,7);
}
void Graph::primAlgorithm()
{
	m_vertices[0]->key=0;	
	Build_Min_Heap(m_vertices);
	while(m_vertices.size() >0)
	{
		vertix* _min=Heap_Extract_Miinimum(m_vertices);
		if(_min->m_parent)
	    	cout<< _min->m_parent->m_name<< "...";
		cout << _min->m_name << "...";
		cout << endl;
		m_weight+= _min->key;
		for(map<int,map<int,int>>::iterator i = m_weightededges.begin();i != m_weightededges.end() ;++i)
		{
		    if(_min->m_name ==i->first)
			for(map<int, int>::iterator j=i->second.begin(); j!=i->second.end();++j)
				for(int m=0;m < m_vertices.size();++m)
			   		if(m_vertices[m]->m_name==j->first && m_vertices[m]->key > j->second )
					{
				   		m_vertices[m]->key = j->second;
				   		m_vertices[m]->m_parent= _min;
					}
		}
	}
	cout <<"Total weight is : "<< m_weight << endl;
}
int main()
{

		vertix  D1(1),D2(2),D3(3),D4(4),D5(5),D6(6),D7(7),D8(8),D9(9);
		vector<vertix* > d;
		d.push_back(&D1);
		d.push_back(&D2);
		d.push_back(&D3);
		d.push_back(&D4);
		d.push_back(&D5);
		d.push_back(&D6);
		d.push_back(&D7);
		d.push_back(&D8);
		d.push_back(&D9);
		Graph G1(d);
		cout << "Prim Algorithm ......" << endl;
		G1.primAlgorithm();
		
	
}

