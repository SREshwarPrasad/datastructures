# include <iostream>
# define max 10
using namespace std;
struct node 
{
	int val;
	struct node *next;	
}*head[max];
int h[max];

void init()
{
	int i;
	for (i=0;i<max;i++)
	{
		head[i]=NULL;
		h[i]=0;
	}	
}
void insert(int index, int v)
{
	struct node *temp;
	temp=new node;
	temp->val=v;
	temp->next=NULL;
	if (head[index]==NULL)
		head[index]=temp;
	else
	{
		temp->next = head[index];
		head[index]=temp;
	}
	h[index]=h[index]+1;

}
void print()
{
	int i;
	struct node *t;
	for (i=0;i<max;i++)
	{
		
		if (h[i]!=0)
			{
				cout<<"Index "<<i<<endl;
				for (t=head[i];t!=NULL;t=t->next)
					cout<<t->val<<"-->";
				cout<<endl;
			}
		
	}
	
}
void del(int index, int v)
{
	struct node *t1, *t2, *t;
	if (head[index]->val==v)// If the search element is in the first index
	{
		cout<<head[index]->val<<" deleted \n";
		h[index]=h[index]-1;
		head[index]=head[index]->next;
		return;			
	}
	// If the search element is not in the first index
	t1=head[index];
	t2=head[index];
	for (;t2!=NULL && t2->val!=v;t1=t2,t2=t2->next);
	if (t2!=NULL)
	{
		cout<<t2->val<<" deleted \n";
		t1->next=t2->next;
		delete t2;
		h[index]=h[index]-1;
	}
	else
		cout<<"Value not found \n";
}
int main()
{
	int c=1,v;
	int ch;
	init();
	cout<<"Hashed Search"<<endl;
	int ind;
	while(c==1)      //MAIN PROGRAM STARTS HERE 
	{
		cout<<"Enter your choice: ";
		cout<<"1- Insert  2-Delete ";
		cin>>ch;
		switch(ch)
		{
			case 1:	
					cout<<"Element ?"<<endl;
					cin>>v;
					ind=v%max;
					insert(ind,v);	
					break;		
			case 2:	
					cout<<"Delete Element ?"<<endl;
					cin>>v;
					ind=v%max;
					if (h[ind]==0)
						cout<<"No list exists in that location \n";
					else
						del(ind,v);	
					break;
			default: cout<<"Enter choice: 1 or 2! ";
		}
		print();
		cout<<"\nDo you want to continue (1 or 0)? ";
	
		cin>>c;
	}	
	return 0;
}
