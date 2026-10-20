#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef long long ll;
const int pN = 1e5, sK = 3e5, N = 4e5, C = 20;
vector<int> idx[pN + 5];
struct Point {
    int id, trans, dis;
};
bool operator > (Point x, Point y) {
    return x.dis > y.dis;
}
vector<Point> g[N + 5];
int dis[C + 5][N + 5], adis[C + 5];
void dijk() {
    priority_queue<Point, vector<Point>, greater<Point>> q;
    memset(dis, 0x3f, sizeof dis);
    for (int id : idx[1]) {
        q.push({id, 0, 0});
        dis[0][id] = 0;
    }
    while (!q.empty()) {
        auto [id, tr, ds] = q.top();
        q.pop();
        if (ds > dis[tr][id]) continue;
        for (Point nxt : g[id]) {
            int gn = nxt.id, nt = nxt.trans + tr, nd = ds + nxt.dis;
            if (nt > C)
                continue;
            if (dis[nt][gn] > dis[tr][id] + nxt.dis) {
                dis[nt][gn] = dis[tr][id] + nxt.dis;
                q.push({nxt.id, nt, nd});
            } 
        }
    }
}
signed main() {
    int n, m, T;
    cin >> n >> m >> T;
    map<int, int> mp;
    int curr = 0;
    for (int i = 1; i <= m; i ++) {
        int k;
        cin >> k;
        if (k == 1) {
            cin >> k;
            continue;
        }
        int u;
        cin >> u;
        k --;
        mp[++ curr] = u;
        idx[u].push_back(curr);
        while (k --) {
            int v;
            cin >> v;
            mp[++ curr] = v; 
            idx[v].push_back(curr);
            g[curr - 1].push_back({curr, 0, 1});
            u = v;
        }
    }
    for (int i = 1; i <= n; i ++) {
        curr ++;
        for (int j : idx[i])
            g[curr].push_back({j, 1, 0}),
            g[j].push_back({curr, 0, 0});
    }
    dijk();
    memset(adis, 0x3f, sizeof adis);
    for (int i : idx[n]) 
        for (int j = 0; j <= 20; j ++)
            adis[j] = min(adis[j], dis[j][i]);
    while (T --) {
        int x, y, c;
        cin >> x >> y >> c;
        ll ans = 9e18;
        for (int i = 0; i <= c; i ++)
            ans = min(ans, adis[i] * 1ll * x + i * y);
        cout << ans << endl;
    }
    return 0; 
}
