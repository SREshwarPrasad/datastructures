# include <iostream>
using namespace std;
struct node
{
	int val;
	struct node *next;
}*head=NULL;
int n=0;
void insBeg(int v)
{
	struct node *temp;
	temp=new node;
	/*cout<<"Value ?\n";
	cin>>val;*/
	temp->val=v;
	temp->next=NULL;
	if (head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
	n=n+1;
}
void insLast(int v)
{
	if (head==NULL) // If the list is empty
	{
		insBeg(v);
		return;
	}
	struct node *temp, *curr;
	temp=new node;
	temp->val=v;
	temp->next=NULL;
	for (curr=head;curr->next!=NULL;curr=curr->next);
	curr->next=temp;
	n=n+1;
	
	
}

void insPos(int v, int p)
{
	 if (p==1)
	 {
	 	  insBeg(v);
	 	  return;
	 }
	 if (p==n+1)
	 {
	 	insLast(v);
	 	return;
	 }
	 if (p<1 || p > n+1)
	 {
	 	cout<<"Enter valid position !";
	 	return;
	 }
	int i;
	struct node *temp, *curr, *prev;
	temp=new node;
	temp->val=v;
	temp->next=NULL;
	for (i=1,prev=head, curr=head;curr!=NULL&&i!=p ;prev=curr, curr=curr->next,i++);
	
	temp->next=curr;
	prev->next=temp;
	n=n+1;
	
}

void delBeg()
{
	struct node *temp;
	if (head!=NULL)
	{
		cout<<head->val<<" deleted !"<<endl;
		temp=head;
		head=head->next;
		n=n-1;
		delete temp;
	}
	else
		cout<<"Empty list !"<<endl;
}

void delLast()
{
	struct node *temp, *prev, *curr;
	if (head!=NULL)
	{
		if (head->next==NULL) // Only one node exists
		{
			delBeg();
			return;
		}
		for (prev=head, curr=head; curr->next!=NULL; prev=curr, curr=curr->next);
		cout<<curr->val<<" deleted !"<<endl;
		prev->next=curr->next;
		delete curr;
		n=n-1;
	}
	else
		cout<<"Empty list !"<<endl;

}

void delVal(int v)
{
	struct node *temp, *prev, *curr;
	if (head!=NULL)
	{
		if (head->val==v) // Only one node exists
		{
			delBeg();
			return;
		}
		for (prev=head, curr=head; curr!=NULL && curr->val!=v; prev=curr, curr=curr->next);
		if (curr->val==v)
		{
			cout<<curr->val<<" deleted !"<<endl;
			prev->next=curr->next;
			delete curr;
			n=n-1;
		}
		else
			cout<<"No such value exists \n";
	}
	else
		cout<<"Empty list !"<<endl;

}
void delPos(int p)
{
	struct node *temp, *prev, *curr;
	int i;
	if (head!=NULL)
	{
		if (p==1) // Only one node exists
		{
			delBeg();
			return;
		}
		if (p==n)
		{
			delLast();
			return;
		}
		if (p<1 || p>n)
		{
			cout<<"Invalid position !\n";
			return;
		}
		for (i=1, prev=head, curr=head; curr!=NULL && i!=p; prev=curr, curr=curr->next,i++);
		if (i==p)
		{
			cout<<curr->val<<" deleted !"<<endl;
			prev->next=curr->next;
			delete curr;
			n=n-1;
		}
		else
			cout<<"No such value exists \n";
	}
	else
		cout<<"Empty list !"<<endl;

}

void print()
{
	struct node *t;
	for (t=head;t!=NULL;t=t->next)
		cout<<t->val<<"-->";
	cout<<endl;
}

int main()
{
	int c=1, v, p;
	int ch;
	cout<<"Singly Linked List"<<endl;
	cout<<endl;

	while(c==1)      //MAIN PROGRAM STARTS HERE 
	{
		cout<<"Enter your choice: ";
		cout<<"1- Insert at the Beginning \n";
		cout<<"2- Insert at the Last \n";		
		cout<<"3- Insert in a Given Position \n";
		cout<<"4- Delete from Beginning \n";
		cout<<"5- Delete at the Last \n";		
		cout<<"6- Delete by Value \n";
		cout<<"7- Delete from a Given Position \n";
		cin>>ch;
		switch(ch)
		{
			case 1:	
					cout<<"Value ?\n";
					cin>>v;
					insBeg(v);	
					break;
			case 2:	
					cout<<"Value ?\n";
					cin>>v;
					insLast(v);	
					break;
			case 3:	
					cout<<"Value ?\n";
					cin>>v;
					cout<<"Position ?\n";
					cin>>p;
					insPos(v,p);	
					break;
			case 4:	
					delBeg();	
					break;
			case 5:	
					delLast();	
					break;
			case 6:	
					cout<<"Value ?\n";
					cin>>v;
					delVal(v);	
					break;		
			case 7:	
					cout<<"Position ?\n";
					cin>>p;
					delPos(p);	
					break;
			
			default: cout<<"Enter valid choice";
		}
		print();
		cout<<"\nDo you want to continue (1 or 0)? ";
	
		cin>>c;
	}	
	
	
	return 0;
}
