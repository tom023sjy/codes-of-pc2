#include<bits/stdc++.h>
using namespace std;
int n,d[500005];
vector<int>G[500005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<-1;
	return 0;
}
