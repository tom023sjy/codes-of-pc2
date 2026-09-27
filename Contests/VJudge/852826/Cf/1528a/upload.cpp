#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Node {
    int l, r;
} a[N + 5];
vector<int> g[N + 5];
int dp[N + 5][2];
void dfs(int id, int ft) {
    dp[id][0] = dp[id][1] = 0;
    for (int nxt : g[id]) 
        if (nxt != ft) {
            dfs(nxt, id);
            dp[id][0] += max(
                dp[nxt][0] + abs(a[id].l - a[nxt].l),
                dp[nxt][1] + abs(a[id].l - a[nxt].r)
            ); // l
            dp[id][1] += max(
                dp[nxt][0] + abs(a[id].r - a[nxt].l),
                dp[nxt][1] + abs(a[id].r - a[nxt].r)
            ); // r
        }
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        g[i].clear();
    for (int i = 1; i <= n; i ++)
        cin >> a[i].l >> a[i].r;
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}