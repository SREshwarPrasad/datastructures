#include<iostream>
#define max 10
using namespace std;
int adj[max][max];
int visited[max];
int q[max];
int f=0, r=-1;
int n;

int empty()
{
	return (r<f) ?1 : 0;
}
void enq(int x)
{
	r+=1;
	q[r]=x;	
}

int deq()
{
	if (empty())
		return -1;
	int val=q[f];
	f++;
	return val;
	
}
void bfs(int s)
{
	int v;
	enq(s);
	visited[s]=1;
	cout<<s<<"\t";
	
	while (!empty())
	{
		v=deq();
		for (int w=1;w<=n;w++)
			if (adj[v][w] && !visited[w])
				{
					enq(w);
					cout<<w<<"\t";
					visited[w]=1;
				}
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
		cin>>f;
		cin>>t;
		adj[f][t]=adj[t][f]=1;
	}
	bfs(1);
}
