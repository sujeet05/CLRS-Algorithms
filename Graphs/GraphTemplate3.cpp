#include<iostream>
#include<list>
#include<vector>
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
		int m_parent;
		color m_clr;
	public:
		vertix(int _name,int _parent=PARENT,color _clr=W):m_name(_name),m_parent(_parent),m_clr(_clr){}
		int m_getvertixName() {return m_name;}
		int m_getvertixParent() {return m_parent;}
		color m_getvertixcolor() {return m_clr;}
		void set_vertixParent(vertix _v) {m_parent = _v.m_name;}	
		void set_vertixcolor(vertix _v) {m_clr =_v.m_clr;}
};

class Graph
{
	public:
	    Graph(vector<vertix> _v,list<vertix> *_e=NULL):m_vertices(_v){m_edges = new list<vertix>[m_vertices.size()]; m_Init(); }
		void m_AddEdge(vertix x,vertix y);
		void m_Init();
		void m_printEdges();
	private:
		vector<vertix> m_vertices;
		list<vertix> * m_edges;
};
void Graph::m_printEdges()
{
		for(int i=0;i<m_vertices.size();i++)
		for(list<vertix>::iterator j = m_edges[i].begin(); j != m_edges[i].end(); j++)
			cout  << m_vertices[i].m_getvertixName() << "..."<<  (*j).m_getvertixName() << endl;
}
void Graph::m_AddEdge(vertix x,vertix y)
{
		m_edges[x.m_getvertixName()-1].push_back(y.m_getvertixName());
}
void Graph::m_Init()
{
   m_AddEdge(m_vertices[0],m_vertices[1]);
   m_AddEdge(m_vertices[0],m_vertices[3]);
   m_AddEdge(m_vertices[1],m_vertices[4]);
   m_AddEdge(m_vertices[2],m_vertices[4]);
   m_AddEdge(m_vertices[2],m_vertices[5]);
   m_AddEdge(m_vertices[3],m_vertices[1]);
   m_AddEdge(m_vertices[4],m_vertices[3]);
   m_AddEdge(m_vertices[5],m_vertices[5]);
  /* m_AddEdge(1,2);
   m_AddEdge(1,4);
   m_AddEdge(2,5);
   m_AddEdge(3,5);
   m_AddEdge(3,6);
   m_AddEdge(4,2);
   m_AddEdge(5,4);
   m_AddEdge(6,6);*/
}
int main()
{
	vertix  v1(1),v2(2),v3(3),v4(4),v5(5),v6(6);
	vector<vertix> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	v.push_back(v6);
		
  //vector<int> v{1,2,3,4,5,6};
   Graph G(v);
   G.m_printEdges();
   return 0;
}
