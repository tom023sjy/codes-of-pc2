#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "trip";
const string FI = FIO + ".in", FO = FIO + ".out";
const bool enableFIO = 1;

const int N = 1e6;
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
        for (int i = 1; i <= n; i ++)
            s[i] = s[i - 1] + a[i];
        map<int, int> mp;
        mp[0] ++;
        for (int i = 1; i <= n; i ++) 
            mp[s[i]] ++;
        int ans = 0;
        for (auto kv : mp)
            ans = max(ans, kv.second);
        cout << ans - 1 << endl;
    }
    return 0;
}