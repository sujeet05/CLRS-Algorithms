#include<iostream>
#include <math.h>

#define size 10
using namespace std;

int find_maxOf_three(int x,int y,int z)
{
		return (x>y)?(x>z?x:z ):(y>z ?y:z);
}

int parent(int i) {return floor((i-1)/2);}
int left(int i){return ((2*i)+1);}
int right(int i){return( (2*i)+2);}

void printArray(int arr[],int n)
{
	for(int i =0;i<n;i++)
			cout << arr[i] << "..";
	cout<<endl;
}
void swap(int *x,int *y)
{
    int temp = *x;
	*x= *y;
	*y=temp;
}
void Max_HeapIFY(int arr[],int i)
{
    int no_of_subtree = floor((size-1)/2);
	for(int i =0;i< no_of_subtree;i++)
	{
		int left_index = left(i);
		int right_index = right(i);
		int largest = find_maxOf_three(arr[left_index],arr[right_index],arr[i]);
		int largest_index = 0;
		if(arr[i] >=largest ) largest_index = i;
		else if (arr[left_index] >= largest) largest_index =left_index;
		else 
			largest_index = right_index;
		if(i!= largest_index)
			swap(arr[i],arr[largest_index]);
	}
}
int main()
{
	std::cout << find_maxOf_three(4,5,2);
	std::cout << find_maxOf_three(7,5,2);
	std::cout << find_maxOf_three(4,5,10);
	std::cout << endl;
	std::cout << parent(9);
	std::cout << left(4);
	std::cout << right(4) << endl;
	int arr[10] ={16,4,10,14,22,9,3,2,8,1};
//	swap(&arr[0],&arr[1]);
	printArray(arr,10);
	std::cout << "End test utility..." << endl;
	Max_HeapIFY(arr,0);
	printArray(arr,10);
}

