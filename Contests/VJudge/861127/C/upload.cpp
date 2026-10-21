#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300, mod = 1e9 + 7;
int a[N + 5], s[N + 5][N + 5], c[N + 5][N + 5], n;
void update(int id, int v, int pds) {
    int m = 1;
    for (int i = pds; i <= n; i ++) {
        a[i] += m * v * c[id][i - pds + 1], a[i] %= mod, a[i] += mod, a[i] %= mod;
        m *= -1;
    }
}
int query(int id, int pds) {
    int ret = 0;
    for (int i = pds, j = 0; i >= 1; i --, j ++) 
        ret += a[i] * s[id - 1][j], ret %= mod;
    return ret;
}
signed main() {
    int T = 0, _;
    cin >> n >> _;
    T += _;
    cin >> _;
    T += _;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 0; i <= n; i ++)
        s[i][0] = s[0][i] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            s[i][j] = s[i - 1][j] + s[i][j - 1], s[i][j] %= mod;
    c[0][1] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1], c[i][j] %= mod;
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int id, l, r, d;
            cin >> id >> l >> r >> d;
            if (id) {
                update(id - 1, d, l);
                update(id - 1, -d, r + 1);
            }
            else for (int i = l; i <= r; i ++)
                a[i] += d, a[i] %= mod, a[i] += mod, a[i] %= mod;
        }
        else {
            int id, l, r;
            cin >> id >> l >> r;
            int res = query(id + 1, r) - query(id + 1, l - 1);
            res %= mod, res += mod, res %= mod;
            cout << res << endl;
        }
    }
    return 0;
}