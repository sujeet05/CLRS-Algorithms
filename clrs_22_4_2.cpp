#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef map<char,vector<char> > dag;

void dfs(dag& graph, char source,set<char>& visited, vector<char>& order)	
{
		visited.insert(source);
		for(char v: graph[source]){
				if(visited.find(v) == visited.end())
						dfs(graph, v, visited,order);
		}
		order.insert(order.begin(), source);
}
vector<char> toposort(dag& graph, char source) 
{
		vector<char> order;
		set<char> vis;
		dfs(graph,source,vis,order);
		return order;
}
int main() {

		dag g;
		
		g['m'].push_back('r');
		g['m'].push_back('q');
		g['m'].push_back('x');
		g['q'].push_back('t');
		g['n'].push_back('q');
		g['n'].push_back('u');
		g['n'].push_back('o');
		g['u'].push_back('t');
		g['o'].push_back('r');
		g['o'].push_back('s');
		g['o'].push_back('v');
		g['r'].push_back('u');
		g['r'].push_back('y');
		g['y'].push_back('v');
		g['v'].push_back('x');
		g['v'].push_back('w');
		g['s'].push_back('r');
		g['p'].push_back('o');
		g['p'].push_back('s');
		g['p'].push_back('z');
		g['w'].push_back('z');
		


		map<char, int> dp;
		dp['p'] = 1;
		for(char s: toposort(g,'p')){
				cout<<s<< " " ;
				for(char v: g[s]) dp[v] += dp[s];
		}
		cout<< dp['v'] << endl;


		return 0;
}

