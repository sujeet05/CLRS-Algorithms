#include<iostream>
#include<vector>
#include<map>

using namespace std;
void addedges(map<int,map<int,int>>&v ,int u,int e,int weight)
{
		v[u][e]=weight;
}
void printedges(map<int,map<int,int>>&v)
{
	for(auto i:v)
	{ 
		  int k =i.first;
			for(auto j:v[k])
			cout << i.first <<"..."<< j.first <<"..."<< j.second << endl;
	}
}
int main()

{
	map<int,map<int,int>> edges;
	addedges(edges,1,2,10);
	addedges(edges,1,3,5);
	addedges(edges,2,3,20);
	addedges(edges,2,4,30);
	addedges(edges,4,3,40);
	printedges(edges);
}
