#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30000, M = 200;
const int m1 = 1e9 + 7, m2 = 998244353, bas = 65537;
int h1[N + 5][M + 5], pw1[M + 5];
int h2[N + 5][M + 5], pw2[M + 5];
char s[M + 5];
signed main() {
    int n, m, _;
    cin >> n >> m >> _;
    pw1[0] = 1;
    for (int i = 1; i <= m; i ++)
        pw1[i] = pw1[i - 1] * bas % m1;
    pw2[0] = 1;
    for (int i = 1; i <= m; i ++)
        pw2[i] = pw2[i - 1] * bas % m2;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            cin >> s[j];
        for (int j = 1; j <= m; j ++)
            h1[i][j] = h1[i][j - 1] * bas + s[j], h1[i][j] %= m1;
        for (int j = 1; j <= m; j ++)
            h2[i][j] = h2[i][j - 1] * bas + s[j], h2[i][j] %= m2;
    }
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        vector<pair<int, int>> tmp;
        for (int j = 1; j <= n; j ++)
            tmp.push_back({
                ((h1[j][i - 1] * pw1[m - i] % m1 + h1[j][m]) % m1 - h1[j][i] * pw1[m - i] % m1 + m1) % m1,
                ((h2[j][i - 1] * pw2[m - i] % m2 + h2[j][m]) % m2 - h2[j][i] * pw2[m - i] % m2 + m2) % m2
            });
        sort(tmp.begin(), tmp.end());
        int cnt = 1;
        for (int j = 1; j < tmp.size(); j ++)
            if (tmp[j] == tmp[j - 1]) {
                ans += cnt;
                cnt ++;
            }
            else cnt = 1;
    }
    cout << ans;
    return 0;
}
