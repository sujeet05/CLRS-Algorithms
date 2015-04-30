#include<iostream>

using namespace std;

int InversionCount(int arr[],int n)
{
   int count =0;
   for(int i = 0;i < n;i++)
    {
       for(int j =i+1;j <n;j++)
	if(arr[i]> arr[j])
	{
	  std::cout << "(" << arr[i] << ", " << arr[j] << ")" << std::endl;
	  ++count;
	}
    }
   return count;
}
int main()
{
   int arr[6] ={5,2,4,6,1,3};
   std::cout << InversionCount(arr,6) << std::endl;
   return 0;
}
