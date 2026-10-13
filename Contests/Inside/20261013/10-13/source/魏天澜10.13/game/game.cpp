#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
const int M = 3030;
const int mod = 1e9+7;
int n;
vector<int>e[N];
int dep[N];
int dp[M][M];
int num[N];
int qpow(int x,int y){
	int res = 1;
	while(y){
		if(y&1)res*=x,res%=mod;
		x = x*x,x%=mod;
		y>>=1;
	}
	return res;
}
void dfs(int u,int fa){
	dep[u] = dep[fa]+1;
	dp[u][0] = 1;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
	num[u] = 1;
	for(auto v:e[u]){
		if(v==fa)continue;
		num[u] = num[u]*(num[v]+1)%mod;
	}
	for(int i = 1;i<=n;i++){
		int tmp = 1;
		for(auto v:e[u]){
			if(v==fa)continue;
			tmp = tmp*dp[v][i-1]%mod;
		}
		dp[u][i] = tmp+1;
	}
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>n;
	for(int i = 1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bool flag = 0;
	for(int i = 1;i<=n;i++)if(e[i].size()>2)flag = 1;
	if(!flag){
		cout<<1;
		return 0;
	}
	return 0;
}
