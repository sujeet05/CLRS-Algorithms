#include<iostream>

#define size 12
using namespace std;

void printArray(int arr[],int n)
{
		for(int i =0;i<n;i++)
				std::cout << arr[i]<< "..";
		cout << endl;
}
void swap(int *x,int *y)
{
		int temp =*x;
		*x= *y;
		*y = temp;
}
int partition(int arr[],int p,int r)
{
	int pivot = arr[r];
	int i =p-1;
	for(int j=p;j<=r-1;j++)
	{
		if(arr[j]< pivot)
		{
				i++;
		  swap(&arr[i],&arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}
int main()
{
   int arr[size] ={13,19,9,5,12,8,7,4,21,2,6,11};
   printArray(arr,12);
   partition(arr,0,11);   
   printArray(arr,12);
   int arr1[8] ={2,8,7,1,3,5,6,4};
   printArray(arr,8);
   partition(arr1,0,7);   
   printArray(arr1,8);
}
