#include<bits/stdc++.h>
using namespace std;
long long s,n,h,l,r,x,u,v,max1=0;
long long a[2001],b[2001];
long long dp[2001][2001];
int main()
{
	cin>>n>>h>>l>>r;
	s=0;
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		//b[i]%=h;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if((b[i]-j)%h>=l&&(b[i]-j)%h<=r)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+1;
			else
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
		}
		
	}
	for(int i=0;i<=n;i++)
	max1=max(max1,dp[n][i]);
	cout<<max1;
}