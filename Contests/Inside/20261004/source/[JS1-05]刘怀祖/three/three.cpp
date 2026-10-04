#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5005,mod=1e9+7;
int n,m,cnt[N];
map<pii,ll> dp[N];//第i格刚好放j块以i+1结尾,k块以i+2结尾横板方案数
int main()
{
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for(int i=0;i<=cnt[1];i+=3)
	{
		dp[1][{0,cnt[1]-i}]=1;
	}
	for(int i=2;i<=m;i++)
	{
		for(auto p:dp[i-1])
		{
			int j=p.first.first,k=p.first.second;
			ll ldp=p.second;
			for(int l=0;l<=cnt[i]-j-k;l+=3)
			{
				(dp[i][{k,cnt[i]-j-k-l}]+=ldp)%=mod;
			}//printf("%d,%d,%d:%lld\n",i-1,j,k,ldp);
		}
	}
	printf("%lld",dp[m][{0,0}]);
	return 0;
}
