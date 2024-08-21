// BINARY SEARCH USING RECURSION

#include<iostream>
#define max 100 //for aesthetic declaration purpose only 
using namespace std;

int n,k,low,high,mid; //no of elements, key to be searched, lowest, highest and middle index val respectively
int list[max];      //declaring list 

void get()  //get elements
{
	cout<<"No of elements (ascending): "; //always give list value in ascending order only 
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>list[i];
	}
	cout<<"key? ";
	cin>>k;
}
int binary(int low, int high, int k)
{	
	int t;
	if (high >= low)
	{
	mid=(low+high)/2;
		if(list[mid]==k)
		{
			return mid;
		}
		else if(list[mid]>k)
		{
			t= binary(low,mid-1,k); //again calls itself
			return t;
		}
		else if(list[mid]<k)
		{
			t= binary(low+1,high,k); //again calls itself
			return t;
		}
	}
	return -1;
}
int main()
{
	get();
	int g=binary(0,n-1, k);
	if(g==-1)
		cout<<"not found....";
	else
		cout<<"found at "<<g<<"th position....";
	return 0;
}
