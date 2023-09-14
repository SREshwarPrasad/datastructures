//Stack using linked list
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
