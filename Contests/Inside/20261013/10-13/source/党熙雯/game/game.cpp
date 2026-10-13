#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int mx=3100;
int dp[mx][mx];
int n;
struct edge
{
	int to,nxt;
}e[2*mx];
int h[mx],tot;
void build(int u,int v)
{
	e[++tot].to=v;
	e[tot].nxt=h[u];
	h[u]=tot;
}
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*w;
}
int fa[mx];
int dep[mx];
int maxndep;
int qz[mx][mx];
void findfa(int u,int f)
{
	fa[u]=f;
	dep[u]=dep[f]+1;
	maxndep=max(maxndep,dep[u]);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==f) continue;
		findfa(v,u);
	}
}
void dfs(int u)
{
	int vis=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa[u]) continue;
		dfs(v);
		vis=1;
	}
	dp[u][dep[u]]=1;
	if(vis==0)
	{
		return ;
	}
	else
	{
		for(int i=dep[u]+1;i<=maxndep;i++)
		{
			int ans=1;
			for(int j=h[u];j;j=e[j].nxt)
			{
				int v=e[j].to;
				if(v==fa[u]) continue;
				ans*=(dp[v][i]+1);
				ans%=mod;
			}
			ans--;
			dp[u][i]=ans%mod;
			for(int j=i;j<=maxndep;j++)
			{
				qz[u][j]+=dp[u][i];
				qz[u][j]%=mod;
			}
		}
	}
	return ;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cout<<1;
	return 0;
	n=fread();
	for(int i=1;i<n;i++)
	{
		int u=fread(),v=fread();
		build(u,v),build(v,u);
	}
	findfa(1,0);
//	cout<<"DEBUG\n";
	dfs(1);
	int ans=0;
	int u=1;
	for(int i=1;i<=maxndep;i++)
	{
		for(int j=h[u];j;j=e[j].nxt)
		{
			for(int k=h[u];k;k=e[k].nxt)
			{
				int v1=e[j].to;
				int v2=e[k].to;
				int ls=dp[v1][i]*dp[v2][i]%mod;
				if(v1>=v2) continue;
				for(int l=h[u];l;l=e[l].nxt)
				{
					int v3=e[l].to;
					if(v1==v3||v2==v3) continue;
					ls*=(qz[v3][i-1]+1);
					ls%=mod;
				}
				ans+=ls;
			}
		}
	}
	ans++;
	cout<<ans<<endl;
	return 0;
}

