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

void selSort()
{
	int minVal, minInd,i,j;
	
	for (i=1;i<=n-1;i++)
	{
		minVal=list[i];
		minInd=i;
		for (j=i+1;j<=n;j++)
		{
			if (list[j]<minVal)
			{
				minInd=j;
				minVal=list[j];
			}
			
		}
		swap(list[i],list[minInd]);
		cout<<"Pass "<<i<<endl;
		print();
	}	
	
}
int main()
{
	cout<<"Selection Sort"<<endl;
	get();
	selSort();
	return 0;
}
