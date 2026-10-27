#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 12;
int c[N + 5], p[N + 5];
bool b[N + 5];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++)
        cin >> c[i], p[i] = i;
    int ans = 0;
    do {
        int cnt = 0, lost = 0;
        for (int i = 1; i <= n; i ++) {
            if (lost >= c[p[i]] || b[i] == 0) lost ++;
            else cnt ++;
        }
        if (cnt >= m) ans ++;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans;
}