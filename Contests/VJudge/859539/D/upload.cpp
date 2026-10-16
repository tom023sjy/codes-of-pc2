#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 5e5;
int a[N + 5], la[N + 5], ra[N + 5];
signed main() {
    int n, m, val;
    cin >> n >> m >> val;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], la[i] = ra[i] = a[i];
    for (int i = 1; i <= N; i ++)
        la[i] = max(la[i], l[i - 1]);
    for (int i = 1; i >= 1; i --)
        ra[i] = max(ra[i], r[i + 1]);
    vector<pii> b, c;
    c.push_back({9e18, 9e18});
    for (int i = 1; i <= m; i ++) {
        int l, r;
        cin >> l >> r;
        int len = r - l;
        for (int s = 1; s <= N; s += len + 1) {
            int t = s + len;
            if (t > N) t = N;
            int rp = r[s], lp = l[t];
            if (rp > t || lp < s) continue;
            int cl = l - rp, cr = r - lp;
            if (cr < 1) continue;
            cl = max(cl, 1ll);
            if (cl > val) continue;
            cr = min(cr, val);
            c.push_back({cl, cr});
        }
        int tl = c.back().first, tr = c.back().second;
        for (int j = c.size() - 1; j >= 0; j --) {
            if (c[j].second <= tr) continue;
            if (c[j].first <= tr) 
                tr = c[j].first;
            else {
                b.push_back({tl, tr});
                tl = c[j].first, tr = c[j].second;
            }
        }
    }
    sort(b.begin(), b.end());
    int lst = 0, ans = val;
    for (auto ths : b) {
        if (ths.second <= lst) continue;
        if (ths.first <= lst) ans -= ths.second - lst;
        else ans -= ths.second - ths.first + 1;
        lst = ths.second;
    }
    cout << ans;
    return 0;
}