#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int a[N + 5];           // a[i]: Value of node i.
int n, T;               // n nodes, T limits.
vector<int> g[N + 5];   // Graph.
vector<pair<int, int>> limits;
int maxn;               // Final Answer.
vector<int> sg[N + 5];  // Sub-Graph.
vector<int> dfa;        // dfa.
int f[N + 5];           // Father.
bool subvis[N + 5];     // Sub-Graph Vis.
bool vis[N + 5];        // Selection.
void getdfa(int id) {
	subvis[id] = 1;
	dfa.push_back(id);
	for (int nxt : sg[id])
		getdfa(nxt);
}
void dfs(int id) {
	if (id > n) {
		dfa.clear();
		for (int i = 1; i <= n; i ++)
			sg[i].clear();
		memset(f, 0, sizeof f);
		memset(subvis, 0, sizeof subvis);
		for (int i = 1; i <= n; i ++)
			if (vis[i]) 
				for (int nxt : g[i])
					if (vis[nxt])
						sg[i].push_back(nxt), f[nxt] = i;
		int rt = 0;
		for (int i = 1; i <= n; i ++)
			if (f[i] == 0 && vis[i])
				rt = i; 
		getdfa(rt);
		for (int i = 1; i <= n; i ++)
			if (vis[i] && !subvis[i])
				return ; // Not Connected.
		map<int, int> idx;
		for (int i = 0; i < dfa.size(); i ++)
			idx[dfa[i]] = i;
		for (pair<int, int> limit : limits)
			if (
				idx.count(limit.first) && idx.count(limit.second)
			 && abs(idx[limit.first] - idx[limit.second]) == 1
			)
				return ;
		int sum = 0;
		for (int i = 1; i <= n; i ++)
			if (vis[i])
				sum += a[i];
		maxn = max(maxn, sum);
		return ;
	}
	vis[id] = 0;
	dfs(id + 1);
	vis[id] = 1;
	dfs(id + 1);
}
signed main() {
    freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	cin >> n >> T;
	assert(n <= 25); 
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		while (k --) {
			int j;
			cin >> j;
			g[i].push_back(j);
		}
	}
	for (int i = 1; i <= T; i ++) {
		int u, v;
		cin >> u >> v;
		limits.push_back({u, v});
	}
	dfs(1);
	cout << maxn;
	return 0;
}

