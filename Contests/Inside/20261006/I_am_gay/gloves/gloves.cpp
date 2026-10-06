// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define inf "gloves.in"
// #define ouf "gloves.out"
// const int N = 1e5;
// int a[N + 5], b[N + 5];
// signed main() {
//     #ifndef ONLINE_JUDGE
//         freopen(inf, "r", stdin);
//         freopen(ouf, "w", stdout);
//     #endif
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i ++)
//         cin >> a[i];
//     for (int i = 1; i <= m; i ++)
//         cin >> b[i];
//     sort(a + 1, a + n + 1);
//     sort(b + 1, b + m + 1);
//     int ans = 0;
//     for (int i = 1; i <= n; i ++)
//         ans = max(ans, abs(a[i] - b[i]));
//     cout << ans;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf "gloves.in"
#define ouf "gloves.out"
const int N = 1e5;
int a[N + 5], b[N + 5], tmp[N + 5];
bool vis[N + 5];
int n, m;
bool check(int nw) {
    memset(vis, 0, sizeof vis);
    int p = 1, maxn = 0;
    for (int i = 1; i <= n; i ++) {
        while (p <= m && b[p] < a[i]) p ++;
        // choose between `p` and `p-1`
        if (p > m) p = m;
        if (p < 2) p = 2;
        int minn = abs(a[i] - b[p]);
        vis[p] = 1;
        if (!vis[p - 1] && minn > abs(a[i] - b[p - 1])) 
            vis[p] = 0, minn = abs(a[i] - b[p - 1]), vis[p - 1] = 1;
        maxn = max(maxn, minn);
    }
    return maxn <= nw;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen(inf, "r", stdin);
        freopen(ouf, "w", stdout);
    #endif
    cin >> n >> m;
    memset(a, 0x3f, sizeof a);
    memset(b, 0x3f, sizeof b);
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    if (n == m) {
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        int ans = 0;
        for (int i = 1; i <= n; i ++)
            ans = max(ans, abs(a[i] - b[i]));
        cout << ans;
        return 0;
    }
    if (n > m) {
        swap(n, m);
        memcpy(tmp, b, sizeof b);
        memcpy(b, a, sizeof a);
        memcpy(a, tmp, sizeof tmp);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int l = 0, r = 9e18, res = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) 
            res = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << res;
    return 0;
}