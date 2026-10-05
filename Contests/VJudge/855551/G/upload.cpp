#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30000, M = 200;
const int mod = 114514191981019, bas = 65537;
int lhs[N + 5][M + 5], rhs[N + 5][M + 5];
char s[M + 5];
signed main() {
    int n, m, _;
    cin >> n >> m >> _;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            cin >> s[j];
        for (int j = 1; j <= m; j ++)
            lhs[i][j] = lhs[i][j - 1] * bas + s[j], lhs[i][j] %= mod;
        for (int j = m; j >= 1; j --)
            rhs[i][j] = rhs[i][j + 1] * bas + s[j], rhs[i][j] %= mod;
    }
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        vector<int> tmp;
        for (int j = 1; j <= n; j ++)
            tmp.push_back((lhs[j][i - 1] * bas % mod + rhs[j][i + 1] * bas % mod) % mod);
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
