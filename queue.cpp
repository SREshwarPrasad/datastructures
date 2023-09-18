//QUEUE PROBLEM RECTIFIED 

#include<iostream>
#define max 100
using namespace std;
int n, r=0,f=1, queue[max];
int isempty()
{
	return (r<f)?1:0;
}
int full()
{
	return (r==n)?1:0;
}

int enqueue()
{
	if(full())
	{
		cout<<"Queue full...";
		return 1;
	}
	int element; 
	cout<<"Enter element: ";
	cin>>element;
	r+=1;
	queue[r]=element;
}

int dequeue()
{
	if(isempty())
	{
		cout<<"Queue empty...";
		return -1;
	}
	int t=queue[f];
	 f+=1; 
	return t;
	
}

void print()
{
	cout<<"Queue items: ";
	for(int i=f; i<=r; i++)	
	{
		cout<<queue[i]<<" ";
	}
}

int main()
{
int c=1;
int ch;
cout<<"QUEUE USING ARRAYS"<<endl;
cout<<"Maximum No. of elements? "; 
cin>>n;
cout<<endl;

	while(c==1)      //MAIN PROGRAM STARTS HERE 
	{
		cout<<"Enter your choice: ";
		cout<<"1- Enqueue  2-Dequeue ";
		cin>>ch;
		switch(ch)
		{
			case 1:	enqueue();	break;		
			case 2:	dequeue();	break;
			default: cout<<"Enter choice: 1 or 2! ";
		}
		print();
		cout<<"\nDo you want to continue (1 or 0)? ";
	
		cin>>c;
	}	
	return 0;
}
