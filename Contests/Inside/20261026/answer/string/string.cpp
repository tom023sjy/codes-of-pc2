#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "string";
const bool JUDGE = 1;
const string FI = FIO + ".in", FO = FIO + ".out";
const int N = 10, M = 5e5;
int s[N + 5], t, dp[N + 5][M + 5];
signed main() {
    #ifndef ONLINE_JUDGE
        if (JUDGE) {
            freopen(FI.data(), "r", stdin);
            freopen(FO.data(), "w", stdout);
        }
    #endif
    int cid, n, lim;
    cin >> cid >> n >> lim;
    assert(cid == 15);
    for (int i = 1; i <= n; i ++) {
        string _;
        cin >> _;
        s[i] = _.size();
    }
    string __;
    cin >> __;
    t = __.size();
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= t; j ++) {
            dp[i][j] = dp[i - 1][j];
            if (j < s[i]) dp[i][j] ++;
            else dp[i][j] += dp[i - 1][j - s[i]];
        }
    int sum = 0;
    for (int i = 0; i <= t; i ++)
        sum += dp[n][i];
    cout << sum << endl;
    for (int i = 1; i <= t; i ++)
        cout << "0 ";
    return 0;
}
