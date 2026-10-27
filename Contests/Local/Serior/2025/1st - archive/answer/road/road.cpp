#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4, M = 1e6, K = 10, M2 = 1e7;
struct Edge {
    int u, v, w;
} e[M2 + 5];
int c[K + 5], w[K + 5][N + 5];
bool vis[K + 5];
inline bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
int f[N * 2 + 20];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
inline pair<int, vector<Edge>> KrusKarl(int n, int m, Edge e[]) {
    int ans = 0;
    sort(e + 1, e + m + 1, cmp);
    vector<Edge> ne;
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        ans += e[i].w;
        ne.emplace_back(e[i]);
    }
    return {ans, ne};
}
inline bool valid(int n, int id, int status) {
    if (id <= n) return 1;
    id -= n;
    return status >> id - 1 & 1; 
}
inline int KrusKarl(int n, int m, Edge e[], int orgn, int stat) {
    int ans = 0;
    // sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        if (!valid(orgn, e[i].u, stat)) continue;
        if (!valid(orgn, e[i].v, stat)) continue;
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) continue;
        f[x] = y;
        ans += e[i].w;
    }
    return ans;
}
signed main() {
	int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= m; i ++)
        scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
    for (int i = 1; i <= k; i ++) {
        scanf("%lld", &c[i]);
        for (int j = 1; j <= n; j ++)
            scanf("%lld", &w[i][j]);
    }
    auto ng = KrusKarl(n, m, e);
    for (int i = 1; i < n; i ++)
        e[i] = ng.second[i - 1];
    m = n - 1;
    // ADD: Add edge, then sort with previus n-1 lines.
    for (int i = 1; i <= k; i ++)
        for (int j = 1; j <= n; j ++)
            e[++ m] = {n + i, j, w[i][j]};
    sort(e + 1, e + m + 1, cmp);
    // End of ADD
    int ans = 9e18;
    for (int status = 0; status < (1 << k); status ++) {
        int sum = 0;
        for (int i = 1; i <= k; i ++)
            if (status >> i - 1 & 1) 
                sum += c[i];
        ans = min(ans, KrusKarl(n + k, m, e, n, status) + sum);
    }
    printf("%lld", ans);
    return 0;
}