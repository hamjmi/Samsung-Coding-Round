#include<bits/stdc++.h>
using namespace std;
int n=9;
int adj[9][9]={{0,1,0,1,1,0,0,0,0},
	     {0,0,1,0,1,0,0,0,0},
		 {0,0,0,0,0,1,0,0,0},
		 {0,0,0,0,1,0,1,0,0},
		 {0,0,0,0,0,1,0,1,0},
		 {0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,1,0,0,1,0},
		 {0,0,0,0,0,1,0,0,1},
		 {0,0,0,0,0,0,0,0,0}};
#define initial 1
#define visited 2

int state[9];
void dfs(int );
void df_tra()
{
	for(int v=0;v<n;v++)
	{
		state[v]=initial;
	}
	cout<<"\nEnter the starting vertex...";
	int k;
	cin>>k;
	dfs(k);
}
void dfs(int v)
{
	state[v]=visited;
	cout<<v<<" ";
	for(int i=0;i<n;i++)
	{
		if(adj[v][i]==1 && state[i]==initial)
		{
			dfs(i);
		}
	}
}
int main()
{
	df_tra();
	return 0;
	
}
