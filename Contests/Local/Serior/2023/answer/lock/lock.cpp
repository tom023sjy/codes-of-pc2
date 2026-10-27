#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
bool vis[N], res[N];
inline int hs(vector<int> a) {
    return a[1] * 10000 + a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5];
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("lock.in", "r", stdin);
        freopen("lock.out", "w", stdout);
    #endif
	int T;
    cin >> T;
    memset(res, 1, sizeof res);
    while (T --) {
        vector<int> a(7);
        cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= 5; i ++)
            for (int j = 1; j <= 9; j ++) {
                a[i] -= j; a[i] = (a[i] + 10) % 10;
                vis[hs(a)] = 1;
                a[i] += j; a[i] %= 10;
            }
        for (int i = 1; i <= 4; i ++)
            for (int j = 1; j <= 9; j ++) {
                a[i] -= j; a[i] = (a[i] + 10) % 10;
                a[i + 1] -= j; a[i + 1] = (a[i + 1] + 10) % 10;
                vis[hs(a)] = 1;
                a[i] += j; a[i] %= 10;
                a[i + 1] += j; a[i + 1] %= 10;
            }
        for (int i = 0; i < N; i ++)
            res[i] &= vis[i];
    }
    int sum = 0;
    for (int i = 0; i < N; i ++)
        sum += res[i];
    cout << sum;
    return 0;
}
