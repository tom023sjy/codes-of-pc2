#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5, bs = 131, mod = 1e9 + 7;
char c[N + 5];
int lhs[N + 5], rhs[N + 5], pw[N + 5];
int glhs(int l, int r) {
    return ((lhs[r] - lhs[l - 1] * pw[r - l + 1]) % mod + mod) % mod;
}
int grhs(int l, int r) {
    return ((rhs[l] - rhs[r + 1] * pw[r - l + 1]) % mod + mod) % mod;
}
signed main() {
    int n;
    cin >> n;
    if (n == 1) return puts("0"), 0;
    int ans = n - 1;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    pw[0] = 1;
    for (int i = 1; i <= n; i ++)
        lhs[i] = lhs[i - 1] * bs + c[i], lhs[i] %= mod,
        pw[i] = pw[i - 1] * bs % mod;
    for (int i = n; i >= 1; i --)
        rhs[i] = rhs[i + 1] * bs + c[i], rhs[i] %= mod;
    for (int i = 1; i <= n; i ++) {
        if (i - 1 >= n - i) {
            int len = n - i;
            if (glhs(i - len, i - 1) == grhs(i + 1, i + len))
                ans = min(ans, i - len - 1);
        }
        if (i >= n - i) {
            int len = n - i;
            if (glhs(i - len + 1, i) == grhs(i + 1, i + len))
                ans = min(ans, i - len);
        }
    }
    cout << ans;
    return 0;
}
