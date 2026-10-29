#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "familiar";
const string FI = FIO + ".in", FO = FIO + ".out";
const bool JUDGE = 1;
const int N = 1000;
int a[N + 5][N + 5], b[N * 2 + 5];
signed main() {
    #ifndef ONLINE_JUDGE
        if (JUDGE) {
            freopen(FI.data(), "r", stdin);
            freopen(FO.data(), "w", stdout);
        }
    #endif
    int n, m, T;
    scanf("%lld%lld%lld", &n, &m, &T);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%lld", &a[i][j]);
    while (T --) {
        int opt, x, y;
        scanf("%lld%lld%lld", &opt, &x, &y);
        if (opt == 1) {
            int k;
            scanf("%lld", &k);
            k = 2 * m - k + 1;
            // x+y k
            int curr = 0;
            int p = 1, q = 1;
            while (p <= m && q <= m) {
                if (a[x][p] <= a[y][q])
                    b[++ curr] = a[x][p], p ++;
                else b[++ curr] = a[y][q], q ++;
            }
            while (p <= m) b[++ curr] = a[x][p], p ++;
            while (q <= m) b[++ curr] = a[y][q], q ++;
            printf("%lld\n", b[k]);
        }
        else {
            int p = upper_bound(a[x] + 1, a[x] + m + 1, y) - a[x];
            p --;
            if (p == 0) continue;
            if (a[x][p] > y) continue;
            a[x][p] = y;
        }
    }
    return 0;
}
