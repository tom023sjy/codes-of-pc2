#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "ship";
const bool JUDGE = 1;
const string FI = FIO + ".in", FO = FIO + ".out";
const int N = 10;
int p[N + 5], t[N + 5], x[N + 5];
int nn, xx;
bool vis[N + 5];
double ans = 99999999;
void dfs(int id) {
    if (id > nn) {
        double res = 0;
        int lst = 0, spd = 1;
        for (int i = 1; i <= nn; i ++)
            if (vis[i] == 1) {
                res += (p[i] - lst) * 1.0 / spd + t[i];
                spd *= x[i];
            }
        res += (xx - lst) * 1.0 / spd;
        ans = min(ans, res);
        return ;
    }
    vis[id] = 1;
    dfs(id);
    vis[id] = 0;
    dfs(id);
}
signed main() {
    #ifndef ONLINE_JUDGE
        if (JUDGE) {
            freopen(FI.data(), "r", stdin);
            freopen(FO.data(), "w", stdout);
        }
    #endif
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> p[i] >> t[i] >> x[i];
    while (T --) {
        cin >> xx;
        nn = n;
        ans = 9e18;
        for (int i = 1; i <= n; i ++)
            if (p[i] > xx) {
                nn = i - 1;
                break;
            }
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
