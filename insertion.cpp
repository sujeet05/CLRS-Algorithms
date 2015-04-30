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
    for(int j=1;j<n ;j++)
    {
        int key = arr[j];
	int k = j-1;
	while(k>=0 && key < arr[k])
	{
	  	arr[k+1] =arr[k];
	  k--;
	}

	arr[k+1] = key;
    }
}
int main()
{
   int arr[6] ={5,2,4,6,1,3};
   insertion(arr,6);
   printArray(arr,6);
   return 0;
}
