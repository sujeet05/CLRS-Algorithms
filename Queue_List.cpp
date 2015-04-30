#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *next;
}*head=NULL;
void display()
{
	struct node *traversal = head;
	while(traversal)
		{
			cout << traversal->data << "... ";
			traversal = traversal->next;
		}
	cout << endl;
}
struct node* search(struct node *list,int key)
{
	struct node *traversal = head;
	while(traversal != NULL)
		{
				if(traversal->data ==key)
				return traversal;
				traversal= traversal->next;
		}
	return traversal;
}
void dequeue(struct node *list)
{
		struct node* temp = head;
		head = head->next;
		delete temp;	
}

void Enqueue(struct node *list,int key)
{
		struct node* temp = new struct node;
	    temp->data = key;
		temp->next = NULL;
		struct node *traversal = head;
		if(!traversal) head = temp;
		else
		{
			while(traversal->next!= NULL)
			traversal = traversal->next;
			traversal->next = temp;
		}
}

int main()
{
  int option;
  int data;
  while(1)
  {
		  cout << "Enter 1 for Enqueue" << endl;
		  cout << "Enter 2 for Dequeue" << endl;
		  cout << "Enter 3 for search " << endl;
		  cout << "Enter 4 for show " << endl;
		  cout << "Enter 5 for Exit " << endl;
		  cin >> option;
		  switch(option)
		  {
			case 1: 
				cout << "Enter data for Enqueue" << endl;
				cin >> data;
				Enqueue(head,data);
				break;
			case 2:
				cout << "Enter data for Dequeue " << endl;
				dequeue(head);
				break;
			case 3:
				cout << "Enter data for  search " << endl;
				cin >> data;
				cout << "Searched Result: " << search(head,data);
				break;
			case 4:
				display();
				break;
			case 5:
				cout << "Thank you: " << endl;
				 exit(0);
		  }
  }
  return 0;
}
