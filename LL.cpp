//STACK USING LINKED LIST

#include<iostream>
using namespace std;
struct node
{
  	int val;
  	struct node *next;
};

struct node *top=NULL;

int isempty()
{
  	return (top==NULL)?1:0;
}

void push()
{
  	struct node *temp;
  	temp=new node;
  	cin>>temp->val;
  	temp->next=NULL;
  	if (isempty())
  	{
  	  	top=temp;
  	}
  	else
  	{
  	  	temp->next=top;
  	  	top=temp;
  	}
}

void print()
{
  	struct node *temp;
  	for(temp=top; temp!=NULL; temp=temp->next)
  	{
  	  	cout<<temp->val<<"\t"; //a[i]
  	}
}
void pop()
{
  	struct node *temp;
  	if(!isempty())
  	{
    		temp=top;
    		cout<<"\n"<<temp->val<<" deleted";
    		top=top->next;
    		delete temp;
  	}
  	else
  	{
  		  cout<<" cannot pop.";
  	}
}

int main()
{
    int c=1;
    int ch;
    cout<<"STACK USING linked list (linked stack)"<<endl;
    cout<<endl;
  
  	while(c==1)      //MAIN PROGRAM STARTS HERE 
  	{
    		cout<<"Enter your choice: ";
    		cout<<"1- PUSH  2-POP ";
    		cin>>ch;
    		switch(ch)
    		{
      			case 1:	push();	break;		
      			case 2:	pop();	break;
      			default: cout<<"Enter choice: 1 or 2! ";
    		}
    		print();
    		cout<<"\nDo you want to continue (1 or 0)? ";
    	
    		cin>>c;
  	}	
  	
  	
  	return 0;
}

_______________________________________________________________________________________________________


//QUEUE USING LINKED LIST



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
	if (f==NULL)
	{
		r=NULL;
	}
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


















