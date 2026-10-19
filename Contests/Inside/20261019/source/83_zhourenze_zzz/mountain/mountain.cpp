#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e3 + 7;
const int mod = 1e9 + 7;
int c, n;
int t[MAXN], ans[MAXN];
bool jud[MAXN];
string s;
void dfs(int x, int y) {
    if (y >= n) {
        ans[x]++;
        return;
    }
    if (t[x] == 1) {
        for (int i = x + 1; i <= n; i++) {
            if (jud[i]) continue;
            jud[i] = 1;
            dfs(i, y + 1);
            jud[i] = 0;
        }
    } else {
        for (int i = 1; i < x; i++) {
            if (jud[i]) continue;
            jud[i] = 1;
            dfs(i, y + 1);
            jud[i] = 0;
        }
    }
    return;
}
signed main() {
    freopen("mountain.in", "r", stdin);
    freopen("mountain.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') t[i + 1] = 1;
    }
    if (c == 10) {
        int pw = 1;
        cout << pw << " ";
        for (int i = 2; i < n; i++) {
            pw *= 2;
            cout << pw << " ";
        }
        cout << 1 << "\n";
        return 0;
    } else if (c == 11) {
        cout << 1 << " ";
        int pw = 1;
        for (int i = n; i >= 2; i--) {
            ans[i] = pw;
            pw *= 2;
        }
        for (int i = 2; i <= n; i++) cout << ans[i] << " ";
        return 0;
    }
    if (n >= 500) {
        for (int i = 1; i <= n; i++) cout << 0 << " ";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        memset(jud, 0, sizeof(jud));
        jud[i] = 1;
        dfs(i, 1);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
