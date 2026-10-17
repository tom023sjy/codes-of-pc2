#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int ___, a[N + 5], s[N + 5];
signed main() {
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> ___;
        for (int i = 1; i <= n; i ++)
            cin >> a[i], s[i] = s[i - 1] + abs(a[i]);
        int l = 1, r = n;
        while (l <= n && a[l] > 0) l ++;
        while (r >= 1 && a[r] < 0) r --;
        int a1 = 0, a2 = 0;
        for (int i = 1; i < l; i ++)
            a1 = max(a1, -a[i] + s[l - 1] - s[i]);
        for (int i = r + 1; i <= n; i ++)
            a2 = max(a2, a[i] + s[i - 1] - s[r]);
        cout << a1 + a2 + s[r] - s[l - 1] << endl;
    }
    return 0;
}