#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "express";
const string FI = FIO + ".in", FO = FIO + ".out";
const bool JUDGE = 1;
const int N = 1000;
int dp[N + 5][2][N + 5], a[N + 5];
signed main() {
    #ifndef ONLINE_JUDGE
        if (JUDGE) {
            freopen(FI.data(), "r", stdin);
            freopen(FO.data(), "w", stdout);
        }
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    /*
    dp[i][j][k]:
    When j = 0, This point = i-th pack, Y to a[i], Z is on a[k]
    When j = 1, This point = i-th pack, Z to a[i], Y is on a[k]
    */
    memset(dp, 0x3f, sizeof dp);
    dp[1][0][0] = dp[1][1][0] = a[1];
    for (int i = 1; i < n; i ++)
        for (int j = 0; j <= n; j ++) {
            // s=0 yn=i zn=j
            dp[i + 1][0][j] = min(dp[i + 1][0][j], dp[i][0][j] + abs(a[i + 1] - a[i]));
            dp[i + 1][1][i] = min(dp[i + 1][1][i], dp[i][0][j] + abs(a[j] - a[i + 1]));
            // s=1 yn=j zn=i
            dp[i + 1][1][j] = min(dp[i + 1][1][j], dp[i][1][j] + abs(a[i + 1] - a[i]));
            dp[i + 1][0][i] = min(dp[i + 1][0][i], dp[i][1][j] + abs(a[j] - a[i + 1]));
        }
    int ans = 9e18;
    for (int i = 0; i <= n; i ++)
        ans = min(ans, min(dp[n][0][i], dp[n][1][i]));
    cout << ans;
    return 0;
}
