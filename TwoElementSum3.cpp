#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void TwoElementSum(vector<int> v,int sum)
{
	int i=0;
	int j=v.size()-1;
	sort(v.begin(),v.end());
	while(i<j)
	{
	   if(v[i]+v[j]>sum)
			--j;
	   else if(v[i]+v[j] < sum)
			   ++i;
	   else if(v[i]+v[j]==sum)
	   {
			 cout << "Numbers are :" << v[i] << "," << v[j]<< endl;
			 i++;
	   }
	}
}

int main()
{
	int sum ;
	cout << "Give the sum value :" ;
	//cin >> sum;
	cin >>sum;
    vector<int> v ={8,9,3,5,2,10,14,16,0,7,4,20,21};
	TwoElementSum(v,sum);
	return 0;
}
