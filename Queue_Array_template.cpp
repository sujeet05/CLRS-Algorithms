#include<iostream>

using namespace std;

void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
			cout<< arr[i] << "..";
	cout << endl;
}
void swap(int *x,int *y)
{
	int temp =*x;
	*x =*y;
	*y = temp;
}
class Queue
{
	public:
			Queue(int _length,int _head=1,int _tail=1,int* _array=NULL);
			~Queue();
	private:
			int head;
			int tail;
			int length;
			int *Array;
};

Queue::Queue(int _length,int _head,int _tail,int* _array):length(_length),head(_head),tail(_tail),Array(_array)
{
	Array = new int[length];
}
Queue::~Queue()
{
		delete Array;
}
int main()
{
	int size;
	cout << "input of the Queue size .." << endl;
    cin >> size;	
	Queue q(size);
	return 0;
}
