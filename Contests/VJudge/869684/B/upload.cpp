#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7, M = 2e6;
int mul[M + 5];
inline int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
inline int getc(int n, int m, int p) {
    if (n < m) return 0;
    if (m > n - m) m = n - m;
    int m1 = mul[n] * fp(mul[n - m], p - 2, p) % p, m2 = mul[m];
    return m1 * fp(m2, p - 2, p) % p;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    mul[0] = 1;
    for (int i = 1; i <= M; i ++)
        mul[i] = mul[i - 1] * i % mod;
    int T;
    cin >> T;
    while (T --) {
        int n, m;
        cin >> n >> m;
        int ans = getc(n + m, n, mod) + (n + m - 1) * getc(n + m - 2, n - 1, mod) % mod * 2 % mod;
        ans %= mod;
        cout << ans << endl;
    }
}