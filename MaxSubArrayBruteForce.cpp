#include<iostream>
#include<vector>

using namespace std;
int getsum(vector<int>v,int start,int end)
{
		int sum =0;
		for(int i=start;i<end;i++)
			sum+= v[i];
	return sum;
}
int max_sum_subarray(vector<int> v)
{
		int sum=-99999;
		for(int i=1;i<=v.size();i++)
		{
			for(int start=0;start<v.size()-i;start++)
				{
					if(getsum(v,start,start+i) > sum)
						sum= getsum(v,start,i+start);
				}
		}
	return sum;
}
int main()
{
	vector<int> v= {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,-7};
	cout << "Max sum of subarray:" << max_sum_subarray(v)<< endl;
	vector<int> v1= {-13,-3,-25,-20,-3,-16,-23,-18,-20,-7,-12,-5,-22,-15,-4,-7};
	cout << "Max sum of subarray:" << max_sum_subarray(v1)<< endl;
	return 0;
}
