#include <bits/stdc++.h>
const int N = 3e5, lgN = 20;
std::vector<int> g[N + 5];
namespace lca {
	int dfn[N + 5], st[N + 5][lgN + 5], tmpstmp, dep[N + 5];
    int get(int x, int y) {
        if (dfn[x] < dfn[y]) return x;
        return y;
    }
    void dfs(int id, int ft) {
        st[dfn[id] = ++ tmpstmp][0] = ft;
        dep[id] = dep[ft] + 1;
        for (int nxt : g[id])
            if (nxt != ft)
                dfs(nxt, id);
    }
    int query(int l, int r) {
        int sz = log2(r - l);
		l ++;
        return get(st[l][sz], st[r - (1 << sz) + 1][sz]);
    }
    int solve(int x, int y) {
        if (x == y) return x;
        int u = dfn[x], v = dfn[y];
        if (u > v) std::swap(u, v);
        int sz = log2(v - u);
        u ++;
        return get(st[u][sz], st[v - (1 << sz) + 1][sz]);
    }
    void init(int n) {
        dfs(1, 0);
        for (int i = 1; (1 << i) <= n; i ++)
            for (int j = 1; j <= n - (1 << i) + 1; j ++)
                st[j][i] = get(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
    } 
}
