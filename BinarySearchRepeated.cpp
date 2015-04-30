#include<iostream>
#include<math.h>

using namespace std;

int BinarySearch(int arr[],int p,int q,int element)
{
		int k = floor((p+q)/2);
		if(k >0 && k < 10)
		{
			if(element < arr[k])
				return	BinarySearch(arr,p,k,element);
			else if(element > arr[k])
				return BinarySearch(arr,k+1,q,element);
			else 
			{
				if(element ==arr[k-1])
					return BinarySearch(arr,p,k-1,element);
				else
					return k;
			}	
		}
}
int main()
{
	int repeated_arr[10] ={3,3,3,2,2,2,2,2,3,3};
	cout << BinarySearch(repeated_arr,0,9,2) << endl;
}
