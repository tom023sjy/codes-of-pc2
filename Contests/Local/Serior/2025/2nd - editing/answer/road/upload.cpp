#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6, K = 10;
struct Node {
    int id, w;
};
struct Edge {
    int u, v, w;
} e[N + 5], eb[N + 5];
vector<Node> g[N + 5], g1[N + 5];
int c[N + 5], a[K + 5][N + 5], f[N + 5];
bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
int kruskarl(int n, int m) {
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    int sum = 0;
    for (int i = 1; i <= m; i ++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int ftu = find(u), ftv = find(v);
        if (ftu != ftv) {
            sum += w;
            f[ftu] = ftv;
        }
    }
    return sum;
}
signed main() {
	int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        eb[i] = {u, v, w};
    }
    for (int i = 1; i <= k; i ++) {
        cin >> c[i];
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];
    }
    int ans = 9e18;
    for (int stat = 0; stat < 1 << k; stat ++) {
        int sum = 0, curr = m;
        memcpy(e, eb, sizeof eb);
        for (int i = 1; i <= k; i ++)
            if (stat >> i - 1 & 1) {
                sum += c[i];
                for (int j = 1; j <= n; j ++)
                    e[++ curr] = {n + i, j, a[i][j]};
            }
        ans = min(ans, kruskarl(k + n, curr) + sum);
    }
    cout << ans;
    return 0;
}
