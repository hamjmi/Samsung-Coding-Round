#include<iostream>
using namespace std;
int ballonBurst(int a[],int n)
{
	int dp[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
				dp[i][j]=-1;
	for(int len=1;len<=n;len++)
	{
		int q=n-len;
		for(int i=0;i<=q;i++)
		{
			int j=i+len-1;
			for(int k=i;k<=j;k++)
			{
				int leftValue=1;
				int rightValue=1;
				if(i!=0)
				{
					leftValue=a[i-1];
				}
				if(j!=n-1)
				{
					rightValue=a[j+1];
				}
				int before=0;
				int after=0;
				if(i!=k)
					before=dp[i][k-1];
				if(j!=k)
					after=dp[k+1][j];
					
				int temp=leftValue*rightValue*a[k]+before+after;
				if(temp>dp[i][j])
					dp[i][j]=temp;
			}
		}
	}
	return dp[0][n-1];
}
int main()
{
	int a[]={ 1, 2, 3, 4, 5};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<ballonBurst(a,n);
}
