#include<iostream>

using namespace std;

class stack
{
public:
	stack(int _top=-1):top(_top){}
	~stack(){}
	bool isEmpty(){return top==-1? true:false;}
	void push(int data){arr[++top]=data;}
	int pop(){return isEmpty()? -1 : arr[top--];}
	void display(){for(int i=top;i>=0;i--)cout << arr[i] << " ";cout <<endl;}
private:
		int top ;
		int arr[10];
};
int main()
{
	stack s;
	s.push(10);		
	s.push(20);		
	s.push(30);		
	s.push(40);		
	s.push(50);
   cout <<	s.pop();
   cout <<	s.pop();
   cout <<	s.pop();
   cout <<	s.pop();
   cout <<	s.pop();
   cout <<	s.pop();
	s.display();	
}
