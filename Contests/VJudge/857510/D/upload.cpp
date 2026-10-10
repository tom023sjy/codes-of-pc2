#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300;
vector<int> g[N + 5];
int a[N + 5];
bool vis[N + 5], able[N + 5], flg[N + 5];
void dfs(int id) {
    if (!able[id] || vis[id]) return ;
    vis[id] = 1;
    for (int nxt : g[id])
        dfs(nxt);
}
signed main() {
    int c, n, m, k, T;
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &k, &T);
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= k; i ++)
        cin >> a[i];
    while (T --) {
        int l, r;
        cin >> l >> r;
        memset(able, 0, sizeof able);
        able[1] = 1;
        for (int i = l; i <= r; i ++) {
            if (able[a[i]]) continue;
            memset(vis, 0, sizeof vis);
            able[a[i]] = 1;
            dfs(a[i]);
            if (!vis[1]) able[a[i]] = 0;
        }
        int cnt = 0;
        for (int i = 2; i <= n; i ++)
            cnt += able[i];
        cout << n - 1 - cnt << endl;
    }
    return 0;
}