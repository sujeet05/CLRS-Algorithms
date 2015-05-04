#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

void printArray(vector<int > v)
{
	for(int i=0;i<v.size();i++)
			cout<< v[i] << "..";
	cout << endl;
}
void merge(vector<int >&v,int p,int q,int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int k = p;
	vector<int> v1(n1);
	vector<int> v2(n2);
	for(int i =0;i<n1;i++,p++)
			v1[i] = v[p];
	for(int i =0;i<n2;i++,q++)
			v2[i] = v[q+1];
	int i=0;
	int j=0;
	int m =k;
	    while(i<n1 && j <n2)
		{
				if( v1[i] <= v2[j] )
				{
			 		 v[m]= v1[i];
			  		i++;
					m++;
				}
				else 
				{
					v[m]= v2[j];
					j++;
					m++;

				}
		}
		while(i<n1)
		{
			v[m]=v1[i];
			i++;
			m++;
		}
		while(j<n2)
		{
			v[m] =v2[j];
			j++;
			m++;
		}
}
void merge_sort(vector<int> &v,int p,int r)
{
	  if(p<r)
	  {
		int mid = floor((p+r)/2);
		merge_sort(v,p,mid);
		merge_sort(v,mid+1,r);
		merge(v,p,mid,r);
	  }
}
int main()
{
	   vector<int> v ={8,9,3,5,2,10,14,16,1,0,7,4,20,21};
	   printArray(v);
	   merge_sort(v,0,13);
	   printArray(v);
		return 0;
}
