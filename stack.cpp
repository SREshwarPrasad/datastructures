#include<iostream>
#define max 100
using namespace std;
int n, top=0, stack[max];

int isempty()
{
	return (top==0)?1:0;
}

int full()
{
	return (top==n)?1:0;
}

void push()
{
	if (full())
	{
		cout<<"STACK OVERFLOW! CANNOT PUSH. ";
		return;
	}
	
    int element;
    cout<<"Enter elements: ";
    cin>>element;
    top=top+1;
    stack[top]=element;
}

int pop()
{
	if(isempty())
	{
		cout<<"STACK EMPTY! CANNOT POP! ";
		return -1;
	}
	int t=stack[top];
	top=top-1;
	return t;
}

void print()
{
	cout<<"Stack items: ";
	for(int i=1; i<=top; i++)	
	{
		cout<<stack[i]<<" ";
	}
}

int main()
{
int c=1;
int ch;
cout<<"STACK USING ARRAYS"<<endl;
cout<<"Maximum No. of elements? "; 
cin>>n;
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
