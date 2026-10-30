#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
int a[N + 5][N + 5];
signed main() {
    int n, m, T;
    scanf("%lld%lld%lld", &n, &m, &T);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%lld", &a[i][j]);
    int l, r, ans;
    int opt, x, y;
    int k;
    int mid, ap, bp, idx;
    int p;
    while (T --) {
        scanf("%lld%lld%lld", &opt, &x, &y);
        if (opt == 1) {
            scanf("%lld", &k);
            k = 2 * m - k + 1;
            l = 1, r = 1e9, ans = -1;
            while (l <= r) {
                mid = l + r >> 1;
                ap = lower_bound(a[x] + 1, a[x] + m + 1, mid) - a[x];
                bp = lower_bound(a[y] + 1, a[y] + m + 1, mid) - a[y];
                ap --, bp --;
                idx = ap + bp + 1;
                if (idx <= k)
                    l = mid + 1, ans = mid;
                else r = mid - 1;
            }
            printf("%lld\n", ans);
        }
        else {
            p = upper_bound(a[x] + 1, a[x] + m + 1, y) - a[x];
            p --;
            if (p == 0) continue;
            if (a[x][p] > y) continue;
            a[x][p] = y;
        }
    }
    return 0;
}
