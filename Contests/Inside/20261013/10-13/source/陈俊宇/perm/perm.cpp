#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int n;
int dt[N], dep[N];
vector<int> g[N];
bool vis[20], ok = false;
int ans[N], pos[N];
int tin[N], tout[N], tim;

void dfs(int u, int sour, int d){
	tin[u] = ++tim;
	dep[u] = d;
	for (int v : g[u]){
		if (v == sour) continue;
		dfs(v,u,d+1);
	}
	tout[u] = tim;
}

void bdfs(int cur){
	if (ok) return;
	if (cur = n+1){
		for (int i = 1; i <= n; i++) pos[ans[i]] = i;
		for (int i = 1; i <= n; i++){
			if (dt[i] == -1){
				for (int j = 1; j <= n; j++){
					if (i == j) continue;
					if (tin[i] < tin[j] && tin[j] <= tout[i] && pos[j] < pos[i]){
						return;
					}
				}
				continue;
			}
			for (int j = 1; j <= n; j++){
				if (i == j) continue;
				if (tin[i] < tin[j] && tin[j] <= tout[i] && pos[j] < pos[i] && dep[j] - dep[i] < dt[i]) return;
			}
			bool is = false;
			for (int p = 1; p < pos[i]; p++){
				int j = ans[p];
				if (tin[i] < tin[j] && tin[j] <= tout[i] && dep[j] - dep[i] == dt[i]){
					is = true; break;
				}
			}
			if (!is) return;
		}
		ok = true;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			vis[i] = true;
			ans[cur] = i;
			bdfs(cur+1);
			vis[i] = false;
			if (ok) return;
		}
	}
}

int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> dt[i];
	}
	for (int i = 1; i < n; i++){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << "-1";
	return 0;
	if (n <= 20){
		dfs(1,0,1);
		bdfs(1);
		if (ok){
			for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		}
		else cout << "-1";
		return 0;
	}
	
	
	return 0;
}
