#include <bits/stdc++.h>
#include <cstdio>
#include <unistd.h>
using namespace std;
#define int long long
#define lint __int128
#define gcd __gcd
const int N = 1e5;
vector<int> g[N + 5];
struct Frac {
    lint p, q;
} a[N + 5];
Frac operator + (Frac x, Frac y) {
    x.p *= y.q;
    y.p *= x.q;
    int q = x.q * y.q;
    x.q = y.q = q;
    return {x.p + y.p, x.q};
}
Frac operator * (Frac x, Frac y) {
    return {x.p * y.p, x.q * y.q};
}
Frac operator ! (Frac x) {
    int g = gcd(x.p, x.q);
    return {x.p / g, x.q / g};
}
void dfs(int id) {
    Frac mul = {1, g[id].size()};
    for (int nxt : g[id]) {
        a[nxt] = a[nxt] + a[id] * mul;
        dfs(nxt);
    }
    if (!g[id].empty())
        a[id] = {0, 1};
}
void write(lint x) {
    if (x > 9) 
        write(x / 10);
    putchar(x % 10 + '0');
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int u = 1; u <= n; u ++) {
        int k;
        cin >> k;
        while (k --) {
            int v;
            cin >> v;
            g[u].emplace_back(v);
        }
    }
    for (int i = 1; i <= m; i ++)
        g[0].emplace_back(i);
    a[0] = {m, 1};
    for (int i = 1; i <= n; i ++)
        a[i] = {0, 1};
    dfs(0);
    for (int i = 1; i <= n; i ++) 
        a[i] = !a[i];
    for (int i = 1; i <= n; i ++)
        if (a[i].p) 
            write(a[i].p), putchar(' '), write(a[i].q), puts("");
    return 0;
}