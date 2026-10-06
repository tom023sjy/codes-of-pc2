#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
struct Node {
    int id, w;
};
vector<Node> g[N + 5];
int dep[N + 5], deps[N + 5], depe[N + 5];
void dfs(int id, int ft) {
    for (Node nxt : g[id])
        if (nxt.id != ft) {
            dep[nxt.id] = dep[id] + nxt.w;
            dfs(nxt.id, id);
        }
}
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    int st = 0, maxn = 0;
    for (int i = 1; i <= n; i ++)
        if (maxn < dep[i])
            maxn = dep[i], st = i;
    memset(dep, 0, sizeof dep);
    dfs(st, 0);
    int ed = 0;
    maxn = 0;
    for (int i = 1; i <= n; i ++)
        if (maxn < dep[i])
            maxn = dep[i], ed = i;
    memcpy(deps, dep, sizeof dep);
    memset(dep, 0, sizeof dep);
    dfs(ed, 0);
    memcpy(depe, dep, sizeof dep);
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, min(deps[i], depe[i]));
    for (int i = 1; i <= n; i ++)
        cout << deps[i] << " " << depe[i] << endl;
    // cout << ans;
    return 0;
}