#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const ll inf=0x7fffffffffffffffll;
int n,m,c[N],u[25],v[25];
ll ans=-inf,dp[N];
vector<int> sn[N];
bool chk(int x,int y)
{
	if(x>y)swap(x,y);
	for(int i=0;i<m;i++)
	{
		if(u[i]==x&&v[i]==y)return 1;
	}
	return 0;
}
void dfs(int x)
{
	dp[x]=c[x];
	for(auto y:sn[x])
	{
		if(chk(x,y))continue;
		dfs(y);
		if(dp[y]>0)dp[x]+=dp[y];
	}
	ans=max(ans,dp[x]);
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int sz,s;
		scanf("%d",&sz);
		for(int j=1;j<=sz;j++)
		{
			scanf("%d",&s);
			sn[i].push_back(s);
		}
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		if(u[i]>v[i])swap(u[i],v[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
