#include<iostream>

using namespace std;

void readArray(int arr[],int size)
{
   for(int i=0;i<size;i++)
	cin >> arr[i];
}
struct crossing_subArray
{
    int left_index;
    int right_index;
    int sum;
};
int get_max_of_three(int x,int y,int z)
{
    return  z> (x >y ? x :y)? z : (x >y ? x :y);
}
void  Find_Max_Array_crossing(int low,int high,int mid,int arr[],int crossing_subArray[])
{
   int crossing_subArray_left =-99999;
   int crossing_subArray_right =-99999;
   int sum_so_far = 0;
   for(int i=mid;i<=0;i--)
     {
	sum_so_far+= arr[i];
	if(sum_so_far > crossing_subArray_left)
	{
		crossing_subArray_left = sum_so_far;
		crossing_subArray[0] = i;
	}
     }
    sum_so_far =0;
   for(int j =mid+1;j<high;j++)
   {
      sum_so_far+= arr[j];
      if(sum_so_far > crossing_subArray_right)
	{
		crossing_subArray_right = sum_so_far;
		crossing_subArray[1] = j;	
	}
   }
    crossing_subArray[2] = crossing_subArray_left+ crossing_subArray_right;
}
void Find_Max_SubArray(int arr[],int low,int high,int _output[])
{
    int _crossing[3];
    if(high ==low)
    {
       _crossing[0] = low;
       _crossing[1] = high;
       _crossing[2] = arr[low];
       return ;
    }
    else
    {
      int mid = (high+low)/2;
       int  _temp1[3] ;
       int  _temp2[3] ;
       int  _temp3[3] ;
       Find_Max_SubArray(arr,low,mid,_temp1);
       Find_Max_SubArray(arr,mid+1,high,_temp2);
       Find_Max_Array_crossing(low,high,mid,arr,_temp3);
       int sum = get_max_of_three(_temp1[2],_temp2[2],_temp3[2]);
       if(sum == _temp1[2]){ _output[0]=_temp1[0];_output[1] =_temp1[1];_output[2] =_temp1[2];return;}
       else if(sum == _temp2[2]) {_output[0] =_temp2[0];_output[1] =_temp2[1];_output[2]=_temp2[2];return; }
       else {_output[0] =_temp3[0];_output[1] =_temp3[1];_output[2]=_temp3[2];return;} 
 
    } 
}
int main()
{
   int inputArray[16];
   readArray(inputArray,16);
   int _output[3];
   Find_Max_SubArray(inputArray,1,16,_output);
   std::cout << _output[2]  << ".." << _output[1] << ".." << _output[0];    
}
