#include<iostream>
#include<vector>
using namespace std;

int linearsearch(vector<int> v,int n)
{
	for(int i=0;i<v.size();i++){
			if(n==v[i])return i;}
			 return -1;
}


int main()
{
	vector<int> v {8,5,7,6,2,0,9,11,4};
	std::cout << linearsearch(v,9) << endl;
	std::cout << linearsearch(v,8) << endl ;
	std::cout << linearsearch(v,4) << endl ;
	std::cout << linearsearch(v,22) << endl ;
}
