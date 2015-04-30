#include<iostream>
#include<math.h>

using namespace std;

int BinarySearch(int arr[],int p,int q,int element)
{
		if(element < floor(arr[(p+q)/2]))
			return	BinarySearch(arr,p,floor((p+q)/2),element);
		else if(element > floor(arr[(p+q)/2]))
				return BinarySearch(arr,floor((p+q)/2+1),q,element);
		else if(element ==floor(arr[(p+q)/2]))
				return floor((p+q)/2);

}
int main()
{
	int arr[10] ={3,6,8,9,11,13,23,27,29,34};
	cout << BinarySearch(arr,0,9,23) << endl;
	cout << BinarySearch(arr,0,9,9) << endl;
	cout << BinarySearch(arr,0,9,13) << endl;
	int repeated_arr[10] ={2,2,2,2,2,2,2,2,2,2};
	cout << BinarySearch(repeated_arr,0,9,2) << endl;
}
