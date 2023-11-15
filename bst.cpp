#include <iostream>
using namespace std;

struct node
{
	int val;
	struct node *left;
	struct node *right;
} *root=NULL;

typedef struct node * nodeptr;

void ins(nodeptr &t, int k)
{
	if(t==NULL)
	{
		t=new node;
		t->val=k;
		t->left=t->right=NULL;
		return;
	}
	if(k<t->val)
		ins(t->left,k);
	else if(k>=t->val)
		ins(t->right,k);
	/*else
	{
		cout<<"Duplicates not allowed ";
		return;
	}*/
}

void preorder(struct node *t)
{
	if(t!=NULL)
	{
		cout<<t->val;
		cout<<"\t";
		preorder(t->left);
		cout<<"\t";
		preorder(t->right);
		cout<<"\t";
	}
}

void postorder(struct node *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		cout<<"\t";
		postorder(t->right);
		cout<<"\t";
		cout<<t->val;
		cout<<"\t";
	}
}


void inorder(struct node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<"\t";
		cout<<t->val;
		cout<<"\t";
		inorder(t->right);
		cout<<"\t";
	}
}

int deletemin(nodeptr &t)
{
	int c;
	if(t->left==NULL)
	{
		c=t->val;
		t=t->right;
		return c;
	}
	else 
	{
		c=deletemin(t->left);
		return c;
	}
}

void del(nodeptr &t,int k)
{
	nodeptr d;
	if  (t==NULL)
	{
		cout<<"Value does not exist ";
		return ;	
	}	
	if(k<t->val)
		del(t->left,k);
	else if(k>t->val)
		del(t->right,k);
	else		
	{
		if ((t->left==NULL) && (t->right==NULL))
		{
			d=t;
			cout<<t->val<<"deleted ";
			t=NULL;
			delete d;
		}
		else if ((t->left!=NULL) && (t->right==NULL))
		{
			d=t;
			cout<<t->val<<"deleted ";
			t=t->left;
			delete d;
		}
		else if ((t->left==NULL) && (t->right!=NULL))
		{
			d=t;
			cout<<t->val<<"deleted ";
			t=t->right;
			delete d;
		}
		else
		{
			t->val=deletemin(t->right);
		}
	}
}


/*int deletemax(nodeptr (*t))
{
	int c;
	if((*t)->right=NULL)
	{
		c=t->val;
		(*t)=(*t)->left;
		return c;
	}
	else 
	{
		c=deletemin((*t)->right);
		return c;
	}
}*/

void search(struct node *t, int k)
{
	if(t==NULL)
	{
		cout<<"No such element ";
		return;
	}
	if(k<t->val)
		search(t->left,k);
	else if(k>t->val)
		search(t->right,k);	
	else
	{
		cout<<"element "<<k<<"found ";
		return;
	}
		
}


int main()
{
int c=1;
int ch; 
int data;
cout<<"BINARY SEARCH TREE"<<endl;
cout<<endl;
	while(c==1)      //MAIN PROGRAM STARTS HERE 
	{
		cout<<"Enter your choice: ";
		cout<<"1- Insert  2-Preorder 3- Postorder 4-Inorder 5-delete 6-search ";
		cin>>ch;
		switch(ch)
		{
			case 1:	
				cout<<"data? "; 
				cin>>data;
				ins(root,data);	
				break;		
			case 2:	
				cout<<"Preorder ";
				preorder(root);
				break;
			case 3:	
				cout<<"postorder ";
				postorder(root);
				break;		
			case 4:	
				cout<<"inorder ";
				inorder(root);	
				break;
			 case 5:	
				cout<<"data? "; 
				cin>>data;
				del(root,data);	
				break;		
			case 6:	
				cout<<"data? "; 
				cin>>data;
				search(root,data);	
				break;
			default: 
				cout<<"Enter choice: (1-7)! ";
		}
		//print();
		cout<<"\nDo you want to continue (1 or 0)? ";
	
		cin>>c;
	}	
	return 0;
	
}
















