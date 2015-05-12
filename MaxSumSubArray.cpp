#include <iostream>
#include <vector>
using namespace std;

int max_sum_sub_array(const vector<int>& arr)
{
	int max_overall = 0, sum = 0;
	for(int i = 0; i < arr.size(); ++i)
	{
		sum += arr[i];
		if( sum < 0 )
		{
			sum = 0;
		}
		if( max_overall < sum)
			max_overall = sum;
	}
	return max_overall;
}

int main() {
	//std::vector<int> arr = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	std::vector<int> arr = { -13, -3, -25, -20, -3, -16, -23, -18, -20, -7, -12, -5, -22, -15, -4, -7};
	//arr = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	cout << max_sum_sub_array(arr) << endl;
	return 0;
}






