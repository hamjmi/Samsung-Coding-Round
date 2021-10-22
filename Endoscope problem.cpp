#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll v[1001][1001];
ll visit[1001][1001];
struct que
{
	ll x;
	ll y;
};
que q[1000001];
bool checkup(ll r,ll c,ll t,ll l)
{
	if(t<0||v[t][c]==0||visit[t][c]!=0||visit[r][c]==l) return false;
	if((v[r][c]==1||v[r][c]==2||v[r][c]==4||v[r][c]==7)&&(v[t][c]==1||v[t][c]==2||v[t][c]==5||v[t][c]==6)) return true;
	return false;
}
bool checkdown(ll r,ll c,ll t,ll row,ll l)
{
	if(t>=row||v[t][c]==0||visit[t][c]!=0||visit[r][c]==l) return false;
	if((v[r][c]==1||v[r][c]==2||v[r][c]==5||v[r][c]==6)&&(v[t][c]==1||v[t][c]==2||v[t][c]==4||v[t][c]==7)) return true;
	return false;
} 
bool checkleft(ll r,ll c,ll t,ll l)
{
	if(t<0||v[r][t]==0||visit[r][t]!=0||visit[r][c]==l) return false;
	if((v[r][c]==1||v[r][c]==3||v[r][c]==7||v[r][c]==6)&&(v[r][t]==1||v[r][t]==3||v[r][t]==4||v[r][t]==5)) return true;
	return false;
}
bool checkright(ll r,ll c,ll t,ll col,ll l)
{
	if(t>=col||v[r][t]==0||visit[r][t]!=0||visit[r][c]==l) return false;
	if((v[r][c]==1||v[r][c]==3||v[r][c]==5||v[r][c]==4)&&(v[r][t]==1||v[r][t]==3||v[r][t]==6||v[r][t]==7)) return true;
	return false;
}
int main()
{
	ll n,m,t,r,c,l,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>r>>c>>l;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>v[i][j];
				visit[i][j]=0;
			}
		}
		if(v[r][c]==0)
			cout<<"0"<<endl;
		else if(l==1)
			cout<<"1"<<endl;
		else
		{
			que p;
			ll start=0,end=0,count=0;
			p.x=r;
			p.y=c;
			q[end++]=p;
			visit[r][c]=1;
			while(start!=end)
			{
				p=q[start];
				start++;
				ll a1,a2;
				a1=p.x;
				a2=p.y;
				if(checkup(a1,a2,a1-1,l))
				{
					p.x=a1-1;
					p.y=a2;
					q[end++]=p;
					visit[a1-1][a2]=1+visit[a1][a2];
				}
				if(checkdown(a1,a2,a1+1,n,l))
				{
					p.x=a1+1;
					p.y=a2;
					q[end++]=p;
					visit[a1+1][a2]=1+visit[a1][a2];
				}
				if(checkleft(a1,a2,a2-1,l))
				{
					p.x=a1;
					p.y=a2-1;
					q[end++]=p;
					visit[a1][a2-1]=1+visit[a1][a2];
				}
				if(checkright(a1,a2,a2+1,m,l))
				{
					p.x=a1;
					p.y=a2+1;
					q[end++]=p;
					visit[a1][a2+1]=1+visit[a1][a2];
				}
			}
			for(i=0;i<n;i++)
				for(j=0;j<m;j++)
					if(visit[i][j]!=0)
						count++;
			cout<<count<<endl;
		}
		
	}
	return 0;
}
