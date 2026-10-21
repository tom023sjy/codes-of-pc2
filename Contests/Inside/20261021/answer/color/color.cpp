#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
signed main() {
    #define judge
    const string fio = "color";
    const string rf = fio + ".in";
    const string wf = fio + ".out";
    #ifndef ONLINE_JUDGE
    #ifdef judge
    freopen(rf.data(), "r", stdin);    
    freopen(wf.data(), "w", stdout);    
    #endif
    #endif

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    
    int ans = 0;
    // Empty arr 1/2
    ans = max(ans, a[n] - a[1]);

    // arr 1 from 1 to n
    int d = -9e18, minn = a[2];
    for (int i = 3; i < n; i ++) {
        d = max(d, a[i] - minn);
        minn = min(minn, a[i]);
    }
    if (d == -9e18) d = 0;
    ans = max(ans, a[n] - a[1] + d);

    // arr 1 from 1 to i
    // i=1
    ans = max(ans, a[n] - a[2]);
    // i=n
    ans = max(ans, a[n - 1] - a[1]);
    // i=2~n-1
    priority_queue<int> q;
    for (int i = 2; i < n; i ++) {
        int res = 0;
        res += a[i] - a[1];
        if (q.empty()) 
            res += a[n] - a[i + 1];
        else {
            int opt1 = a[n] - a[i + 1], opt2 = q.top();
            res += max(opt1, opt2);
        }
        q.push(a[n] - a[i]);
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}