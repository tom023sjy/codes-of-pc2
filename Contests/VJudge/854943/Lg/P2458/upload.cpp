#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1500;
int a[N + 5], dp[N + 5][3], f[N + 5];
vector<int> g[N + 5];
template<typename Tp>
Tp min(Tp a, Tp b, Tp c) {
    return min(a, min(b, c));
}
void dfs(int id, int ft) {
    dp[id][2] = a[id];
    for (int nxt : g[id]) {
        if (nxt == ft)
            continue;
        dfs(nxt, id);
        dp[id][0] += min(dp[nxt][1], dp[nxt][2]);
        dp[id][2] += min(dp[nxt][0], dp[nxt][1], dp[nxt][2]);
    }
    dp[id][1] = 9e18;
    for (int nxt : g[id])
        if (nxt != ft)
            dp[id][1] = min(dp[id][1], dp[id][0] - min(dp[nxt][1], dp[nxt][2]) + dp[nxt][2]);
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int u, x;
        cin >> u;
        cin >> a[u] >> x;
        while (x --) {
            int v;
            cin >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            f[v] = u;
        }
    }
    dfs(1, 0);
    cout << min(dp[1][1], dp[1][2]);
    return 0;
}
