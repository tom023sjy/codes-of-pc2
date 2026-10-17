#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 45, M = 90, mod = 998244353;
int a[N + 5][N + 5], b[N + 5][N + 5];
int dp[2][N + 5][N + 5][N + 5][M + 5], ans[N + 5][N + 5];
signed main() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> b[i][j];
    dp[1][1][0][0][p] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int k = p; k >= a[i][j]; k --) 
                for (int x = 0; x < n - i; x ++)
                    for (int y = 0; y <= m - j; y ++) 
                            dp[i & 1][j][x + 1][y][k - a[i][j]] += dp[i & 1][j][x][y][k], dp[i & 1][j][x + 1][y][k - a[i][j]] %= mod;
            for (int k = p; k >= b[i][j]; k --) 
                for (int x = 0; x <= n - i; x ++)
                    for (int y = 0; y < m - j; y ++) 
                        dp[i & 1][j][x][y + 1][k - b[i][j]] += dp[i & 1][j][x][y][k], dp[i & 1][j][x][y + 1][k - b[i][j]] %= mod;
            for (int k = 0; k <= p; k ++) 
                for (int x = 0; x <= n - i; x ++)
                    for (int y = 0; y <= m - j; y ++) {
                        if (x > 0 && i < n)
                            dp[i + 1 & 1][j][x - 1][y][k] += dp[i & 1][j][x][y][k], dp[i + 1 & 1][j][x - 1][y][k] %= mod;
                        if (y > 0 && j < m)
                            dp[i & 1][j + 1][x][y - 1][k] += dp[i & 1][j][x][y][k], dp[i & 1][j + 1][x][y - 1][k] %= mod;
                    }
        }
        for (int j = 1; j <= m; j ++)
            ans[i][j] = dp[i & 1][j][0][0][0];
        memset(dp[i & 1], 0, sizeof dp[i & 1]);
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}