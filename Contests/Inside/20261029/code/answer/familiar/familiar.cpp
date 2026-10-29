#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "familiar";
const string FI = FIO + ".in", FO = FIO + ".out";
const bool JUDGE = 1;

inline int lower(int a[], int n, int v) {
    int l = 1, r = n, ans = n + 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid] >= v)
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

inline int upper(int a[], int n, int v) {
    int l = 1, r = n, ans = n + 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid] > v)
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

const int N = 1000;
int a[N + 5][N + 5];
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
            // x+y k
            l = 1, r = 1e9, ans = -1;
            while (l <= r) {
                mid = l + r >> 1;
                ap = lower_bound(a[x] + 1, a[x] + m + 1, mid) - a[x];
                // ap = lower(a[x], m, mid);
                bp = lower_bound(a[y] + 1, a[y] + m + 1, mid) - a[y];
                // bp = lower(a[y], m, mid);
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
            // p = upper(a[x], m, y);
            p --;
            if (p == 0) continue;
            if (a[x][p] > y) continue;
            a[x][p] = y;
        }
    }
    return 0;
}
