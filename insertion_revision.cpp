#include<iostream>

using namespace std;

void printArray(int arr[],int n)
{
   for(int i=0;i<n;i++)
   std::cout << arr[i];
   std::cout <<std::endl;
}

void insertion(int arr[],int n)
{
    for(int i=1;i<n ;i++)
    {
		int key = arr[i];
		int j =i-1;
			for(;j>=0 && arr[j] > key;--j)
				arr[j+1] =arr[j];
			arr[j+1] =key;// insert the key when it is less than arr[j] or if all are graterr insert at 0 index
    }
}
int main()
{
   int arr[6] ={5,2,4,6,1,3};
   insertion(arr,6);
   printArray(arr,6);
   return 0;
}
