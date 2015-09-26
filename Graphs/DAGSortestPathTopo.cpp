#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;

enum color
{
		W=0,
		G,
		B
};

class vertix
{
	public:
	char name;
	char parent;
	int  weight;
	color clr;
	vertix(char name ,char parent='#',int weight=999,color _clr=W):name(name),parent(parent),weight(weight),clr(_clr) {}
	char getvertixName() {return name;}
	char getvertixParent() {return parent;}
	color getvertixcolor() {return clr;}
	void setParent(char _v) {parent = _v;}	
	void setcolor(color clr) {clr =clr;}
};
class DAGGraph
{
	public:
		DAGGraph(vector<vertix*>& _v):m_vertices(_v){ AddEdge(); }
		vector<vertix*> m_vertices;
		list<vertix*> m_topoorder; 
		void RunAlgorithm();
		map<char,map<char,int>> m_edges;
		void AddEdge();
		void DFS(vertix& src);
		void BuildDFS();
		void initializeSingleSource(vertix& v);
		void Relax(char u,char v,char w);
		int getweight(char c) {int _ret;for (auto i:m_vertices) if(i->name==c) _ret= i->weight;return _ret;}
		void setweight(char c,int weight) {for (auto i:m_vertices) if(i->name==c)  i->weight=weight;}
		void setparent(char c,char p) {for(auto i:m_vertices) if(i->name==c) i->parent=p;}
		void setcolor (char c,color clr) {for(auto i:m_vertices) if(i->name==c) i->clr=clr;}
		vertix* getVertixObj(char c){vertix* _ret= NULL;for(auto i:m_vertices) if(i->name==c) _ret=i;return _ret;}
		void setweightinTopo(char c,int weight) {for (auto i:m_topoorder) if(i->name==c)  i->weight=weight;}
		void setparentinTopp(char c,char p) {for(auto i:m_topoorder) if(i->name==c) i->parent=p;}
		int getweightinTopo(char c) {int _ret;for (auto i:m_topoorder) if(i->name==c) _ret= i->weight;return _ret;}
		void printtopoorder();
};
ostream& operator << (ostream& os ,const vector<vertix*>& v)
{
	for(auto i:v){
		os << i->name << ".." << i->parent << ".." << i->weight << endl ;
	}
}
ostream& operator << (ostream& os ,const list<vertix*>& v)
{
	for(auto i:v)
		os << i->name << ".."  << ".." << i->weight << endl;
}
void DAGGraph::AddEdge()
{
	m_edges['r']['s'] =5;
	m_edges['r']['t'] =3;
	m_edges['s']['t'] =2;
	m_edges['s']['x'] =6;
	m_edges['t']['x'] =7;
	m_edges['t']['y'] =4;
	m_edges['t']['z'] =2;
	m_edges['x']['y'] =-1;
	m_edges['x']['z'] =1;
	m_edges['y']['z'] =-2;
}
void DAGGraph::initializeSingleSource(vertix& _v)
{
	for(auto i:m_topoorder)
	{
		i->parent = 'T';
		i->weight = 999;
		if(i->name==_v.name)
			i->weight =0;
	}
}
void DAGGraph::printtopoorder()
{
	for(auto i:m_topoorder)
			cout << i->name << "...";
	cout << endl;
}
void DAGGraph::DFS(vertix& src)
{
	src.setcolor(G);
	for(auto j: m_edges)
	{ 
			char u = j.first;
			map<char,int> _m=j.second;
			if(u==src.getvertixName())
			{
				for(auto k:_m)
				if(getVertixObj((k.first))->getvertixcolor() ==W)
				{
						setparent(k.first,src.getvertixName());
						setcolor(k.first,G);
						DFS(*(getVertixObj(k.first)));// Fix this
				}
			}
	}
	setcolor(src.getvertixName(),B);
	m_topoorder.push_front(&src); 
}

void DAGGraph::BuildDFS()
{
	for(int i=0;i < m_vertices.size() ;++i)
	{
			(*m_vertices[i]).setcolor(W);
			(*m_vertices[i]).setParent('#');
	}
	        vertix *src= getVertixObj('s');
			DFS(*src);
}
void DAGGraph::Relax(char u,char v,char w)
{
			int _weight =getweightinTopo(u)+w;
			if(getweightinTopo(v) >_weight)
			{
				setweightinTopo(v,_weight);
				setparentinTopp(v,u);
			} 
}
void DAGGraph::RunAlgorithm()
{
	BuildDFS();
	initializeSingleSource(*(m_topoorder.front()));
		for(auto i:m_topoorder)
		{
			char first = i->name;
			for(auto j:m_edges[first])
				Relax(first,j.first,j.second);
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
	vertix v6('r');
	v.push_back(&v6);
	DAGGraph G(v);
	G.BuildDFS();
	G.printtopoorder();
	G.RunAlgorithm() ;
    cout <<  G.m_topoorder;	
	cout << endl;
	return 0;
}
