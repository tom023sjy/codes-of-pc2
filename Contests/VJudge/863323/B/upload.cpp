#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "divide";
const string FI = FIO + ".in", FO = FIO + ".out";
const bool enableFIO = 1;
const int N = 12;
vector<int> g[N + 5], elm[N + 5], g2[N + 5];
bool nvis[N + 5];
int dep[N + 5];
void pre(int id, int ft) {
    dep[id] = dep[ft] + 1;
    for (int nxt : g[id])
        if (nxt != ft) 
            pre(nxt, id);
}
void add(int id, int ft, int curr) {
    elm[curr].push_back(id);
    nvis[id] = 1;
    for (int nxt : g[id])
        if (nxt != ft)
            add(nxt, id, curr);
}
void addother(int id, int ft, int curr) {
    if (nvis[id]) return ;
    elm[curr].push_back(id);
    for (int nxt : g[id])
        if (nxt != ft)
            add(nxt, id, curr);
}
bool vis[N + 5];
int n, m, ans;
void dfs(int id, int sel) {
    if (id > n) {
        if (sel < m) return ;
        vector<int> v;
        for (int i = 1; i <= n; i ++)
            if (vis[i])
                v.push_back(i);
        sort(v.begin(), v.end(), [](int a, int b){
            return dep[a] < dep[b];
        });
        memset(nvis, 0, sizeof nvis);
        for (int i = 0; i < m; i ++)
            add(v[i], 0, i + 1);
        addother(1, 0, m + 1);
        bitset<12> x, y;
        for (int i : elm[1])
            x[dep[i] - 1] = 1;
        for (int i : elm[2])
            y[dep[i] - 1] = 1;
        for (int i = 3; i <= m + 1; i ++) {
            bitset<12> tmp;
            for (int j : elm[i])
                tmp[dep[j] - 1] = 1;
            y &= tmp;
        }
        if (x == y)
            ans ++;
        return ;
    }
    vis[id] = 0;
    dfs(id + 1, sel);
    if (id != 1) {
        vis[id] = 1;
        dfs(id + 1, sel + 1);
    }
    vis[id] = 0;
}
signed main() {
    #ifndef ONLINE_JUDGE
        if (enableFIO) {
            freopen(FI.data(), "r", stdin);
            freopen(FO.data(), "w", stdout);
        }
    #endif
    cin >> n >> m;
    dep[1] = 1;
    for (int v = 2; v <= n; v ++) {
        int u;
        cin >> u;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pre(1, 0);
    dfs(1, 0);
    cout << ans;
    return 0;
}