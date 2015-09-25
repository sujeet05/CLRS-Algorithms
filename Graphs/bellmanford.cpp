#include <iostream>
#include <map>

using namespace std;

const int INF = 1 << 30;
class weightedgraph
{
		  private:
				   map<char, map<char, int> > g;

		  void addEdge(char u, char v, int w)
				  {
						    g[u][v] = w;
						  }

						  void init()
								  {
										    addEdge('t','x',5);
										    addEdge('t','y',8);
										    addEdge('t','z',-4);
										    addEdge('x','t',-2);
										    addEdge('y','x',-3);
										    addEdge('y','z',9);
										    addEdge('z','x',7);
										    addEdge('z','s',2);
										    addEdge('s','t',6);
										    addEdge('s','y',7);
										  }
										  public:

												  weightedgraph() {init();}
										  bool bellmanford(char s) {
												    map<char, int> d;
												    for(auto i: g){
														      char v = i.first;
														      d[v] = INF;
														    }
														    d[s] = 0;
														    int count =0;
														    for(int k=0; k < g.size()-1; ++k)
																    {
																		      for(auto i: g){
																				        char u = i.first;
																				        for(auto j: g[u]) {
																						          char v = j.first;
																						          int w = g[u][v];
																						          if( d[v] > d[u] + w)
																								            d[v] = d[u] + w;
																									count++;
																						        }
																						      }
																						    }
																								cout << ".....";
																								cout << count;
																								cout << ".....";
																						    for(auto itr: d){
																								      cout<< itr.first << " " << itr.second << endl;
																								    }
																								    return false;
																								  }
};
int main ()
{
		    weightedgraph g;
		    g.bellmanford('s');
}

