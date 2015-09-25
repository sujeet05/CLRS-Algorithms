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
				int m_getvertixName() {return m_name;}
				vertix* m_getvertixParent() {return m_parent;}
				color m_getvertixcolor() {return m_clr;}
				void set_vertixParent(vertix* _v) {m_parent = _v;}	
				void set_vertixcolor(color clr) {m_clr =clr;}
};

class Graph
{
		public:
			Graph(vector<vertix*>& _v,list<vertix> *_e=NULL):m_vertices(_v){m_edges = new list<vertix*>[m_vertices.size()]; m_InitDFS(); }
		//	Graph(vector<vertix*>& _v,list<vertix> *_e=NULL):m_vertices(_v){m_edges = new list<vertix*>[m_vertices.size()]; m_InitTopo(); }
			void m_AddEdge(vertix &x,vertix &y);
			void m_Init();
			void m_InitDFS();
			void m_InitTopo();
			void m_printEdges();
			void BFS(vertix& src);
			void BuildDFS();
			bool DFS(vertix& src);
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
void Graph::m_InitDFS()
{
		m_AddEdge(*m_vertices[0],*m_vertices[1]);
		m_AddEdge(*m_vertices[0],*m_vertices[4]);
		m_AddEdge(*m_vertices[1],*m_vertices[2]);
		m_AddEdge(*m_vertices[1],*m_vertices[4]);
		m_AddEdge(*m_vertices[2],*m_vertices[3]);
		m_AddEdge(*m_vertices[3],*m_vertices[1]);
		m_AddEdge(*m_vertices[4],*m_vertices[3]);
		m_AddEdge(*m_vertices[5],*m_vertices[0]);
		m_AddEdge(*m_vertices[5],*m_vertices[4]);
		m_AddEdge(*m_vertices[6],*m_vertices[5]);
		m_AddEdge(*m_vertices[6],*m_vertices[7]);
		m_AddEdge(*m_vertices[7],*m_vertices[6]);
		m_AddEdge(*m_vertices[7],*m_vertices[5]);
}
void Graph::m_Init()
{
		m_AddEdge(*m_vertices[0],*m_vertices[1]);
		m_AddEdge(*m_vertices[0],*m_vertices[3]);
		m_AddEdge(*m_vertices[1],*m_vertices[4]);
		m_AddEdge(*m_vertices[2],*m_vertices[4]);
		m_AddEdge(*m_vertices[2],*m_vertices[5]);
		m_AddEdge(*m_vertices[3],*m_vertices[1]);
		m_AddEdge(*m_vertices[4],*m_vertices[2]);
		m_AddEdge(*m_vertices[5],*m_vertices[5]);
}
bool Graph::DFS(vertix& src)
{
		src.set_vertixcolor(G);
		for(list<vertix*>::iterator j = m_edges[src.m_getvertixName()-1].begin(); j != m_edges[src.m_getvertixName()-1].end(); j++)
		{
				if((*j)->m_getvertixcolor() ==G)
						return true;
				else if((*j)->m_getvertixcolor() ==W)
				{
						(*j)->set_vertixParent(&src);
						(*j)->set_vertixcolor(G);
						DFS(**j);
				}
		}
		  src.set_vertixcolor(B);
		  m_topoorder.push_front(&src); 
	return false;
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
void Graph::BFS(vertix& src)
{
	for(int i=0;i < m_vertices.size() ;++i)
	{
			(*m_vertices[i]).set_vertixcolor(W);
			(*m_vertices[i]).set_vertixParent(NULL);
	}
	src.set_vertixParent(NULL);
	src.set_vertixcolor(G);
	queue<vertix*> q;
	q.push(&src);
	cout << endl;
	while(!q.empty())
	{
		 vertix *v = q.front();
		 q.pop();
		 for(list<vertix*>::iterator j = m_edges[v->m_getvertixName()-1].begin(); j != m_edges[v->m_getvertixName()-1].end(); j++)
		 {
				 if((*j)->m_getvertixcolor() ==W)
				 {
					(*j)->set_vertixcolor(G);
					(*j)->set_vertixParent(&(*v));
					 q.push(&(**j));
				 }
		 }
		 v->set_vertixcolor(B);
	}
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
	cout << "BFS DEMONSTRATION......................." << endl;
#if 0
	vertix  v1(1),v2(2),v3(3),v4(4),v5(5),v6(6);
	vector<vertix* > v;
	v.push_back(&v1);
	v.push_back(&v2);
	v.push_back(&v3);
	v.push_back(&v4);
	v.push_back(&v5);
	v.push_back(&v6);
    Graph G(v);
	G.BFS(*v[0]);
    G.m_printEdges();
	cout << endl;
    G.printPath(*v[0],*v[5]);
	cout << endl;
    G.printPath(*v[0],*v[4]);
	cout << endl;
#endif
	cout << "DFS DEMONSTRATION......................." << endl;

#if 0
	vertix  D1(1),D2(2),D3(3),D4(4),D5(5),D6(6),D7(7),D8(8);
	vector<vertix* > d;
	d.push_back(&D1);
	d.push_back(&D2);
	d.push_back(&D3);
	d.push_back(&D4);
	d.push_back(&D5);
	d.push_back(&D6);
	d.push_back(&D7);
	d.push_back(&D8);
	Graph G1(d);
	G1.BuildDFS();
    G1.printPath(*d[0],*d[3]);
	cout << endl;
    G1.printPath(*d[0],*d[4]);
	cout << endl;
    G1.printPath(*d[6],*d[5]);
	cout << endl;
#endif
	
	cout << "Topological DEMONSTRATION......................." << endl;
#if 0
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
#endif
	vertix  D1(1),D2(2),D3(3),D4(4),D5(5),D6(6),D7(7),D8(8);
	vector<vertix* > d;
	d.push_back(&D1);
	d.push_back(&D2);
	d.push_back(&D3);
	d.push_back(&D4);
	d.push_back(&D5);
	d.push_back(&D6);
	d.push_back(&D7);
	d.push_back(&D8);
	Graph G1(d);
	bool cyclic =G1.DFS(D1);
	if(cyclic) cout << "Cyclic ";
	else cout << "Not Cyclic";
	return 0;
}
