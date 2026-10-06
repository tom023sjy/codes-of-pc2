#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20000, bs = 1e7 + 9, mod = 998244353;
int a[N + 5], hs[N + 5], pw[N + 5];
int n, m;
bool check(int mid) {
    map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        if (i + mid - 1 <= n) {
            int h = (hs[i + mid - 1] - hs[i - 1] * pw[mid] % mod + mod) % mod;
            mp[h] ++;
            ans = max(ans, mp[h]);
        }
        else break;
    return ans >= m;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    pw[0] = 1;
    for (int i = 1; i <= n; i ++)
        hs[i] = hs[i - 1] * bs + a[i], hs[i] %= mod,
        pw[i] = pw[i - 1] * bs % mod;
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
