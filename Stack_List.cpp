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
			cout << traversal->data << endl;
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
void push(struct node *list,int key)
{
		struct node* temp = new struct node;
	    temp->data = key;
		temp->next = head;
		head = temp;
			
}

void pop(struct node *list)
{
 	struct node * poped = head;
	head = head->next;
	delete poped;

}
int main()
{
  int option;
  int data;
  while(1)
  {
		  cout << "Enter 1 for Push" << endl;
		  cout << "Enter 2 for POP" << endl;
		  cout << "Enter 3 for search " << endl;
		  cout << "Enter 4 for show " << endl;
		  cout << "Enter 5 for Exit " << endl;
		  cin >> option;
		  switch(option)
		  {
			case 1: 
				cout << "Enter data for PUSH" << endl;
				cin >> data;
				push(head,data);
				break;
			case 2:
				pop(head);
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
