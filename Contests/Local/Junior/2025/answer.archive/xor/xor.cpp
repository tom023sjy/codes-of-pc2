#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int a[N + 5], n, k, ans;
void dfs(int id, int cc) {
    if (id > n) {
        ans = max(ans, cc);
        return;
    }
    for (int s = id; s <= n; s ++) {
        int xres = 0;
        for (int t = s; t <= n; t ++) {
            xres ^= a[t];
            if (xres == k)
                dfs(t + 1, cc + 1);
        }
    }
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dfs(1, 0);
    cout << ans;
    return 0;
}