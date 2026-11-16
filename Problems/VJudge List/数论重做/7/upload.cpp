#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int a, b;
    cin >> a >> b;
    if (a * a == 4 * b)
        return puts("inf"), 0;
    int x = 1, t = sqrt(b), ans = 0;
    if (t * t == b) ans ++;
    while (1) {
        int n = x * 2 - a, m = b - x * x;
        if (((n > 0 && m > 0) || (n < 0 && m < 0)) && m % n == 0)
            ans ++;
        if (n > 0 && m < 0) break;
        x ++;
    }
    cout << ans;
    return 0;
}
