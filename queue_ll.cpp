#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
};
struct node *f=NULL;
struct node *r=NULL;

void enqueue()
{
	struct node *temp;
	temp=new node;
	cin>>temp->val;
	temp->next=NULL;
	if(r==NULL && f==NULL)
	{
		f=temp;
		r=temp;
	}
	else
	{
		r->next=temp; 
		r=temp;
	}
}
void dequeue()
{
	struct node *temp;
	temp=f;
	cout<<temp->val<<" deleted ";
	f=f->next;
	/*if (f==NULL)
	{
		r=NULL;
	}*/
	delete temp;
}
void print()
{
	struct node *temp;
	for(temp=f; temp!=NULL;temp=temp->next)
	{
		cout<<temp->val<<"\t";
	}
}
int main()
{
		int ch=1;
	int c;
	cout<<"Queue using Linked List"<<endl;
	while(ch==1)
	{	cout<<"1- enqueue 2-dequeue: ";
		cin>>c;
		switch(c)
		{
			case 1:
			{
				cout<<"Enter element to be pushed: ";
				enqueue();
				cout<<"Elements: ";
				print();
				break;
			}
			case 2:
			{
				dequeue();
				cout<<"Elements ";
				print();
				break;
			}
			default:
			{
				cout<<"enter choice 1 or 2 ";
			}
		}
		//print();
		cout<<"\nproceed-1 quit-0 "; 
		cin>>ch;
	}
}
