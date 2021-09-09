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
#define waiting 2
#define visited 3
int q[9];
int state[9];
int front=-1;
int rear=-1;
int isempty()
{
	if(front>rear||front==-1)
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
	if(rear==8)
	{
		cout<<"\nOverflow..";
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear++;
	}
	q[rear]=data;
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
		int data=q[front];
		front++;
		return data;
	}
}
void bfs(int v)
{
	int data;
	insert(v);
	state[v]=waiting;
	while(!isempty())
	{
		data=del();
		state[data]=visited;
		cout<<data<<" ";
		for(int i=0;i<n;i++)
		{
			if(adj[data][i]==1 && state[i]==initial)
			{
				insert(i);
				state[i]=waiting;
			}
		}
	}
}
void Bf_tra()
{
	int v;
	cout<<"\nEnter the vertex..";
	cin>>v;
	for(int i=0;i<n;i++)
		state[i]=initial;
	bfs(v);
}
int main()
{
	Bf_tra();
	return 0;
	
}
