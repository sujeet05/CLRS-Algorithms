#include<iostream>

using namespace std;

void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
			cout<< arr[i] << "..";
	cout << endl;
}
void swap(int *x,int *y)
{
	int temp =*x;
	*x =*y;
	*y = temp;
}

int main()
{
	return 0;
}
