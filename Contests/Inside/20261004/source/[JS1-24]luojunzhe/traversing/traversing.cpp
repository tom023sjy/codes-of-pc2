#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int ljz[100005], cur = 0, dfn[100005];
void dfs(int x, int fa)
{
	if(ljz[x] == -1)
	{
		dfn[x] = ++cur;
		for(auto lbq : v[x])
		{
			if(lbq != fa)
			{
				dfs(lbq, x);
			}
		}
	}
	else if(ljz[x] == 0)
	{
		int g;
		for(auto lbq : v[x])
		{
			if(lbq != fa)
			{
				g = lbq;
				dfs(lbq, x);
				break;
			}
		}
		dfn[x] = ++cur;
		for(auto lbq : v[x])
		{
			if(lbq != fa && lbq != g)
			{
				dfs(lbq, x);
			}
		}
	}
	else
	{
		for(auto lbq : v[x])
		{
			if(lbq != fa)
			{
				dfs(lbq, x);
			}
		}
		dfn[x] = ++cur;
	}
}
int main()
{
	freopen("traversing.in", "r", stdin);
	freopen("traversing.out", "w", stdout);
	int n, q;
	cin>>n>>q;
	for(int i = 1; i <= n; i++)
	{
		int l, r;
		cin>>l>>r;
		if(l)
		{
			v[l].push_back(i);
			v[i].push_back(l);
		}
		if(r)
		{
			v[r].push_back(i);
			v[i].push_back(r);
		}
	}
	for(int i = 1; i <= n; i++) ljz[i] = -1;
	while(q--)
	{
		int op;
		cin>>op;
		if(op == 1)
		{
			int l, r, x;
			cin>>l>>r>>x;
			for(int i = l; i <= r; i++)
			{
				ljz[i] = x;
			}
		}
		else
		{
			int x;
			cin>>x;
			cur = 0;
			memset(dfn, 0, sizeof(dfn));
			dfs(1, 0);
			/*
			for(int i = 1; i <= n; i++)
				cout<<dfn[i]<<' ';
			cout<<endl;
			*/
			cout<<dfn[x]<<endl;
		}
	}
	return 0;
}
