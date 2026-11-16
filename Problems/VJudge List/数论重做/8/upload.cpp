#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 302;
int C[N + 5][N + 5], lck[N + 5], s[N + 5], dp[N + 5][N + 5];
void init(int mod) {
    C[0][0] = 1;
    for (int i = 1; i <= N; i ++)
        for (int j = 1; j <= i; j ++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1], C[i][j] %= mod;
}
int getc(int n, int m) {
    return C[n + 1][m + 1];
}
void solve() {
    memset(lck, 0, sizeof lck);
    memset(s, 0, sizeof s);
    int n, m, mod;
    cin >> n >> m >> mod;
    init(mod);
    for (int i = 1; i <= m; i ++) {
        int _, x;
        cin >> _ >> x;
        lck[x] ++;
    }
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + lck[i];
    for (int i = 1; i <= n; i ++)
        if (m - s[i] > n - i) {
            puts("NO");
            return ;
        }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n - m + s[i]; j ++)
            for (int k = lck[i]; k <= j - i + 1; k ++)
                dp[i][j] += dp[i - 1][j - k] * getc(n - m + s[i] - j + k - lck[i], k - lck[i]) % mod, dp[i][j] %= mod;
    cout << "YES " << dp[n][n] << endl;
}
signed main() {
	int T;
    cin >> T;
    while (T --) solve();
    return 0;
}