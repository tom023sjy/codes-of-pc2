#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500;
struct Point {
    int idx, lt, w;
};
struct Node {
    int id, w;
};
bool operator <(Node x, Node y) {
    return x.w < y.w;
}
vector<Point> g[N + 5];
void dijk(int id, int dis[]) {
    // `sizeof` no usage, use hand-calc instead.
    priority_queue<Node> q;
    memset(dis, 0xff, (N + 5) * 8); 
    dis[id] = 2e9;
    q.push({id, dis[id]});
    while (!q.empty()) {
        int t = q.top().id;
        q.pop();
        for (auto nxt : g[id]) {
            int wgt = min(nxt.lt, dis[t] - nxt.w);
            if (dis[nxt.idx] < wgt) {
                dis[nxt.idx] = wgt;
                q.push({nxt.idx, dis[nxt.idx]});
            }
        }
    }
}
int dis[N + 5][N + 5];
signed main() {
    int n, m, T;
    cin >> n >> m >> T;
    for (int i = 1; i <= m; i ++) {
        int u, v, l, t;
        cin >> u >> v >> l >> t;
        g[v].push_back({u, l, t});
    }
    for (int i = 1; i <= n; i ++)
        dijk(i, dis[i]);
    while (T --) {
        int s, t, x;
        cin >> s >> t >> x;
        if (dis[t][s] < x)
            puts("No");
        else puts("Yes");
    }
    return 0;
}
