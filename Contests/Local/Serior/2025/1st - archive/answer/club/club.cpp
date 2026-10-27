#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Node {
    int a, b, c;
} a[N + 5];
int b[N + 5];
void solve() {
    int n;
    cin >> n;
    int ans = 0, c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].a >> a[i].b >> a[i].c;
    for (int i = 1; i <= n; i ++) {
        if (a[i].a >= max(a[i].b, a[i].c))
            c1 ++, b[i] = 1, ans += a[i].a;
        else if (a[i].b >= max(a[i].a, a[i].c))
            c2 ++, b[i] = 2, ans += a[i].b;
        else
            c3 ++, b[i] = 3, ans += a[i].c;
    }
    vector<int> d;
    for (int i = 1; i <= n; i ++) {
        if (c1 > n / 2 && b[i] == 1)
            d.push_back(a[i].a - max(a[i].b, a[i].c));
        else if (c2 > n / 2 && b[i] == 2)
            d.push_back(a[i].b - max(a[i].a, a[i].c));
        else if (c3 > n / 2 && b[i] == 3)
            d.push_back(a[i].c - max(a[i].b, a[i].a));
    }
    sort(d.begin(), d.end());
    int id = 0;
    while (c1 > n / 2)
        ans -= d[id ++], c1 --;
    while (c2 > n / 2)
        ans -= d[id ++], c2 --;
    while (c3 > n / 2)
        ans -= d[id ++], c3 --;
    cout << ans << endl;
}

signed main() {
    int T;
    cin >> T;
    while (T --) 
        solve();
}