#include <bits/stdc++.h>
using namespace std;
const int N = 5e5, M = 1 << 20;
int a[N + 5], s[N + 5], idx[M + 5];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i - 1] ^ a[i];
    int last = 0, ans = 0;
    memset(idx, 0xff, sizeof idx);
    idx[0] = 0;
    for (int r = 1; r <= n; r ++) {
        int xres = s[r] ^ k;
        if (idx[xres] >= last) {
            ans ++;
            last = r;
        }
        idx[s[r]] = r;
    }
    cout << ans;
    return 0;
}