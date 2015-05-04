#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<int > v)
{
	for(int i=0;i<v.size();i++)
			cout<< v[i] << "..";
	cout << endl;
}
void merge(vector<int > v,int p,int q,int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int k = p;
	vector<int> v1(n1);
	vector<int> v2(n2);
	for(int i =0;i<n1;i++,p++)
			v1[i] = v[p];
	printArray(v1);
	for(int i =0;i<n2;i++,q++)
			v2[i] = v[q+1];
	printArray(v2);
	int i=0;
	int j=0;
	for(int m=k;m<r;m++)
		{
			if(v1[i] <= v2[j])
			{
			  v[m] = v1[i];
			  i++;
			}
			else 
			{
				v[m]=v2[j];
				j++;

			}
		}
	printArray(v);
}

int main()
{
	   vector<int> v ={8,9,3,5,2,10,14,16,1,0,7,4,20,21};
	   printArray(v);
	   merge(v,4,8,12);
		return 0;
}
