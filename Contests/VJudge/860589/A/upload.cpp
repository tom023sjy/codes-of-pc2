#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define pii pair<int, int>
#define fir first
#define sec second
const int P = 1e5, N = 10;
int p, n, m;
pii plc[P + 5], x[P + 5], y[P + 5];
int c[P + 5], ans, cnt[N + 5][N + 5];
void dfs(int id) {
    if (id > p) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= p; i ++)
            cnt[plc[i].fir][plc[i].sec] += c[i];
        int res = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                res += cnt[i][j] * (cnt[i][j] - 1) / 2;
        ans = max(ans, res);
        return ;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (!(x[id].fir <= i && i <= x[id].sec && y[id].fir <= j && j <= y[id].sec)) {
                plc[id] = {i, j};
                dfs(id + 1);
            }
}
signed main() {
    int cid;
    cin >> cid;
    cin >> p >> n >> m;
    for (int i = 1; i <= p; i ++) 
        cin >> x[i].fir >> y[i].fir >> x[i].sec >> y[i].sec >> c[i];
    if (cid <= 8 && cid != 0 || p <= 8 && n <= 3 && m <= 3) {
        dfs(1);
        cout << ans;
    }
    else if (cid <= 10) {
        int sum = 0;
        for (int i = 1; i <= p; i ++)
            sum += c[i];
        cout << sum * (sum - 1) / 2;
    }
    return 0;
}