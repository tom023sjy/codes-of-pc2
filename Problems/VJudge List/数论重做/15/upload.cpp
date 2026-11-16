#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3, mod = 1e5 + 3;
int cc[N + 5][N + 5], fct[N + 5];
void init() {
    cc[0][0] = 1;
    for (int i = 1; i <= N + 1; i ++)
        for (int j = 1; j <= i; j ++)
            cc[i][j] = cc[i - 1][j - 1] + cc[i - 1][j], cc[i][j] %= mod;
    fct[0] = 1;
    for (int i = 1; i <= N; i ++)
        fct[i] = fct[i - 1] * i % mod;
}
int C(int n, int m) {
    return cc[n + 1][m + 1];
}
signed main() {
	int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    init();
    int ans = 0;
    for (int i = 0; i <= m; i ++)
        ans +=   C(a, i) * C(b + d - m + i, i) % mod * fct[i] % mod
               * C(c, m - i) % mod * C(d, m - i) % mod * fct[m - i]
               % mod, 
        ans %= mod;
    cout << ans;
    return 0;
}
