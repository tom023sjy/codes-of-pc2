#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300, mod = 1e9 + 7;
int a[N + 5][N + 5], s[N + 5][N + 5][N + 5];
signed main() {
    #define judge
    const string fio = "array";
    const string rf = fio + ".in";
    const string wf = fio + ".out";
    #ifndef ONLINE_JUDGE
    #ifdef judge
    freopen(rf.data(), "r", stdin);    
    freopen(wf.data(), "w", stdout);    
    #endif
    #endif
    int n, T = 0, _;
    cin >> n >> _;
    T += _;
    cin >> _;
    T += _;
    for (int i = 1; i <= n; i ++)
        cin >> a[0][i];
    for (int i = 1; i < n; i ++)
        for (int j = 1; j <= n; j ++)
            a[i][j] = a[i][j - 1] + a[i - 1][j], a[i][j] %= mod;
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int id, l, r, d;
            cin >> id >> l >> r >> d;
            for (int i = l; i <= r; i ++)
                a[id][i] += d, a[id][i] %= mod;
            for (int i = id - 1; i >= 0; i --)
                for (int j = 1; j <= n; j ++)
                    a[i][j] = a[i + 1][j] - a[i + 1][j - 1], a[i][j] %= mod;
            for (int i = id + 1; i < n; i ++)
                for (int j = 1; j <= n; j ++)
                    a[i][j] = a[i][j - 1] + a[i - 1][j], a[i][j] %= mod;
        }
        else {
            int id, l, r;
            cin >> id >> l >> r;
            int s = 0;
            for (int i = l; i <= r; i ++)
                s += a[id][i], s %= mod;
            s += mod, s %= mod;
            cout << s << endl;
        }
    }
    return 0;
}