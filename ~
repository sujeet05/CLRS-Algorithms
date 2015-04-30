#include<iostream>

using namespace std;

void printArray(int arr[],int size)
{
	for(int i=0;i<size;i++)
			cout << arr[i] << "...";
	   cout << endl;
}
void insert(int arr[],int size,int key)
{
	int i =size;
	for(;i >=0 && arr[i] > key;--i)
		arr[i+1] = arr[i];
		arr[i+1] = key;
}
void insertionsort(int arr[],int size)
{
   if(size >= 1)
   {
		   insertionsort(arr,size-1);
		   insert(arr,size-1,arr[size]);
   }
}
int main()
{
	cout << "test utility "<< endl;
	int arr[6] = {31,41,59,26,41,58};
	printArray(arr,6);
	insertionsort(arr,5);
	printArray(arr,6);
	int arr1[6] = {5,2,4,6,1,3};
	printArray(arr1,6);
	insertionsort(arr1,5);
	printArray(arr1,6);
}
