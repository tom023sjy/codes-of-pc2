#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "train";
const string FI = FIO + ".in", FO = FIO + ".out";
const bool enableFIO = 1;
const int N = 3000;
int a[N + 5];
bool open[N + 5][N + 5];
void solve() {
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memset(open, 1, sizeof open);
    while (T --) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1) {
            for (int i = l; i <= r; i ++)
                for (int j = i; j <= r; j ++)
                    open[i][j] = 0;
        }
        else {
            int ans = 9e18;
            for (int i = l; i >= 1; i --)  
                for (int j = r; j <= n; j ++)
                    if (open[i][j]) 
                        ans = min(ans, a[j] - a[i]);
            if (ans == 9e18)
                ans = -1;
            cout << ans << endl;
        }
    }
}
signed main() {
    #ifndef ONLINE_JUDGE
        if (enableFIO) {
            freopen(FI.data(), "r", stdin);
            freopen(FO.data(), "w", stdout);
        }
    #endif
    int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}