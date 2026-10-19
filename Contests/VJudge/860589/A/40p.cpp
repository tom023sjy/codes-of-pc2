#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second
// #define debug
const string FILEIO = "chess";
const string FILEI = FILEIO + ".in";
const string FILEO = FILEIO + ".out";

const int P = 3, N = 8;
int p, n, m;
pii plc[N + 5], x[N + 5], y[N + 5];
int c[N + 5], ans, cnt[P + 5][P + 5];
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
        #ifdef debug
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++)
                cerr << cnt[i][j] << " ";
            cerr << endl;
        }
        cerr << "------------------------\n"; 
        #endif
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
    #ifndef ONLINE_JUDGE
        freopen(FILEI.data(), "r", stdin);
        freopen(FILEO.data(), "w", stdout);
    #endif
    int cid;
    cin >> cid;
    assert(cid <= 8); // 太大的不要，避免炸死judgeeeeeer
    cin >> p >> n >> m;
    // 显然
    // 把一坨棋子放在一起最优
    for (int i = 1; i <= p; i ++) 
        cin >> x[i].fir >> y[i].fir >> x[i].sec >> y[i].sec >> c[i];
    // 稍加使用骗分导论
    dfs(1);
    cout << ans;
    return 0;
}