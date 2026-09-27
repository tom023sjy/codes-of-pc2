#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef long long ll;

template<typename Tp>
Tp max(Tp a, Tp b, Tp c) {
	return max(a, max(b, c));
}
template<typename Tp>
Tp min(Tp a, Tp b, Tp c) {
	return min(a, min(b, c));
}

const int N = 5e5, M = 20;
int root, st[N + 5][M + 5], dfn[N + 5], tmp, dep[N + 5];
vector<int> g[N + 5];

int get(int x, int y) {
	if (dfn[x] < dfn[y]) return x;
	return y;
}
void dfs(int id, int ft) {
	st[dfn[id] = ++ tmp][0] = ft;
	dep[id] = dep[ft] + 1;
	for (int nxt : g[id])
		if (nxt != ft)
			dfs(nxt, id);
}
int query(int l, int r) {
	int sz = log2(r - l ++);
	return get(st[l][sz], st[r - (1 << sz) + 1][sz]);
}
int lca(int x, int y) {
	if (x == y) return x;
	int u = dfn[x], v = dfn[y];
	if (u > v) swap(u, v);
	int sz = log2(v - u);
    u ++;
    return get(st[u][sz], st[v - (1 << sz) + 1][sz]);
}

void init(int n, int rt = 1) {
	dfs(rt, 0);
	for (int i = 1; (1 << i) <= n; i ++)
        for (int j = 1; j <= n - (1 << i) + 1; j ++)
            st[j][i] = get(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, T;
	cin >> n >> T;
	for (int i = 1; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	init(n);
	while (T --) {
		int a, b, c;
		cin >> a >> b >> c;
		int lab = lca(a, b), lac = lca(a, c), lbc = lca(b, c);
		ll dab = dep[lab],  dac = dep[lac],  dbc = dep[lbc];
		if (lab == lac)
			cout << lbc;
		else if (lab == lbc)
			cout << lac;
		else if (lac == lbc)
			cout << lab;
		cout << " " << ll(dep[a]) + dep[b] + dep[c] - max(dab, dac, dbc) - 2 * min(dab, dac, dbc) << endl;
	}
	return 0;
} 

/*
综上所述，答案为
deep(a)+deep(b)+deep(c)−最深LCA的深度−最浅LCA的深度∗2
*/