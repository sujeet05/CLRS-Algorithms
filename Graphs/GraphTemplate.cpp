#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

class Graph
{
	public:
		vector<int> vertices;
		list<int> * edges;
		void AddEdge(int x,int y);
		void Init();
		void printEdges();
	    Graph(vector<int> _v,list<int> *e=NULL):vertices(_v){edges = new list<int>[vertices.size()]; Init(); }
		

};
void Graph::printEdges()
{
		for(int i=0;i<vertices.size();i++)
		for(list<int>::iterator j = edges[i].begin(); j != edges[i].end(); j++)
			cout  << vertices[i] << "..."<<  *j << endl;
}
void Graph::AddEdge(int x,int y)
{
		edges[x-1].push_back(y);
}
void Graph::Init()
{
   AddEdge(1,2);
   AddEdge(1,4);
   AddEdge(2,5);
   AddEdge(3,5);
   AddEdge(3,6);
   AddEdge(4,2);
   AddEdge(5,4);
   AddEdge(6,6);
}
int main()
{
   vector<int> v{1,2,3,4,5,6};
   //vector<list<int>> e (v.size());
   Graph G(v);
   G.printEdges();
   return 0;
}
