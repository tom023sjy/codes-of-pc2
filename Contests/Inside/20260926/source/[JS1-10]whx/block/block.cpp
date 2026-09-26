#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
vector<int> g[100010];
vector<int> p[100010];
long long ans;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		while(x--){
			int y;
			cin>>y;
			g[i].push_back(y);
		}
	}
	while(m--){
		int x,y;
		cin>>x>>y;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
