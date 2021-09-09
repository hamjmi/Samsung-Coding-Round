#include<bits/stdc++.h>
using namespace std;
int n=9;
//int adj[100][100];
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
int q[50];
int state[9];
int top=-1;
int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void insert(int data)
{
	if(top==49)
	{
		cout<<"\nOverflow..";
	}
	top++;
	q[top]=data;
}
int del()
{
	if(isempty())
	{
		cout<<"\nUnderflow..";
		exit(1);
	}
	else
	{
		int data=q[top];
		top--;
		return data;
	}
}
void dfs(int v)
{
	int data;
	insert(v);
	while(!isempty())
	{
		data=del();
		if(state[data]==initial)
		{
			state[data]=visited;
			cout<<data<<" ";
		}
		for(int i=n-1;i>=0;i--)
		{
			if(adj[data][i]==1 && state[i]==initial)
			{
				insert(i);
			}
		}
	}
}
void Df_tra()
{
	int v;
	cout<<"\nEnter the vertex..";
	cin>>v;
	for(int i=0;i<n;i++)
		state[i]=initial;
	dfs(v);
}
int main()
{
	Df_tra();
	return 0;
	
}
