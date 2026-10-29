#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#define N 500
#define M 50000
using namespace std;
int read()
{
	char c=0;
	int sum=0;
	while (c<'0'||c>'9') c=getchar();
	while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();
	return sum; 
}
int op,n,h[N+1];
bitset<M+1>dp[2][N+1];
bitset<M+1>ans;
int main()
{
	freopen("cup.in","r",stdin);
	freopen("cup.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i) h[i]=read();
	sort(h+1,h+n+1),dp[0][0][M>>1]=1;
	for (int i=1;i<=n-1;++i)
	{
		op^=1;
		for (int j=0;j<=i;++j) dp[op][j]=dp[op^1][j];
		for (int j=i;j>=1;--j) dp[op][j-1]|=(dp[op][j]<<h[i]);
		for (int j=1;j<=i;++j) dp[op][j]|=(dp[op^1][j-1]>>h[i]);
	}
	for (int i=dp[op][0]._Find_first();i!=dp[op][0].size();i=dp[op][0]._Find_next(i)) printf("%d ",i-(M>>1));
	puts("");
	return 0;
}
