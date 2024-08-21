#include<iostream>
#define max 100
using namespace std; 
int list[max];
int n;

void print();

void get()
{
	cout<<"No of elements: ";
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>list[i];
	}
}

void bubble_sort()
{
	for(int c=1; c<=n; c++)
	{
		for(int w=n; w>c;w--)
		{ 	
			if(list[w]<list[w-1])
			{
				swap(list[w],list[w-1]);
			}
		}
		if(c==n)
		{
			cout<<"SORTED Loop "<<c<<":"<<endl;
			print();
		}
		else
		{
			cout<<"Loop "<<c<<" : ";
			print();
			cout<<endl;
		}
			
	}
}

void print()
{
	for(int i=1;i<=n;i++)
	{
		cout<<list[i]<<"\t";
	}
	cout<<endl;
}

int main()
{
	get();
	bubble_sort();
	//print();
	return 0;
}
