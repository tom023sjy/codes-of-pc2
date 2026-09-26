#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=205,N2=20205,m=998244353,im=998244352;
int n;
ll dp[N2][N],ans=1;
ll qpow(ll a,ll x)
{
	a%=m;
	ll ret=1;
	while(x)
	{
		if(x&1)ret=ret*a%m;
		a=a*a%m;
		x>>=1;
	}
	return ret;
}
int main()
{
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	scanf("%d",&n);
	int n2=n*(n+1)/2;
	for(int i=1;i<=n2;i++)
	{
		for(int j=1;j<=n&&j<i;j++)
		{
			dp[i][j]=(dp[i][j-1]+dp[i-j][j-1])%im;
		}
		if(i<=n)
		{
			dp[i][i]=(dp[i][i-1]+1)%im;
		}
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
		}
	}
	for(int i=1;i<=n2;i++)
	{
		ans=ans*qpow(i,dp[i][n])%m;
	}
	printf("%lld",ans);
	return 0;
}
