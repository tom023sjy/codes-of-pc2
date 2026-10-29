#include <bits/stdc++.h>
using namespace std;
const int N=2002,M=51;
int n;
int h[N],sum,a[M];
bitset<N*M>dp[2][N];
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int main()
{
	freopen("cup.in","r",stdin);
	freopen("cup.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) h[i]=read(),a[h[i]]++;
	for (int i=1;i<=n;i++) sum+=h[i];
	int maxx=0;
	for (int i=1;i<=n;i++) maxx=max(maxx,h[i]);
	for (int i=0;i<=n;i++) dp[0][i].reset();
	for (int i=0;i<=n;i++) dp[1][i].reset();
	dp[maxx+1&1][0]=1;
	int rw=0;
	for (int i=maxx;i>=1;i--)
	{
		for (int j=0;j<=n;j++) dp[i&1][j].reset();
		if (a[i]==0)
		{
			for (int j=0;j<=n;j++) dp[i&1][j]=dp[i+1&1][j];
		}
		else
		{
			for (int k=0;k<=n;k++)
			{
				dp[i&1][k]|=dp[i+1&1][k];
				if (k!=0) dp[i&1][k]|=dp[i&1][k-1]<<i;
			}	
		}
		rw+=a[i];
		for (int j=0;j<rw;j++) dp[i&1][j]=0;
		if (i==maxx&&a[i]==1) for (int j=rw+1;j<=n;j++) dp[i&1][j]=0;
	}
	for (int i=0;i<=n*maxx;i++) if (dp[1][n][i]) cout << i-sum << " ";
	return 0;
}
