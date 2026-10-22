#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
vector<int> g[N + 5];
int col[N + 5], st[N + 5][30], dep[N + 5];
bool vis[N + 5];
void dfs(int id, int cl, int ft) {
    if (col[id]) return ;
    col[id] = cl;
    st[id][0] = ft;
    for (int nxt : g[id])
        dfs(nxt, cl, id);
}
int query(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 25; i >= 0; i --) 
		if (dep[st[u][i]] >= dep[v])
			u = st[u][i];
	if (u == v) return u;
	for (int i = 25; i >= 0; i --)
		if (st[u][i] != st[v][i])
			u = st[u][i], v = st[v][i];
	return st[u][0];
}
void init(int n) {
	for (int i = 1; (1 << i) <= n; i ++)
        for (int j = 1; j <= n; j ++)
            st[j][i] = st[st[j][i - 1]][i - 1];
}
void dfs2(int id, int ft) {
    if (dep[id]) {
        if (abs(dep[ft] - dep[id]) % 2 == 0 && ft)
            vis[col[id]] = 1;
        return ;
    }
    dep[id] = dep[ft] + 1;
    for (int nxt : g[id])
        dfs2(nxt, id);
}
signed main() {
    int n, m, T;
    cin >> n >> m >> T;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++) 
        dfs(i, i, 0), dfs2(i, 0);
    init(n);
    while (T --) {
        int s, t, x;
        cin >> s >> t >> x;
        if (col[s] != col[t]) {
            puts("expand");
            continue;
        }
        if (s == t && g[s].empty() && x) {
            puts("expand");
            continue;
        }
        if (vis[col[s]]) {
            puts("tribool");
            continue;
        }
        int lc = query(s, t);
        int len = dep[s] + dep[t] - 2 * dep[lc];
        if (len + x & 1)
            puts("expand");
        else puts("tribool");
    }
    return 0;
}
