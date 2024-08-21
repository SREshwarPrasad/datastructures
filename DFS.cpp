#include<iostream>
#define max 10
using namespace std;
int adj[max][max];
int visited[max];
int n;
void dfs(int s)
{
	int i;
	visited[s]=1; //visited 
	cout<<s<<"\t";
	for(i=1; i<=n; i++)
	{
		if (adj[s][i] && !visited[i]) //v[i] not visited; a[p][i] i is adjacent to p; i should not be visited again.
			dfs(i);
	}
}
int main()
{
	cout<<"No of elements: ";
	cin>>n;	
	for(int i=1; i<=n; i++)
	{
		visited[i]=0; // 0 represents not visited
	}
	cout<<"Matrix :";
	for(int u=1; u<=n; u++)
	{
		for(int s=1; s<=n; s++)
		{
		//	cin>>adj[u][s];
			adj[u][s]=0;
		}
	}
	int edges,f,t;
	cout<<"No. of edges ";
	cin>>edges;
	for (int i=1;i<=edges;i++)
	{
		cout<<"Edge "<<i<<endl;
		cin>>f; // from vertex
		cin>>t; // to vertex
		adj[f][t]=adj[t][f]=1; // this line used for undirected graph
		//adj[f][t] = 1; // uncomment this for directed graph 
	}
	dfs(1);
}
