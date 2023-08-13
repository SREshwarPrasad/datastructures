//Sorting //Bubble Sort

#include<iostream>
#define max 100
using namespace std;
int list[max];
int n;
void get()
{
	cout<<"No of elements: ";
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>list[i];
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

void b_sort()
{
	int last=n;
	int current=1;
	bool s= false;
	while(current<=last && s==false)
	{
		int w=last;
		s=true;
		while(w>current)
		{
			if(list[w]<list[w-1])
			{
				swap(list[w],list[w-1]);
				s=false;
			}
			w=w-1;
		}
		print();
		current=current+1;
	}
}
int main()
{
	get();
	b_sort();
	cout<<"BUBBLE SORT:"<<endl;
	print();
	return 0;
}
