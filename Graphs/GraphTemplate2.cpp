#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

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
		int m_parent;
		color m_clr;
	public:
		int m_getvertixName() {return m_name;}
		int m_getvertixParent() {return m_parent;}
		color m_getvertixcolor() {return m_clr;}	
};

class Graph
{
	public:
	    Graph(vector<int> _v,list<int> *_e=NULL):m_vertices(_v){m_edges = new list<int>[m_vertices.size()]; m_Init(); }
		void m_AddEdge(int x,int y);
		void m_Init();
		void m_printEdges();
	private:
		vector<int> m_vertices;
		list<int> * m_edges;
};
void Graph::m_printEdges()
{
		for(int i=0;i<m_vertices.size();i++)
		for(list<int>::iterator j = m_edges[i].begin(); j != m_edges[i].end(); j++)
			cout  << m_vertices[i] << "..."<<  *j << endl;
}
void Graph::m_AddEdge(int x,int y)
{
		m_edges[x-1].push_back(y);
}
void Graph::m_Init()
{
   m_AddEdge(1,2);
   m_AddEdge(1,4);
   m_AddEdge(2,5);
   m_AddEdge(3,5);
   m_AddEdge(3,6);
   m_AddEdge(4,2);
   m_AddEdge(5,4);
   m_AddEdge(6,6);
}
int main()
{
   vector<int> v{1,2,3,4,5,6};
   Graph G(v);
   G.m_printEdges();
   return 0;
}
