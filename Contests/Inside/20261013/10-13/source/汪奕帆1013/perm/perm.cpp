#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,a[N],u,v,f[N],dep[N],d[N],c[N],ans[N],cnt=0;
vector <int > e[N],g[N],h[N]; 
unordered_map <int ,int > m[N];

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

inline void dfs1 (int u,int fa)
{
	f[u]=fa;
	dep[u]=dep[fa]+1;
	for (int v:e[u])
	{
		if (v==fa) continue ;
		dfs1(v,u);
	}
}

inline void dfs2 (int u,int rt)
{
//	printf("[[[%d %d]]]\n",u,rt);
	if (dep[u]-dep[rt]==a[rt]) {h[u].push_back(rt);return ;}
	if (u!=rt&&!m[rt][u]) g[rt].push_back(u),d[u]++,m[rt][u]=1;
	for (int v:e[u])
	{
		if (v==f[u]) continue ;
		dfs2(v,rt);
	}
}

inline void top_sort ()
{
	priority_queue <int,vector <int>,greater<int> > q;
	for (int i=1;i<=n;i++) if (!d[i]&&!c[i]) q.push(i);
	while (!q.empty())
	{
		u=q.top();
		q.pop();
		//printf("{%d}\n",u);
		cnt++;
		ans[cnt]=u;
		for (int v:g[u])
		{
			d[v]--;
			if (!d[v]&&!c[v]) q.push(v);
		}
		for (int v:h[u])
		{
		//	printf("(%d %d)\n",u,v);
			if (c[v])
			{
				c[v]=0;
				if (!d[v]&&!c[v]) q.push(v);
			}
		}
	}
}

signed main()
{
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++) u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	dfs1(1,0);
	for (int i=1;i<=n;i++)
		if (a[i]>=0) dfs2(i,i),c[i]=1;
		else dfs2(i,i);
	top_sort();
	if (cnt<n) cout<<-1;
	else for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}
