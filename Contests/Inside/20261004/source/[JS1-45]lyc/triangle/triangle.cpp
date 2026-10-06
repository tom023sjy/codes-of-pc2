#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
bool a[15][15],b[15][15];
void xz()
{
	int c[15][15];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[i][j]=a[i][j];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			a[n-j+1][n-i+1]=c[i][j];
			a[i][j]=c[n-j+1][n-i+1];
		}
	}
	return;
}
void fz()
{
	int c[15][15];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i/2;j++)
		{
			a[i][j]=c[i][i-j+1];
			a[i][i-j+1]=c[i][j];
		}
	}
	return;
}
int check()
{
	int ans=1e9,now=0;
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=i;j++)
		{
			now+=(a[i][j]^b[i][j]);
		}
	}
	ans=min(now,ans);
	now=0;
	xz();
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=i;j++)
		{
			now+=(a[i][j]^b[i][j]);
		}
	}
	ans=min(now,ans);
	now=0;
	fz();
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=i;j++)
		{
			now+=(a[i][j]^b[i][j]);
		}
	}
	ans=min(now,ans);
	now=0;
	fz();
	xz();
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=i;j++)
		{
			now+=(a[i][j]^b[i][j]);
		}
	}
	ans=min(now,ans);
	now=0;
	fz();
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=i;j++)
		{
			now+=(a[i][j]^b[i][j]);
		}
	}
	ans=min(now,ans);
	now=0;
	xz();
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=i;j++)
		{
			now+=(a[i][j]^b[i][j]);
		}
	}
	ans=min(now,ans);
	now=0;
	return ans;
}
signed main()
{
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{	
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			
			cin>>b[i][j];
		}
	}
	int ans=check();
	cout<<ans;
	return 0;
}
