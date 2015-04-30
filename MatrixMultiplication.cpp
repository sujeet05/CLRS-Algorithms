#include<iostream>

using namespace std;
#if(0)
void printArray(int arr[3][3],int row,int col)
{
     for(int i=0;i<row;i++)
	{
	   std::cout << endl;
	   for(int j=0;j<col;j++)
		std::cout << *((*arr)+(i*j)+j) << "..";
	//	std::cout << arr[i][j] << "..";// another way of manipulating the array 
	}
}
#endif
void printArray(int arr[][3],int row,int col)
{
    for(int i =0;i<row;i++)
	for(int j=0; j<col;j++)
    		std::cout << arr[row][col] << "...";
}
int main()
{
   int arr1[3][3] ={{1,2,3},{4,5,6},{7,8,9}};
   int arr2[3][3] ={{2,3,4},{6,5,4},{2,0,8}};
   int arr3[3][3];
   printArray(arr1,3,3);
   std::cout << endl;
   printArray(arr2,3,3);
   std::cout << endl;
   for(int i =0;i<3;i++)
    {
       for(int j =0; j <3; j++)
	{
	  arr3[i][j]=0;
          for(int k =0;k<3;k++)
        	arr3[i][j]+= (arr1[i][k])*(arr2[k][j]);
	}
    } 
   printArray(arr3,3,3);
}
