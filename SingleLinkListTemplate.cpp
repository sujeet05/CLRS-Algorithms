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
void insertBegining(struct node *list,int key)
{
		struct node* temp = new struct node;
	    temp->data = key;
		temp->next = head;
		head = temp;
			
}

void insertEnd(struct node *list,int key)
{
}
struct node * remove(struct node *list,int key)
{

}
int main()
{
  int option;
  int data;
  while(1)
  {
		  cout << "Enter 1 for insert at Beginning" << endl;
		  cout << "Enter 2 for insert at End" << endl;
		  cout << "Enter 3 for search " << endl;
		  cout << "Enter 4 for Remove " << endl;
		  cout << "Enter 5 for show " << endl;
		  cout << "Enter 6 for Exit " << endl;
		  cin >> option;
		  switch(option)
		  {
			case 1: 
				cout << "Enter data for Beginning Insertion" << endl;
				cin >> data;
				insertBegining(head,data);
				break;
			case 2:
				cout << "Enter data for End Insertion " << endl;
				cin >> data;
			//	insertEnd(head,data);
				break;
			case 3:
				cout << "Enter data for  search " << endl;
				cin >> data;
				cout << "Searched Result: " << search(head,data);
				break;
			case 4:
				cout << "Enter data for remove " << endl;
				cin >> data;
				//search(head,data);
				break;
			case 5:
				display();
				break;
			case 6:
				cout << "Thank you: " << endl;
				 exit(0);
		  }
  }
  return 0;
}
