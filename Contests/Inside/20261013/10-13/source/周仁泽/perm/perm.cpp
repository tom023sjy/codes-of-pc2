#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 7;
const int INF = 0x3f3f3f3f;
int n, a, b, w;
int d[MAXN], p[MAXN], t[MAXN], f[MAXN], ans[MAXN];
bool flag, ok;
bool vis[MAXN];
vector<int> val[MAXN];
void init(int x) {
	for (auto u : val[x]) {
		if (u == f[x]) continue;
		f[u] = x;
		init(u);
	}
	return;
}
void check(int x, int y, int z) {
	for (auto u : val[y]) {
		if (u == f[y]) continue;
		if (t[u] < t[x]) w = min(w, z);
		check(x, u, z + 1);
	}
	return;
} 
void solve() {
	for (int i = 1; i <= n; i++) t[p[i]] = i;
	for (int i = 1; i <= n; i++) {
		ok = 0, w = INF;
		check(i, i, 1);
		if (w == INF) w = -1;
		if (w == d[i]) ok = 1;
		if (!ok) break;
	}
	if (ok) {
		flag = 1;
		for (int i = 1; i <= n; i++) ans[i] = p[i];
	}
	return;
}
void dfs(int x) {
	if (flag) return;
	if (x > n) {
		solve();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (flag) break;
		if (vis[i]) continue;
		vis[i] = 1;
		p[x] = i;
		dfs(x + 1);
		vis[i] = 0;
		p[x] = 0;
	}
	return;
}
signed main() {
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		val[a].push_back(b);
		val[b].push_back(a);
	}
	if (n > 11) {
		cout << -1 << "\n";
		return 0; 
	}
	init(1);
	dfs(1);
	if (!flag) cout << -1 << "\n";
	else for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}
