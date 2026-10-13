#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=4005,mod=1e9+7;
int n,u,v,dp[N][N],dep[N],sum[N][N],ans=0,is=1;
vector <int > e[N];

inline int read ()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-f;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

inline void write (int x)
{
	if (x>=10) write(x/10);
	putchar(char(x%10+'0'));
}

inline void add (int &a,int b) {a=(a+b)%mod;}

inline int ksm (int a,int b)
{
	int res=1;
	while (b)
	{
		if (b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1; 
	}
	return res;
}

inline int niyuan (int x) {return ksm(x,mod-2);}

void dfs (int u,int fa)
{
	dep[u]=0;
	dp[u][0]=1;
	for (int v:e[u])
	{
		if (v==fa) continue ;
		dfs(v,u);
		dep[u]=max(dep[u],dep[v]+1);
		sum[u][0]=1;
		for (int i=1;i<=dep[u];i++)
			sum[u][i]=0,add(sum[u][i],sum[u][i-1]+dp[u][i]);
		for (int j=dep[u];j>=0;j--)
		{
			if (j>0) add(dp[u][j],dp[u][j]*sum[v][min(j-1,dep[v])]%mod);
			if (dep[v]>=j-1) add(dp[u][j],sum[u][j-1]*dp[v][j-1]%mod);
		}
	}
	sum[u][0]=1;
	for (int i=1;i<=dep[u];i++)
		sum[u][i]=0,add(sum[u][i],sum[u][i-1]+dp[u][i]);
	
	/*printf("dfs::{%d %d}\n",u,dep[u]);
	for (int j=0;j<=dep[u];j++)
	{
		printf("(%d %d)\n",j,dp[u][j]);
	}*/
}

signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	for (int i=1;i<n;i++)
	{
		u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
		if (u!=i||v!=i+1) is=0;
	}
	if (is)
	{
		cout<<1;
		return 0;
	}
	dfs(1,0);
	for (int j=0;j<=dep[1];j++) add(ans,dp[1][j]);
	for (int j=1;j<=dep[1];j++)
	{
		int s=1;;
		if (j>1) for (int v:e[1]) s=s*(1+sum[v][min(dep[v],j-2)])%mod;
		for (int v:e[1])
		{
			int res=dp[v][j-1]*s%mod*niyuan(1+sum[v][min(dep[v],j-2)]);
			add(ans,-res);
		}
	}
	cout<<(ans+mod)%mod;
	return 0;
}
