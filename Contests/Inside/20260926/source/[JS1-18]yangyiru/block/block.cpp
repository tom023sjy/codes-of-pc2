#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
int val[N], f[N];

vector <int> G[N];

int main(){
//	freopen("block.in", "r", stdin);
//	freopen("block.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>val[i];
	for(int i=1; i<=n; i++){
		int x, y;
		cin>>x;
		for(int j=1; j<=x; j++){
			cin>>y;
			son[i].push_back(y);
		}
	}
	for(int i=1; i<=m; i++){
		int u, v;
		cin>>u>>v; 
	}
	return 0;
}
