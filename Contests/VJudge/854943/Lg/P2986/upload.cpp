#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Node {
    int id, w;
};
vector<Node> g[N + 5];
int a[N + 5], dis[N + 5], tot[N + 5], s;
int dfs(int id, int ft) {
    int ret = a[id];
    for (Node nxt : g[id])
        if (nxt.id != ft) {
            int cnt = dfs(nxt.id, id);
            dis[id] += dis[nxt.id];
            dis[id] += cnt * nxt.w;
            ret += cnt;
        }
    return tot[id] = ret;
}
int dpx[N + 5];
void dfs2(int id, int ft) {
    for (Node nxt : g[id])
        if (nxt.id != ft) {
            dpx[nxt.id] = dpx[id] - tot[nxt.id] * nxt.w + (s - tot[nxt.id]) * nxt.w;
            dfs2(nxt.id, id);
        }
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s += a[i];
    for (int i = 1; i < n; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << *min_element(dpx + 1, dpx + n + 1) + dis[1];
    return 0;
}