#include <bits/stdc++.h>
using namespace std;
const int N = 5000, mod = 998244353;
int a[N + 5], n, ans = 0;
void dfs(int id, int sum, int maxn, int cc) {
    if (id > n) {
        ans += cc >= 3 && sum > 2 * maxn;
        return ;
    }
    dfs(id + 1, sum, maxn, cc);
    dfs(id + 1, sum + a[id], max(maxn, a[id]), cc + 1);
}
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    if (n <= 28) {
        dfs(1, 0, 0, 0);
        cout << ans;
        return 0;
    }
    // 随便选 排除选2个的，选1个的和没有的
    int ans = fp(2, n, mod) - 7;
    cout << (ans % mod + mod) % mod;
    return 0;
}