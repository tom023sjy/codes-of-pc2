#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e6+5;
int dp[2][5005][5003],a[N],b[N],n,top,s[N],ans[N];
int F(int x)
{
	if(x<0)return -x;
	return x;
}
/*
2 
1 2 
2 1

1
1
2
*/
int main()
{
	freopen("maxmin.in","r",stdin);
	freopen("maxmin.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[++top]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		s[++top]=b[i];
	}
	
	sort(s+1,s+1+top);
	top=unique(s+1,s+1+top)-s-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(s+1,s+1+top,a[i])-s;
		b[i]=lower_bound(s+1,s+1+top,b[i])-s;
	}
	int op=1;
	dp[op][a[1]][b[1]]=1;
	op=0;
	for(int i=1;i<n;i++)
	{
		op^=1;
		for(int j=1;j<=top;j++)
		{
			for(int k=1;k<=top;k++)
			{
				int V1=max(j,a[i+1]),V2=max(k,b[i+1]);
				dp[op^1][V1][V2]|=dp[op][j][k];
				V1=min(j,a[i+1]),V2=min(k,b[i+1]);
				dp[op^1][V1][V2]|=dp[op][j][k];
				dp[op][j][k]=0;
			}
		}
	}
	op^=1;
	for(int i=1;i<=top;i++)
	{
		for(int j=1;j<=top;j++)
		{
			ans[F(s[i]-s[j])]+=dp[op][i][j];
		}
	}
	for(int i=0;i<n;i++)printf("%d ",ans[i]);
	return 0;
}
