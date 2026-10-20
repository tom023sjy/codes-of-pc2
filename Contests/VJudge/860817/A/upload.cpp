#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2e5;
vector<int> g[N + 5];
int maxv[N + 5], s[N + 5], a[N + 5];
void dijk(int n, int p, int x) {
    priority_queue<pii> q;
    memset(maxv, 0xff, sizeof maxv);
    for (int i = 1; i <= p; i ++) {
        maxv[s[i]] = a[s[i]];
        q.push({a[s[i]], s[i]});
    }
    while (!q.empty()) {
        auto [w, t] = q.top();
        q.pop();
        if (w < maxv[t]) continue;
        for (int nxt : g[t]) {
            if (nxt == x) continue;
            if (a[nxt] <= w && maxv[nxt] < w) {
                maxv[nxt] = w;
                q.push({w, nxt});
            }
        }
    }
}
signed main() {
    int n, m, p, x;
    cin >> n >> m >> p >> x;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= p; i ++)
        cin >> s[i];
    dijk(n, p, x);
    int sum = 0;
    for (int nxt : g[x])
        if (maxv[nxt] != -1)
            sum ++;
    cout << sum;
    return 0;
}