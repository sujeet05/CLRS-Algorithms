#include<iostream>



using namespace std;

void printArray(int arr[],int size)
{
	for(int i=0;i<size;i++)
			cout << arr[i] << "...";
	  cout << endl;
}

void countingsort2(int input[],int output[],int size,int process[],int process_size)
{
	for(int i=0;i<size;i++)
			process[input[i]]++;
	for(int j=1;j<process_size;j++)
			process[j]=process[j]+process[j-1];
	for(int k=0;k<size;k++)
	{
			output[process[input[k]]-1]=input[k];
			process[input[k]]=process[input[k]]-1;
	}
}
void countingsort(int input[],int output[],int size,int process[],int process_size)
{
	for(int i=0;i<size;i++)
			process[input[i]]++;
	for(int j=1;j<process_size;j++)
			process[j]=process[j]+process[j-1];
	for(int k=size-1;k>=0;k--)
	{
			output[process[input[k]]-1]=input[k];
			process[input[k]]=process[input[k]]-1;
	}
}
int main()
{
	int input[8]={2,5,3,0,2,3,0,3 };
	printArray(input,8);
    int output[8]={0,0,0,0,0,0,0,0};
	int process[6]= {0,0,0,0,0,0};
	countingsort(input,output,8,process,6);
	printArray(output,8);
	cout << endl;

	int input1[11]={6,0,2,0,1,3,4,6,1,3,2};
	printArray(input1,11);
	int process1[7]= {0,0,0,0,0,0,0};
    int output1[11]={0,0,0,0,0,0,0,0,0,0,0};
	countingsort2(input1,output1,11,process1,7);
	printArray(output1,11);
}
