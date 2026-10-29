#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "guess";
const string FI = FIO + ".in", FO = FIO + ".out";
const bool JUDGE = 1;
template <typename Tp>
Tp gcd(Tp a, Tp b) {
    if (b) return gcd(b, a % b);
    return a;
}
signed main() {
    #ifndef ONLINE_JUDGE
        if (JUDGE) {
            freopen(FI.data(), "r", stdin);
            freopen(FO.data(), "w", stdout);
        }
    #endif
    int T;
    cin >> T;
    while (T --) {
        int m;
        cin >> m;
        for (int n = 1; ; n ++) {
            int s = 0;
            for (int i = 1; i <= n; i ++)
                if (__gcd(i, n) == 1)
                    s += i;
            if (s == m) {
                cout << n << endl;
                break;
            }
        }
    }
    return 0;
}
