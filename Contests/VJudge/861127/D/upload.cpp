#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int a[N + 5], n;
vector<int> b[N + 5];
int calc(vector<int> v) {
    int sum = 0;
    for (int val : v) {
        int p = upper_bound(a + 1, a + n + 1, val) - a;
        if (p > n) break;
        sum += n - p + 1;
    }
    return sum;
}
signed main() {
    #define judge
    const string fio = "file";
    const string rf = fio + ".in";
    const string wf = fio + ".out";
    #ifndef ONLINE_JUDGE
    #ifdef judge
    freopen(rf.data(), "r", stdin);    
    freopen(wf.data(), "w", stdout);    
    #endif
    #endif
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    vector<int> cdt;
    for (int i = 1; i <= m; i ++) {
        int l;
        cin >> l;
        while (l --) {
            int x;
            cin >> x;
            b[i].push_back(x);
        }
        sort(b[i].begin(), b[i].end());
        cdt.push_back(calc(b[i]));
    }
    sort(cdt.begin(), cdt.end());
    int ans = 0;
    for (int i = 0; i < cdt.size(); i ++)
        ans += cdt[i] * (m - i);
    cout << ans + n * (n + 1) / 2 * m;
    return 0;
}