#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005, mod = 10007;
int C[N + 5][N + 5], lck[N + 5], s[N + 5], dp[N + 5][N + 5];
void init() {
    C[0][0] = 1;
    for (int i = 1; i <= N; i ++)
        for (int j = 1; j <= i; j ++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1], C[i][j] %= mod;
}
int getc(int n, int m) {
    return C[n + 1][m + 1];
}
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
	int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    init();
    cout << fp(a, n, mod) * fp(b, m, mod) % mod * getc(k, n) % mod;
    return 0;
}
