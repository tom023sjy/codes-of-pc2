#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int T, n, m, p;
    cin >> T >> n >> m >> p;
    int ans = 1;
    for (int i = n - m + 1, c = 1; c <= m; c ++, i --)
        ans = ans * i % p;
    cout << ans;
    return 0;
}
