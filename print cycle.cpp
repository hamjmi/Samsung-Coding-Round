#include<bits/stdc++.h>
using namespace std;
int n=9;
int adj[9][9] = {{0,1,0,0,0,0,0,0,0},
	     {0,0,1,0,0,0,0,0,0},
		 {0,0,0,1,1,0,0,0,0},
		 {1,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,1,0,0,0},
		 {0,0,0,0,0,0,1,0,0},
		 {0,0,0,0,1,0,0,0,0},
		 {0,0,0,0,0,0,0,0,1},
		 {0,0,0,0,0,0,0,0,0}};
#define initial 1
#define visited 2
vector<int> vec;
vector<int> :: iterator it;
int s[100];
int top=-1;
void insert(int a)
{
	if(top==99)
	{
		cout<<"\nOverflow...";
	}
	top++;
	s[top]=a;
}
int del()
{
	if(top==-1)
	{
		cout<<"\nUnderflow...";
	}
	int data=s[top];
	top--;
	return data;
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int state[9];
void dfs(int );
void df_tra(int v)
{
	state[v]=visited;
	//cout<<v<<" ";
	for(int i=0;i<n;i++)
	{
		if(adj[v][i]==1 && state[i]==initial)
		{
			df_tra(i);
		}
	}
	insert(v);
}
void dfs(int v)
{
	state[v]=visited;
	//cout<<v<<" ";
	vec.push_back(v);
	for(int i=0;i<n;i++)
	{
		if(adj[i][v]==1 && state[i]==initial)
		{
			dfs(i);
		}
	}
}
int main()
{
	for(int v=0;v<n;v++)
	{
		state[v]=initial;
	}
	for(int v=0;v<n;v++)
	{
		if(state[v]==initial)
			df_tra(v);
	}
	for(int v=0;v<n;v++)
	{
		state[v]=initial;
	}
	for(int i=0;i<=top;i++)
		cout<<s[i]<<":";
	cout<<endl;
	while(!isempty())
	{
		int d=del();
		if(state[d]==initial)
		{
			vec.clear();
			dfs(d);
			if(vec.size()>2)
			{
				sort(vec.begin(),vec.end());
				for(it=vec.begin();it!=vec.end();it++)
					cout<<(*it)<<" ";
				cout<<endl;
			}
			
		}
	}
}
