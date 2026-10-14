#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], b[N + 5];
inline int solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    int p = 1;
    for (int i = 1; i <= m; i ++) {
        while (b[i] != a[p] && p <= n) p ++;
        if (p > n) return puts("No");
        p ++;
    }
    return puts("Yes");
}
signed main() {
    int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}