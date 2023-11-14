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
	temp->prev=head;
	temp->next=head;
	
	if(head->next==head)
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
	for(temp=head->next; temp!=head && temp->data!=k; temp=temp->next);
	if(temp==head)
	{
		cout<<"does not exist ";
		return;
	}
	temp->prev->next=temp->next;
	if(temp->next!=head)
		temp->next->prev=temp->prev;
	delete temp;
}
void print()
{
	struct node *temp;
	struct node *temp1;
	cout<<"Display from front: "<<endl;
	for(temp=head->next; temp!=head; temp=temp->next)
	{
		cout<<temp->data<<"\t";
	}
	cout<<"Display from back ";
	for(temp=head->next; temp->next!=head; temp=temp->next);
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
	head->prev=head;
	head->next=head;
	while(i<10)
	{
		insBeg();
		++i;
	}
	delElement();
	print();
	
	return 0;
}
