// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒
// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒
// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒
// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒
// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒
// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒
// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒
// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒
// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒
// 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒 🐒

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf "bargain.in"
#define ouf "bargain.out"
const int N = 1e5;
char s[N + 5];
int v[10], n, dp[N + 5][7], pp[9];
signed main() {
    freopen(inf, "r", stdin);
    freopen(ouf, "w", stdout);
    int c, T;
    scanf("%lld%lld", &c, &T);
    pp[0] = 1; 
    for (int i = 1; i <= 8; i ++) pp[i] = pp[i - 1] * 10;
    while (T --) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= 9; i ++)
            scanf("%lld", &v[i]);
        int sum = 0;
        for (int i = 1; i <= n; i ++)
            sum += v[s[i] - '0'];
        memset(dp, 0, sizeof dp);
        for (int i = n; i >= 1; i --) 
            for (int j = 1; j <= 6; j ++) 
                dp[i][j] = max(
                    dp[i + 1][j], 
                    dp[i + 1][j - 1] + v[s[i] - '0'] - pp[j - 1] * (s[i] - '0')
                );
        int maxn = 0;
        for (int i = 1; i <= 6; i ++)
            maxn = max(maxn, dp[1][i]);
        cout << sum - maxn << endl;
    }
    return 0;
}

