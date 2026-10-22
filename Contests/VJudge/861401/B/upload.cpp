#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], b[N + 5];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++)
        a[i] += b[i - 1] - a[i - 1];
    if (a[n] == b[n])
        puts("Yes");
    else puts("No");
}
signed main() {
    int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}