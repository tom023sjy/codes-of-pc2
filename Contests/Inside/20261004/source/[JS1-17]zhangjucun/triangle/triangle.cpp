#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,ans=1e9,a[6][15][15],b[15][15],s;
int main()
{
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++) cin>>a[0][i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++) cin>>b[i][j];
	}
	for(int j=n;j>=1;j--)
	{
		for(int i=j;i<=n;i++) a[1][i][j]=a[0][n-j+1][i-j+1];
	}
	for(int j=n;j>=1;j--)
	{
		for(int i=j;i<=n;i++) a[2][i][j]=a[1][n-j+1][i-j+1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++) a[3][i][j]=a[0][n-j+1][n-i+1];
	}
	for(int j=n;j>=1;j--)
	{
		for(int i=j;i<=n;i++) a[4][i][j]=a[3][n-j+1][i-j+1];
	}
	for(int j=n;j>=1;j--)
	{
		for(int i=j;i<=n;i++) a[5][i][j]=a[4][n-j+1][i-j+1];
	}
	for(int i=0;i<6;i++)
	{
		int res=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=j;k++) if(a[i][j][k]!=b[j][k]) res++;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
