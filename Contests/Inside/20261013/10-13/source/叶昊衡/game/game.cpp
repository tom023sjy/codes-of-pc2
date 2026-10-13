#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005,Mod=1e9+7;
int n,ans,dep[N],fa[N];
vector<int>con[N];
bool Special=1,vis[N];
struct Node{
	int u,v;
}E[N];
void Getdep(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(int v:con[u])
		if(v!=fa) Getdep(v,u);
}
bool dfs(int u,int step)
{
	dep[0]=-1;
	bool Ans=0;
	Getdep(u,0);
	for(int i=1;i<=n;i++)
		if(u!=i&&vis[i])
			if(dep[i]>step)
			{
				bool X=dfs(i,dep[i]);
				Getdep(u,0);
//				cout<<"u:"<<u<<" i:"<<i<<" dep:"<<dep[i]<<" step:"<<step<<" dfs:"<<X<<'\n';
				Ans|=!X;
			}
	return Ans;
}
void Init()
{
	for(int i=1;i<=n;i++) fa[i]=i;
}
int Fa(int u)
{
	if(fa[u]==u) return u;
	else return fa[u]=Fa(fa[u]);
}
void Add(int u,int v)
{
	u=Fa(u),v=Fa(v);
	if(u!=v) fa[u]=v;
}
void Getvis(int x)
{
	if(x==n+1)
	{
		Init();
		for(int i=1;i<n;i++)
			if(vis[E[i].u]&&vis[E[i].v])
				Add(E[i].u,E[i].v);
		for(int i=1;i<=n;i++)
			if(vis[i]&&Fa(1)!=Fa(i))
				return;
		if(!dfs(1,0)) ans=(ans+1)%Mod;
		return;
	}
	vis[x]=1;
	Getvis(x+1);
	if(x>1)
	{
		vis[x]=0;
		Getvis(x+1);
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		if(x!=i||y!=i+1) Special=0;
		con[x].push_back(y);
		con[y].push_back(x);
		E[i]={x,y};
	}
	if(Special) {cout<<1;return 0;}
	Getvis(1);
	cout<<ans;
	//cout<<dfs(1,0);
}
/*
6
1 2
2 3
1 4
4 5
4 6
*/
