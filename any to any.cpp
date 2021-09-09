#include<bits/stdc++.h>
using namespace std;
int ans=-1;
int visited[20];
int x[20],y[20],n;
int a[20];
int count=0;
int b[20];
void fun(int pos,int total,int s)
{
    visited[pos]=1;
	a[(::count)++]=pos;
    if(n==total+1)
    {
        if(ans==-1)
        {
            ans=s;
        }
        else
        {
            if(ans>s)
            {
				for(int i=0;i<(::count);i++)
            	{
					b[i]=a[i];
				}
				ans=min(ans,s);
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        
		if(visited[i]==0)
        {
            int sum=abs(x[pos]-x[i])+abs(y[pos]-y[i]);
            if(ans!=-1 && (sum+s)>ans)
            	break;
            	
			fun(i,total+1,s+sum);
        }
    }
    (::count)--;
    visited[pos]=0;
}

int main()
{
    int t;
    //cin>>t;
    t=1;
   // cout<<t<<endl;
    while(t--)
    {
       // int n;
        cin>>n;
        n=n+2;
        ans=-1;
       
       for(int i=0;i<n;i++)
       {
           cin>>x[i]>>y[i];
           visited[i]=0;
       }
    for(int i=0;i<n;i++)
    {
    	fun(i,0,0);
	}
      
    cout<<ans<<endl;
    	for(int i=0;i<n;i++)
    		cout<<b[i]<<" ";
    	cout<<endl;
    }
    
    
    return 0;
}
