#include<bits/stdc++.h>
using namespace std;
const int mx=20;
int n;
int d[mx];
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*w;
}
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
int vis[mx],pl[mx];
int fa[mx];
void findfa(int u,int f)
{
	fa[u]=f;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==f) continue;
		findfa(v,u);
	}
}
int dis[mx];
int bb[mx];
void getdis(int u,int x,int di)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa[u]) continue;
		if(bb[v]==1) 
		{
			dis[x]=min(dis[x],di+1);
		}
		else getdis(v,x,di+1);
	}
}
bool che()
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9;
		for(int j=1;j<=n;j++) bb[j]=0;
		for(int j=1;j<=n;j++)
		{
			if(pl[j]==i) break;
			bb[pl[j]]=1;
		}
		getdis(i,i,0);
		if(dis[i]==1e9) dis[i]=-1;
		if(dis[i]!=d[i]) return 0;
	}
	return 1;
}
void dfs(int k)
{
	if(k==n)
	{
		if(che())
		{
			for(int i=1;i<=n;i++) cout<<pl[i]<<' ';
			exit(0);
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		pl[k+1]=i;
		dfs(k+1);
		vis[i]=0;
	} 
}
int main()
{
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	n=fread();
	for(int i=1;i<=n;i++) d[i]=fread();
	for(int i=1;i<n;i++)
	{
		int u=fread(),v=fread();
		build(u,v),build(v,u);
	}
	findfa(1,0);
	dfs(0);
	cout<<-1;
	return 0;
}

