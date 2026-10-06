#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3000, mod = 10000000000002137, M = 1e7;
char s[N + 5], t[N + 5];
int a[M + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    for (int i = 1; i <= n; i ++)
        cin >> t[i];
    int curr = 0;
    for (int i = 1; i <= n; i ++) {
        int hs = 0, p = 1;
        for (int j = i; j <= n; j ++) {
            while (p <= n && s[p] != t[j]) p ++;
            if (p > n) break;
            p ++;
            hs = hs * 65537 + t[j], hs %= mod;
            a[++ curr] = hs;
        }
    }
    sort(a + 1, a + curr + 1);
    int ls = unique(a + 1, a + curr + 1) - a - 1;
    cout << ls;
    return 0;
}
