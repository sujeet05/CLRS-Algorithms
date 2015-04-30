#include<iostream>
#include<math.h>

using namespace std;

int BinarySearch(int arr[],int k,int element)
{
		int i =0;
		while( i <= k)
		{
			int j = floor((i+k)/2);
			if(element == arr[j])
			  return j;
		    else if(element > arr[j])
				 	i = j+1;
			else 
				
					k = j-1;
		}
}
int main()
{
	int arr[10] ={3,6,8,9,11,13,23,27,29,34};
	cout << BinarySearch(arr,10,23) << endl;
	cout << BinarySearch(arr,10,9) << endl;
	cout << BinarySearch(arr,10,13) << endl;
}
