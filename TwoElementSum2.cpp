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
int findElelmentOfgivenSum(vector<int> v,int sum)
{
   sort(v.begin(),v.end());
   int j = v.size()-1;
   int count=0;
   for(int i=0;i<v.size();i++)
   {
		for(; (j>=i) && (v[j] >=sum-v[i]) ;j--)
				if(v[j]==sum-v[i])
				{
					cout << v[i] << "," << v[j] << endl;
					++count;
				}
	}
   cout << endl;
   return count;

}
int main()
{
    vector<int> v = {8,9,3,5,2,10,14,16,0,7,4,20,21};
	cout << "Input elements are ..." << endl;
	printArray(v);
	cout << endl << "Give the sum value.. " << endl;
	int sum;
	cin >>sum;
    cout << "combinations are :" << endl <<  findElelmentOfgivenSum(v,sum) <<"...total count "<< endl;
	return 0;
}
