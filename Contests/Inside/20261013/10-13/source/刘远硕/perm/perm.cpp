#include<bits/stdc++.h>
using namespace std;
int n,a[500020],ft[500020],f[500020],vis[500020];
vector<int> G[500020];
map<pair<int,int> ,int> mp;
vector<int> v[500020];
int dep[500020];
bool cmp (vector<int> a,vector<int> b){
	if (a.empty()) return 0;
	if (b.empty()) return 1;
	return a[0]<b[0];
}
bool check(int x,int now,int fa){
	if (now<a[x] && now!=0) return 1;
	if (now!=0 && a[x]==-1) return 1;
	if (a[x]==0 ) return 1;
	now=max(now,a[x]);
	int ans=0;
	for (auto r : G[x]){
		if (r==fa) continue;
		ans|=check(r,max(now-1,0),x);
	}
	return ans;
}
void Dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x]=fa;
	for (auto r : G[x]){
		if (r==fa) continue;
		Dfs(r,x);
	}
}
void dfs(int st,int ed,int x,int fa){
	if (dep[x]==ed) {
		mp[{x,ed}]=x;
		ft[st]=min(x,ft[st]);
//		cout<<st<<" "<<ft[st]<<" "<<x<<"\n";
		return ;
	}
	if (mp[{x,ed}]){
		ft[st]=min(x,ft[st]);
		ft[st]=min(mp[{x,ed}],ft[st]);
		return ;
	}
	for (auto r : G[x]){
		if (r==fa) continue;
		dfs(st,ed,r,x);
		if (mp[{x,ed}]==0) mp[{x,ed}]=mp[{r,ed}];
		else mp[{x,ed}]=min(mp[{x,ed}],mp[{r,ed}]);
	}
}
void print(int x){
	if (vis[x]==1) return ;
	if (ft[x]!=0x3f3f3f3f) print(ft[x]);
	cout<<x<<" ";
	vis[x]=1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (check(1,0,0)){
		cout<<-1;
		return 0;
	}else {
		Dfs(1,0);
		memset(ft,0x3f,sizeof ft); 
		for (int i=1;i<=n;i++){
			if (a[i]==-1) continue;
			dfs(i,dep[i]+a[i],i,f[i]);
		}
		int cnt=0;
		for (int i=1;i<=n;i++)print(i);
	}
	return 0;
}

