#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "trip";
const string FI = FIO + ".in", FO = FIO + ".ans";
const bool enableFIO = 1;

const int N = 1e3;
int a[N + 5], s[N + 5];
signed main() {
    #ifndef ONLINE_JUDGE
        if (enableFIO) {
            freopen(FI.data(), "r", stdin);
            freopen(FO.data(), "w", stdout);
        }
    #endif
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        int ans = 0;
        for (int l = 1; l <= n; l ++)
            for (int r = l; r <= n; r ++) {
                s[l - 1] = 0;
                for (int i = l; i <= r; i ++)
                    s[i] = s[i - 1] + a[i];
                int cnt = 0;
                for (int i = l; i <= r; i ++)
                    cnt += s[i] == 0;
                ans = max(ans, cnt);
            }
        cout << ans << endl;
    }
    return 0;
}