struct Edge {
    int u, v, w;
} e[M * 2 + 5];
inline bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
int f[N * 2 + 20];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
int KrusKarl(int n, int m) {
    int ans = 0;
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        ans += e[i].w;
    }
    return ans;
}
vector<int> g[N + 5];
bool vis[N + 5];
void dfs(int id) {
    if (vis[id]) return ;
    vis[id] = 1;
    for (int nxt : g[id])
        dfs(nxt);
}