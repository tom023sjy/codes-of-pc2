#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], b[N + 5];
int n, m, req;
bool check(int k) {
    int p = 1, q = 1, cnt = 0;
    while (p <= n && q <= m)
        if (abs(a[p] - b[q]) <= k)
            p ++, q ++, cnt ++;
        else if (req == n)
            q ++;
        else p ++;
    return cnt >= req;
}
signed main() {
    cin >> n >> m;
    req = min(n, m);
    memset(a, 0x3f, sizeof a);
    memset(b, 0x3f, sizeof b);
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
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