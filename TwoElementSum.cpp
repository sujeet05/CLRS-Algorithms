#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int> v)
{
	for(int i=0;i<v.size();i++)
			cout << v[i] << "...";
	cout << endl;
}
int find_successive_sameno(vector<int> v,int sum)
{
	int count =0;
	for(int i=0;i<(v.size()-1)/2;i++)
	{
		if(v[i]==v[i+1])
		{
		    cout << v[i] << ","<< sum-v[i]<< endl;
			++count;
		}
	}
	return count;
}
vector<int> mergevectors(vector<int>v1,vector<int>v2)
{
		vector<int> v (v1.size()+v2.size());
		v1[v1.size()]=99999;
		v2[v2.size()]=99999;
		int i=0;
		int j =0;
		for(int k=0;k<v.size();k++)
		{
			if(v1[i]<=v2[j])
			{
				v[k]=v1[i];
			    i++;
			}
			else
			{
				v[k] = v2[j];
				j++;
			}
		}
		return v;
}
void findElelmentOfgivenSum(vector<int> v,int sum)
{
    vector<int> v1(v.size());
   sort(v.begin(),v.end());
   for(int i=0;i<v.size();i++)
		   v1[i]=sum-v[i];
   sort(v1.begin(),v1.end());
   vector<int> _return= mergevectors(v,v1);
   cout << find_successive_sameno(_return,sum)<< endl;

}
int main()
{
    vector<int> v = {8,9,3,5,2,10,14,16,0,7,4,20,21};
	cout <<  "Give the sum value.. " << endl;
	int sum;
	cin >>sum;
    findElelmentOfgivenSum(v,sum);
	return 0;
}
