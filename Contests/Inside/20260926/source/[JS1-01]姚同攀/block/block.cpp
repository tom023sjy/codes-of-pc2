#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,a[N],cnt[N],lim[N];
ll f[N],ans=-1e15;
vector<int> G[N];
void dfs(int u){
	f[u]=a[u];
	for(auto v:G[u]){
		dfs(v);
		f[u]+=max(f[v],0ll);
	}
	if(lim[u]&&!G[u].empty()) f[u]-=max(f[G[u][0]],0ll);
	ans=max(ans,f[u]);
}
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&cnt[i]);
		for(int j=1,x;j<=cnt[i];++j){
			scanf("%d",&x);
			G[i].push_back(x);
		}
	}
	
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		lim[v]=1;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}

/*
6 3 
2 2 1 3 2 5 
2 2 6 
3 3 4 5 
0 
0 
0 
0 
3 4 
5 6 
2 6
12

*/
