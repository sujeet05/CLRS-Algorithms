#include <iostream>
#include <vector>

using namespace std;

#define mat vector<vector<int> > 
mat mul(mat a, mat b)
{
	mat c = mat (a.size(), 
					vector<int>(b[0].size(),0));
	for( int i=0; i < a.size(); ++i)
			for( int k=0; k < b.size(); ++k)
				for( int j=0; j < b[0].size(); ++j)
					c[i][j] += a[i][k] * b[k][j];
	return c;
}
void print(mat a)
{

	for( int i=0; i < a.size(); ++i){
		for( int j=0; j < a[0].size(); ++j)
				cout<< a[i][j]<< " ";
		cout<<endl;
	}
		cout<<endl;
}

int main () 
{
		mat a {{1,2,1,5}, {2,3,4,5}};
		mat b {{1,2}, {1,5}, {2,3}, {4,5}};
		mat c = mul(a,b);
		print(a);
		print(b);
		print(c);
		return 0;
}

		
	
