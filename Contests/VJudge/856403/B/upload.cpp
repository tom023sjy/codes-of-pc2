#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 10000, M = 10000, m1 = 1e9 + 7, m2 = 998244353, bs = 65537;
char c[N + 5][M + 5];
int nxt[N + 5];
pii hl[N + 5], hc[M + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) 
            hl[i] = {(hl[i].first * bs + c[i][j]) % m1, (hl[i].second * bs + c[i][j]) % m2};
    for (int j = 1; j <= m; j ++) 
        for (int i = 1; i <= n; i ++)
            hc[j] = {(hc[j].first * bs + c[i][j]) % m1, (hc[j].second * bs + c[i][j]) % m2};
    int ans = 1;
    int len = 0;
    for (int i = 2; i <= n; i ++) {
        while (hl[i] != hl[len + 1] && len) len = nxt[len];
        if (hl[i] == hl[len + 1]) len ++;
        nxt[i] = len;
    }
    ans *= n - nxt[n];
    len = 0;
    memset(nxt, 0, sizeof nxt);
    for (int i = 2; i <= m; i ++) {
        while (hc[i] != hc[len + 1] && len) len = nxt[len];
        if (hc[i] == hc[len + 1]) len ++;
        nxt[i] = len;
    }
    ans *= m - nxt[m];
    cout << ans;
    return 0;
}
