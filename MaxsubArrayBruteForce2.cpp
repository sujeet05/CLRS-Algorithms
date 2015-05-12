#include<iostream>
#include<vector>

using namespace std;
void Max_sum_subArray(vector<int> v)
{
	vector<int> v1(v.size());
	v1[0]=0;
	int max_sum =-99999;
	int start_index=0;
	int end_index =0;
	for(int i=0;i<v.size();i++)
		v1[i]= v1[i-1]+v[i];
	for(int i=1;i<v.size();i++)
		for(int j=i;j<v.size();j++)
		{
			int sum = v1[j]-v1[i-1];
			if(sum> max_sum)
			{
					max_sum =sum;
					start_index =i;
					end_index =j;
			}
		}
	cout << "maxsumofsubarray:" << max_sum << "start_index:" << start_index << "end_index:" << end_index; 
}
int main()
{
	vector<int> v{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	Max_sum_subArray(v);
	return 0;
}
