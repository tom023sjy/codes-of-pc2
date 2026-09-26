#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5;
struct G
{
	int u,v;
}a[N+4];
ll v[N+4],vs[N+4],ans=-2e17;
int fa[N+4],dfn[N+4],b[N+4],c,z;
bool vis[N+3];
inline ll read()
{
	ll sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}
ll ma(ll x,ll y)
{
	return x>y?x:y;
}
void dfs(int p)
{
	if(vis[p]) return;
	vis[p]=true;
	vs[p]=v[p];
	for(int i=b[p];i<b[p+1];++i)
	{
		if(a[i].u==0&&a[i].v==0) continue;
		dfs(a[i].v);
		vs[p]+=vs[a[i].v];
	}
	ans=ma(ans,vs[p]);
}
bool cmp(G x,G y)
{
	return x.u<y.u;
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;++i) v[i]=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		for(int j=1;j<=x;++j)
		{
			int y=read();
			fa[y]=i;
			a[++z]={i,y};
		}
	}
	sort(a+1,a+z+1,cmp);
	for(int i=1;i<=z;++i) if(a[i].u!=a[i-1].u) b[a[i].u]=i;
	b[n+1]=z+1;
	for(int i=n;i;--i) if(b[i]==0) b[i]=b[i+1];
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		for(int j=b[y];j<b[y+1];++j)
		{
			if(a[j].v==x)
			{
				a[j]={0,0};
				break;
			}
		}
	}
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i);
	cout<<ans;
}
