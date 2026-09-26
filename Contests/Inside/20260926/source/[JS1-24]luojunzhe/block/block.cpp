#include <bits/stdc++.h>
using namespace std;
int val[100005];
vector <int> v[100005];
int dfn[100005];
bool vis[100005], is[100005];
int cnt = 1, ans = 0;
void dfs(int a, int fa)
{
	if(vis[a]) return;
	vis[a] = 1;
	dfn[a] = cnt;
	for(auto y : v[a])
	{
		if(y != fa)
		{
			cnt++;
			dfs(y, a);
		}
	}
}
void dfs2(int a, int fa)
{
	if(vis[a]) return;
	vis[a] = 1;
	for(auto y : v[a])
	{
		if(y != fa && is[y] == 0)
		{
			ans += val[y];
			dfs2(y, a);
		}
	}
}
int main()
{
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		cin>>val[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin>>x;
		for(int j = 1; j <= x; j++)
		{
			int g;
			cin>>g;
			v[i].push_back(g);
			v[g].push_back(i);
		}
	}
	dfs(1, 0);
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin>>u>>v;
		if(abs(dfn[u] - dfn[v]) == 1)
		{
			is[u] = is[v] = 1;
		}
	}
	dfs(1, 0);
	//cout<<ans;
	cout<<val[1];
	return 0;
}
