#include<iostream>
#include<list>
#include<vector>
#include<queue>
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
				void set_vertixParent(vertix* _v) {m_parent = _v;}	
				void set_vertixcolor(color clr) {m_clr =clr;}
};

class Graph
{
		public:
			Graph(vector<vertix*>& _v,list<vertix> *_e=NULL):m_vertices(_v)
			{
					m_edges = new list<vertix*>[m_vertices.size()]; 
					m_InitTopo();
		   	}
			void m_AddEdge(vertix &x,vertix &y);
			void m_printEdges();
			void m_InitTopo();
			void BuildDFS();
			void DFS(vertix& src);
			void printPath(vertix &src,vertix &dest);
			void Topologicalsort();
		private:
			vector<vertix*> m_vertices;
			list<vertix*> * m_edges;
			list<vertix*>  m_topoorder;
};
void Graph::m_printEdges()
{
		for(int i=0;i<m_vertices.size();i++)
		for(list<vertix*>::iterator j = m_edges[i].begin(); j != m_edges[i].end(); j++)
		cout  << (*m_vertices[i]).m_getvertixName() << "..."<<  (*j)->m_getvertixName() << "..color.." << (*j)->m_getvertixcolor() << endl;
}
void Graph::m_AddEdge(vertix &x,vertix &y)
{
		m_edges[x.m_getvertixName()-1].push_back(&y);
}

void Graph::m_InitTopo()
{
		m_AddEdge(*m_vertices[0],*m_vertices[1]);
		m_AddEdge(*m_vertices[0],*m_vertices[7]);
		m_AddEdge(*m_vertices[1],*m_vertices[2]);
		m_AddEdge(*m_vertices[1],*m_vertices[7]);
		m_AddEdge(*m_vertices[2],*m_vertices[5]);
		m_AddEdge(*m_vertices[3],*m_vertices[2]);
		m_AddEdge(*m_vertices[3],*m_vertices[4]);
		m_AddEdge(*m_vertices[4],*m_vertices[4]);
		m_AddEdge(*m_vertices[6],*m_vertices[7]);
}
void Graph::DFS(vertix& src)
{
		src.set_vertixcolor(G);
		for(list<vertix*>::iterator j = m_edges[src.m_getvertixName()-1].begin(); j != m_edges[src.m_getvertixName()-1].end(); j++)
		{ 
				if((*j)->m_getvertixcolor() ==W)
				{
						(*j)->set_vertixParent(&src);
						(*j)->set_vertixcolor(G);
						DFS(**j);
				}
		}
		  src.set_vertixcolor(B);
		  m_topoorder.push_front(&src); 
}
void Graph::Topologicalsort()
{
		BuildDFS();
		for(list<vertix*>::iterator j = m_topoorder.begin(); j != m_topoorder.end(); j++)
				cout << (*j)->m_getvertixName() << "....";
}
void Graph::BuildDFS()
{
	for(int i=0;i < m_vertices.size() ;++i)
	{
			(*m_vertices[i]).set_vertixcolor(W);
			(*m_vertices[i]).set_vertixParent(NULL);
	}
	for(int i=0;i < m_vertices.size() ;++i)
		if((*m_vertices[i]).m_getvertixcolor() ==W)
			DFS(*(m_vertices[i]));
}
void Graph::printPath(vertix &src,vertix &dest)
{
	if(src.m_getvertixName()==dest.m_getvertixName())
			cout << src.m_getvertixName();
	else if (dest.m_getvertixParent() == NULL)
			cout << "No path from src to dest exist" << endl;
	else
		{	printPath(src,*(dest.m_getvertixParent()));
			cout << dest.m_getvertixName();
		}
}
int main()
{

	
	cout << "Topological DEMONSTRATION......................." << endl;
	vertix  T1(1),T2(2),T3(3),T4(4),T5(5),T6(6),T7(7),T8(8),T9(9);
	vector<vertix*> t;
	t.push_back(&T1);
	t.push_back(&T2);
	t.push_back(&T3);
	t.push_back(&T4);
	t.push_back(&T5);
	t.push_back(&T6);
	t.push_back(&T7);
	t.push_back(&T8);
	t.push_back(&T9);
	Graph G1(t);
    G1.Topologicalsort();
	cout << endl;
	return 0;
}
