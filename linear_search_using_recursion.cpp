#include<iostream>
#define max 100
using namespace std;
int list[max];
int n,k;
void get()
{
	cout<<"No of elements: ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>list[i];
	}
	cout<<"key? ";
	cin>>k;
}
int lin_search(int m, int k)
{	int p;
	if(m==-1 || list[m]==k)
		return m;
	else
		{
			p=lin_search(m-1,k);
			return p;
		}
}
int main()
{
	get();
	int t=lin_search(n,k);
	if(t==-1)
		cout<<"KEY NOT FOUND...";
	else
		cout<<"KEY FOUND IN "<<t<<"th POSITION...";
return 0;
}
