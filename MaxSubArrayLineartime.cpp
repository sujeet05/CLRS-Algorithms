#include<iostream>
#include<vector>
using namespace std;

void MaxSumSubArray(vector<int> v)
{
	int index_start =0;
	int index_end=0;
	int max_sum=0;
	int sum=0;
	for(int i=0;i<v.size();i++)
	{
		sum=sum+v[i];
		if(sum > max_sum)
		{
			max_sum=sum;
			index_end=i;
		}
		else if(sum < 0)
		{
			index_start=i+1;
			sum=0;
		}
	}
	cout <<"Maximum Sum: "<< max_sum << "startIndex:" << index_start << "EndIndex:" << index_end;
}

int main()
{
	vector<int> v={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	MaxSumSubArray(v);
}
