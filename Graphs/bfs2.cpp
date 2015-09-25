#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int PARENT = -1;
enum COLOR {
		WHITE, GRAY, BLACK
};

class vertex {

		int parent;
		COLOR color;
		int id;

		public:
			vertex(int _id,int _parent=PARENT, COLOR _color=WHITE)
					:id(_id), parent(_parent), color(_color) {}

			int getParent() { return parent; }
			int getColor()  { return color; } 
			int getId()     { return id; }
			void setParent(int _parent) { parent = _parent; }
			void setColor(COLOR _color)  { color =_color; } 
			void setId(int _id)     { id = _id; }
};

class graph {
		vector<vertex> vertices;
		vector<vector<int> > adj;
		public:
		graph(vector<vertex>& _vertices):vertices(_vertices) {
				for(int i=0; i<vertices.size(); ++i) {
						vector<int> v;
						adj.push_back(v);
				}
				init();
		}

		void addEdge(vertex u, vertex v) {
				adj[u.getId()].push_back(v.getId());
		}
		void init() {
				addEdge(vertices[1],vertices[2]);
				addEdge(vertices[1],vertices[4]);
				addEdge(vertices[2],vertices[5]);
				addEdge(vertices[3],vertices[5]);
				addEdge(vertices[3],vertices[6]);
				addEdge(vertices[4],vertices[2]);
				addEdge(vertices[5],vertices[4]);
				addEdge(vertices[6],vertices[6]);
		}

		void bfs(vertex s){

				queue<int> q;
				vertices[s.getId()].setColor(GRAY);
				q.push(s.getId());
				while(!q.empty()) 
				{
					int v = q.front(); q.pop();
					for(auto i = adj[v].begin(); i!=adj[v].end();++i){
							if( vertices[*i].getColor() == WHITE){
									vertices[*i].setColor(GRAY);
									vertices[*i].setParent(v);
									q.push(*i);
							}
					}
					vertices[v].setColor(BLACK);
				}
		}
		void path(vertex s,vertex d){
			vertex _s = vertices[s.getId()];
			vertex _d = vertices[d.getId()];

			if(_s.getId() == _d.getId()) cout<< _s.getId() << " ";
			else if(_d.getParent() == PARENT) cout<<"No path\n";
			else{
				path(_s,_d.getParent());
				cout<< _d.getId() << " ";
			}	
		}
};

int main() {

		vertex v0(0),v1(1),v2(2),v3(3),v4(4),v5(5),v6(6);
		vector<vertex> v = {v0,v1,v2,v3,v4,v5,v6};

		graph g(v);
		g.bfs(v1);
		g.path(v1,v6);

		return 0;
}
