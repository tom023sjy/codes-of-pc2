#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,val[100005];
vector<int>vec[100005];
map<pair<int,int>,bool>mp;
int f[100005];//f[i]:以i为深度最小的节点的联通块的最大值 
void dfs(int u){
	f[u]=val[u];
	for(int v:vec[u]){
		dfs(v);
		int i=u,j=v;
		if(i>j)swap(i,j);
		if(mp.find({i,j})==mp.end())f[u]=max(f[u],f[u]+f[v]);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("sample2.in","r",stdin);
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int j=1;j<=num;j++){
			int v;
			cin>>v;
			vec[i].push_back(v);
		}
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(u>v)swap(u,v);
		mp[{u,v}]=1;
	}
	dfs(1);
	int ans=-1e18;
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans<<'\n';
//	cout<<tot<<'\n';
	return 0;
}
