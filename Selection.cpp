#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> v)
{
	for(int i=0;i<v.size();i++)
			std::cout << v[i] << "...";
	cout << endl;
}
void swap(int *x,int*y)
{
		int temp = *x;
		*x =*y;
		*y = temp;
}
vector<int> selctionsort(vector<int> v)
{
		for(int i=0;i<v.size();i++)
		{
				int key = i;
				for(int j=i;j<v.size();j++)
				{
						if(v[key] > v[j])
						 key = j;
				}
				swap(&v[i],&v[key]);
		}
	return v;
}
int main()
{
	vector<int> v {8,5,7,6,2,0,9,11,4};
	std::vector<int> result=selctionsort(v);
	display(result);
}
