#include<iostream>

using namespace std;

void readArray(int arr[],int size)
{
   for(int i=0;i<size;i++)
	cin >> arr[i];
}
int max_of_array(int arr[],int size)
{
	int max_index =0;
	for(int i =0;i<size;i++)
	{
		if(arr[max_index]  < arr[i])
		max_index =i;
	}
  return max_index;
}
void MaxSubArray(int arr[],int size)
{
   int arr_demarcate[size];
   int arr_sum[size];
   for(int k=0;k<size;k++)
	{
	  arr_demarcate[k]=0;
	  arr_sum[k]=-999999;
	}
   for(int i=0;i<size;i++)
   {
	int sum_so_far =0;
	for(int j=i;j<size;j++)
	{
	  sum_so_far+=arr[j];
	  if(sum_so_far > arr_sum[i])
	  {	
		arr_sum[i] = sum_so_far;
		arr_demarcate[i] =j;
	  }
	}
   }
    int start_index= max_of_array(arr_sum,size);
    int end_index = arr_demarcate[start_index];
    std::cout << "start from :" << start_index << "end it :" << end_index << "sum:" << arr_sum[start_index]; 		
}

int main()
{
   int inputArray[16];
   readArray(inputArray,16);
   MaxSubArray(inputArray,16);
}
