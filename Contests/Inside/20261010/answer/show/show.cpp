#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf "show.in"
#define ouf "show.out"
const int N = 300;
vector<int> g[N + 5];
int a[N + 5];
bool vis[N + 5], able[N + 5];
void dfs(int id) {
    if (!able[id] || vis[id]) return ;
    vis[id] = 1;
    for (int nxt : g[id])
        dfs(nxt);
}
signed main() {
    freopen(inf, "r", stdin);
    freopen(ouf, "w", stdout);
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
        int cnt = n - 1;
        for (int i = l; i <= r; i ++) {
            memset(vis, 0, sizeof vis);
            able[i] = 1;
            dfs(i);
            if (vis[1]) cnt --;
            else able[i] = 0;
        }
        cout << cnt << endl;
    }
    return 0;
}