#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    #define judge
    const string fio = "func";
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
    for (int l = 1; l <= n; l ++) {
        int x = 0, y = 0;
        vector<int> v;
        for (int r = l; r <= n; r ++) {
            x |= a[r];
            v.push_back(a[i]);
            for (int val : v) {
                
            }
        }
    }
    return 0;
}