#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5, M = 20;
int st[N + 5][M + 5], dep[N + 5], tmpstmp;
vector<int> g[N + 5];
void dfs(int id, int ft) {
	st[id][0] = ft;
	dep[id] = dep[ft] + 1;
	for (int nxt : g[id])
		if (nxt != ft)
			dfs(nxt, id);
}
int query(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = M; i >= 0; i --) 
		if (dep[st[u][i]] >= dep[v])
			u = st[u][i];
	if (u == v) return u;
	for (int i = M; i >= 0; i --)
		if (st[u][i] != st[v][i])
			u = st[u][i], v = st[v][i];
	return st[u][0];
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q, rt;
	cin >> n >> q >> rt;
	for (int i = 1; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(rt, 0);
	for (int i = 1; (1 << i) <= n; i ++)
        for (int j = 1; j <= n; j ++)
            st[j][i] = st[st[j][i - 1]][i - 1];
	while (q --) {
		int x, y;
		cin >> x >> y;
		cout << query(x, y) << endl;
	}
	return 0;
} 