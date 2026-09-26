#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+5;
ll n,m,a,b,w[maxn],ans=0,cnt,dfn[maxn],t=0,s[maxn];
vector<int> p[maxn],c[maxn];
void dfs(int u){
	dfn[u]=++t;
	bool f=1;
	ans=max(ans,cnt);
	
	for(int nv:c[u]){
		if(nv==p[u][0]){
			f=0;
			break;
		}
		if(dfn[nv]==t){
			f=0;
			break;
		}
	}
	cnt+=w[u];
	if(!f){
		t=0;cnt=0;
	}
	cout<<"!"<<u<<" "<<dfn[u]<<" "<<cnt<<" ";
	if(s[u]==0)return;
	for(int v :p[u]){

		dfs(v);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("block.in","r",stdin);
//	freopen("block.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		p[i].resize(s[i]+1);
		for(int j=0,t;j<s[i];j++){
			cin>>t;
			p[i].push_back(t);
		}
	}
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		c[u].push_back(v);
		c[v].push_back(u);
	}
	dfs(1);
	cout<<ans;
	return 0;
}

