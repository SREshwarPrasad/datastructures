//DOUBLY LINKED LIST

#include <iostream>
using namespace std; 
int n;
struct node
{
	int data;
	struct node *prev, *next;
}*head;

void insBeg()
{
	struct node *temp; 
	temp= new node;
	cin>>temp->data;
	temp->prev=NULL;
	temp->next=NULL;
	
	if(head->next==NULL)
	{
		head->next=temp;
		temp->prev=head;
	}
	else
	{
		temp->next=head->next;
		temp->prev=head;
		head->next->prev=temp;
		head->next=temp;
	}
}

void delElement()
{
	struct node *temp;
	int k=5;
	for(temp=head->next; temp!=NULL && temp->data!=k; temp=temp->next);
	if(temp==NULL)
	{
		cout<<"does not exist ";
		return;
	}
	temp->prev->next=temp->next;
	if(temp->next!=NULL)
		temp->next->prev=temp->prev;
	delete temp;
}
void print()
{
	struct node *temp;
	struct node *temp1;
	cout<<"Display from front: "<<endl;
	for(temp=head->next; temp!=NULL; temp=temp->next)
	{
		cout<<temp->data<<"\t";
	}
	cout<<"Display from back ";
	for(temp=head->next; temp->next!=NULL; temp=temp->next);
	for(temp1=temp; temp1!=head; temp1=temp1->prev, n++)
	{
			cout<<temp1->data<<"\t";
			
	}cout<<"No of elements: "<<n;
}
int main()
{
	int i=1;
	head=new node;
	head->data=-1;
	head->prev=NULL;
	head->next=NULL;
	while(i<10)
	{
		insBeg();
		++i;
	}
	delElement();
	print();
	
	return 0;
}
