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
			Queue(int _length,int _head=0,int _tail=0,int* _array=NULL);
			~Queue();
			bool IsFull(){return head==tail+1 ? true:false;}
			bool IsEmpty(){return head==tail ? true:false;}
			void Enqueue(int data);
			int Dequeue();
			void show();
			int tail;
			int head;
	private:
			//int head;
			//int tail;
			int length;
			int *Array;
			int getlength(){return length;}
};

void ReadInput( Queue &q)
{
	int input;
	int num;
	cout <<  "Hoe many record to be inserted : " << endl;
	cin >> num;
	for(int i=0;i<num;i++)
	{	
	    cin >> input;
		 q.Enqueue(input);
	}
}

Queue::Queue(int _length,int _head,int _tail,int* _array):length(_length),head(_head),tail(_tail),Array(_array)
{
	Array = new int[length];
}
Queue::~Queue()
{
		delete Array;
}
void Queue::Enqueue(int data)
{
		if(!IsFull())
		{
			*(Array+tail) = data;
			if(tail==getlength()-1) 
				tail = 0;
			else
				++tail;
		}
		else
		{
			cout << "Overflow.." << endl;
		}
}
int Queue::Dequeue()
{
		if(!IsEmpty())
		{
			int key = *(Array+head);
			*(Array+head) =-99;
			if(head == getlength()-1)
				head =0;
			else
				head++;
			return key;
		}
		else 
		{
			cout << "underflow.." << endl;
			return -1;
		}
}
void Queue::show()
{
		if(!IsEmpty())
		{
			if(tail > head)
				for(int i=head;i< tail;i++)
					cout << *(Array+i)<< " ";
			else
			{
				for(int i =head;i<getlength();i++)
					cout << *(Array+i)<< " ";
			    for(int j=0;j<=tail;j++)
					cout << *(Array+j) << " ";
			}
		}
		else
		 cout << "No element..." << endl; 
}
int main()
{
	int size;
	cout << "input of the Queue size .." << endl;
    cin >> size;	
	Queue q(size);
	ReadInput(q);
	q.show();
	cout << "head and tail value " << q.head << "..." << q.tail << endl;
	cout << q.Dequeue() << " ";
	cout << q.Dequeue()<< " ";;
	cout << q.Dequeue()<< " ";
	cout << q.Dequeue()<< " " << endl;
	cout << "head and tail value " << q.head << "..." << q.tail << endl;
	q.show();
	q.Enqueue(11);
	cout << "head and tail value " << q.head << "..." << q.tail << endl;
//	q.Enqueue(11);
//	q.Enqueue(11);
//	q.Enqueue(11);
	q.Enqueue(11);
	cout << "head and tail value " << q.head << "..." << q.tail << endl;
	q.show();
	return 0;
}
