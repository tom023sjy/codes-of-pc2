#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;
int n, m, a[N], ans, p[N], sum, val;
struct Limit {
	int u, v;
} lmt[25];
struct Edge {
	int v, nxt;
} e[N];
int head[N], cnt;

void add (int u, int v) {
	e[++ cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void dfs (int x) {
	val += a[x];
	for (int i = head[x]; i != -1; i = e[i].nxt) {
		int y = e[i].v;
		bool f = 0;
		for (int j = 1; j <= m; j ++) {
			if (lmt[j].u == x && lmt[j].v == y || lmt[j].u == y && lmt[j].v == x) {
				f = 1;
				p[++ sum] = y;
				break;
			}
		}
		if (f) continue;
		dfs (y);
	}
}

signed main () {
	freopen ("block.in", "r", stdin);
	freopen ("block.out", "w", stdout);
	
	memset (head, -1, sizeof head);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j ++) {
			int v;
			cin >> v;
			add (i, v);
		}
	}
	for (int i = 1; i <= m; i ++) 
		cin >> lmt[i].u >> lmt[i].v;
	dfs (1);
	ans = val;
	for (int i = 1; i <= sum; i ++) {
		val = 0;
		dfs (p[i]);
		ans = max (ans, val);
	}
	cout << ans;
	return 0;
}
